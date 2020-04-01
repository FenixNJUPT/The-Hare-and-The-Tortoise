#include "config.h"

extern unsigned char tCount;	//��Դ��snake.c�ļ�
extern unsigned char keyValue;	//��Դ��snake.c�ļ�
unsigned char wei=0;
unsigned int counter=0,sec=0;
extern unsigned char DisplayData[8];


sbit LS1=P2^2;
sbit LS2=P2^3;
sbit LS3=P2^4;
sbit LS4=P2^5;

//******��ʱ��0��ʼ��*************//
void initTimer0()
{
	TMOD |= 0x01;
	TL0 = TIMER;
	TH0 = TIMER>>8;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
}

//******��ʱ��0�жϷ�����*************//
void timer0Handle() interrupt 1
{	// 10ms�ж�
	TL0 = TIMER;
	TH0 = TIMER>>8;
	keyValue=scanKey();
	tCount++;
}

//******��ʱ��1��ʼ��*************//
void initTimer1()
{
	TMOD |= 0x01;
	TL1 = TIMER2;
	TH1 = TIMER2>>8;
	TR1 = 1;
	ET1 = 1;
	EA = 1;
}

//******��ʱ��1�жϷ�����*************//
void timer1Handle() interrupt 3
{	// 50ms�ж�
	TL1 = TIMER2;
	TH1 = TIMER2>>8;
	P1=0x00;//����
	DigDisplay(wei);
	wei++;
	if(wei>3)
		wei=0;
	counter++;
	if(counter>=200)
	{
		sec++;
		counter=0;
	}
}

void DigDisplay(unsigned char i)
{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(0):
				LS1=0;LS2=0;LS3=0;LS4=1; break;//��ʾ��0λ
			case(1):
				LS1=0;LS2=0;LS3=1;LS4=0; break;//��ʾ��1λ
			case(2):
				LS1=0;LS2=1;LS3=0;LS4=0; break;//��ʾ��2λ
			case(3):
			  LS1=1;LS2=0;LS3=0;LS4=0; break;
		}
		P1=DisplayData[i];//���Ͷ���
}
