
#include "buzzer.h"
#define DISABLE 0
#define ENABLE  1
#define ON      1
#define OFF     0
/*  -----    ---         -----    ---
    |   |   |  |         |   |   |  |
    |   |t2 |  | t2+t3   |   |t2 |  |
---- t1 ----   ---------
*/
typedef struct 
{
    uint32_t ton;
    uint32_t toff;
    uint32_t t3;
    uint32_t cont;
    uint32_t cyc;
} bzr_SPL;

bzr_SPL Msc_Spl;

static uint8 msc_en = DISABLE;

static uint32_t  t_          = 0;
static uint8_t   s           = 0;
static uint32_t  c           = 0;
static uint32_t  cont_inside = 0;


void cb_bzr_Main(void)
{
    if(msc_en == ENABLE)
    {
        switch(s)
        {
            case 0:
                    if(Msc_Spl.ton)
                    {
                        BUZZER_SET(ON);
                        t_ = 0;
                        s  = 1;
                    }
                    break;
            case 1:
                    if(t_ >= Msc_Spl.ton)
                    {
                        BUZZER_SET(OFF);
                        t_ = 0;
                        s  = 2;
                    }
                    break;
            case 2:
                    if(t_ >= Msc_Spl.toff)
                    {
                        if(Msc_Spl.cont > (++cont_inside))
                        {
                            t_ = 0;
                            s  = 0;
                        }
                        else//
                        {
                            if((Msc_Spl.cont>1)&&(Msc_Spl.t3 > 0))//进入t3
                            {
                                t_ = 0;
                                s  = 3;
                            }
                            else//进入下一个周期
                            {
                                if((Msc_Spl.cyc) && ((++c) >= Msc_Spl.cyc))
                                {
                                    s = 0;
                                    msc_en = DISABLE;
                                }
                                else
                                {
                                    BUZZER_SET(ON);
                                    s  = 1;
                                    t_ = 0;
                                }
                            }		
                        }
                    }
                    break;
            case 3:
                    if(t_ >= Msc_Spl.t3)
                    {
                        if((Msc_Spl.cyc) && ((++c) >= Msc_Spl.cyc))
                        {
                            s = 0;
                            msc_en = DISABLE;
                        }
                        else
                        {
                            BUZZER_SET(ON);
                            s  = 1;
                            t_ = 0;
                            cont_inside = 0;
                        }
                    }
                    break;

            default:
                    break;
        }
        t_ += BZR_TIME_STEP;
    }
}

void bzr_Init(void)
{
    Msc_Spl.ton  = 0;
    Msc_Spl.toff = 0;
    Msc_Spl.t3   = 0;
    Msc_Spl.cont = 0;
    Msc_Spl.cyc  = 0;
    t_           = 0;
    s            = 0;
    c            = 0;
    cont_inside  = 0;
    msc_en       = DISABLE;
    BUZZER_SET(OFF);
}

void bzr_SetBell(uint32_t ton, uint32_t toff,uint32_t cont,uint32_t t3, uint32_t cyc)
{	
    if((Msc_Spl.ton == ton)&&
      (Msc_Spl.toff == toff)&&
      (Msc_Spl.cyc == cyc)&&
      (Msc_Spl.cont == cont)&&
      (Msc_Spl.t3 == t3)&&( msc_en == ENABLE))
    {
        
    }
    else//参数发生改变
    {
        msc_en = DISABLE;
        
        if( (!toff) && (ton) && (!cyc))
        {
            bzr_Init();
            BUZZER_SET(ON);  //蜂鸣器保持鸣叫
        }
        else if(!ton)
        {
            bzr_Init();
            BUZZER_SET(OFF); //蜂鸣器保持关闭
        }
        else
        {
            Msc_Spl.ton  = ton;
            Msc_Spl.toff = toff;
            Msc_Spl.cyc  = cyc;
            Msc_Spl.cont = cont;
            Msc_Spl.t3   = t3;
            
            t_ = 0;
            s  = 0;
            c  = 0;
            cont_inside = 0;        
            msc_en = ENABLE;
        }       
    }	
}

uint8 bzr_ifBusy(void)
{
    if(msc_en != DISABLE)
    {
        return 1;
    }          
    else
    {
        return 0;
    }            
}