#include <ioCC2530.h>  


#define LED1 P1_0     // P1_0定义为P1.0
#define LED2 P1_1     // P1_1定义为P1.1

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：Delay
* 参数：UINT
* 返回：void
* 描述：延时函数
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//1ms精确定时
void Delay(unsigned int UINT)
{
    unsigned int uiLoop = 0;
    unsigned int uiLoopj;
    for(uiLoop = 0; uiLoop < UINT; uiLoop++)
  {
    for(uiLoopj = 0; uiLoopj < 475; uiLoopj++)
    {   
        asm("NOP");   
        asm("NOP");
        asm("NOP");
    }
  }
}

void main(void)
{
    P1SEL &= ~(0x03);
    P1DIR |= 0x03 ;   
    while(1)
    {
      LED1 = 1;    
      LED2 = 0;
      Delay(1000);
      LED1 = 0;    
      LED2 = 1;
      Delay(1000);
    }    
}

 