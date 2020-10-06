#include <ioCC2530.h>  


#define LED1 P1_0     // P1_0����ΪP1.0
#define LED2 P1_1     // P1_1����ΪP1.1

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ��������Delay
* ������UINT
* ���أ�void
* ��������ʱ����
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//1ms��ȷ��ʱ
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

 