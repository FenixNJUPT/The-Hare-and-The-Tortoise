/*
rabbit 012
       543
*/
#include "config.h"

struct Rabbit
{
	char x[3];
	char y[2];
  unsigned char Score;	// ���ӵķ���
	unsigned char Speed;	// ���ӵ��ٶ�
}rabbit;	// ���ӽṹ��

static struct Barrier
{
	char x[3];	// �ϰ���ĺ�����
	char y;	// �ϰ����������
//	unsigned char yes;
}barrier;	// �ϰ���ṹ��


enum Dir{ speedup, speeddown, left, right}; //����ö��


//***********��������***************//
unsigned char DispRAM[8]={0}; // �����껺��
unsigned char tCount;
unsigned char keyValue;
unsigned char speedLevel=25;
extern uchar keyVal; // ��Դ��key.c
//**********************************//
static void createBarrier()
{
	barrier.x[0] = rand()%(WIDTH-3);
	barrier.x[1] = barrier.x[0]+1;
	barrier.x[2] = barrier.x[0]+2;
	barrier.y = WIDTH-1;
}

//****************��ʼ�����ӵ�λ�õ�***********************//
static void initRabbit()
{
	//********��ʼ�����Ӳ���**********//
	rabbit.y[0]=1;
	rabbit.y[1]=1;
	rabbit.y[2]=1;
	rabbit.y[3]=0;
	rabbit.y[4]=0;
	rabbit.y[5]=0;
	
	rabbit.x[0]=3;
	rabbit.x[1]=4;
	rabbit.x[2]=5;
	rabbit.x[3]=5;
	rabbit.x[4]=4;
	rabbit.x[5]=3;
	createBarrier();
}

//********************ˢ�½���*******************//
static void drawRabbit()
{
	unsigned char i=0;
	for(i=0; i<8; i++) DispRAM[i]=0;
	for(i=0; i<6; i++)
		DispRAM[rabbit.y[i]] |= 1<<rabbit.x[i];
	scanDisplay(DispRAM);
	drawPoint(food.x, food.y);
}

//********************�����˶�����ˢ��*******************//
static void runRabbit()
{
	rabbit.x[0]=rabbit.x[1]-1;
	rabbit.x[2]=rabbit.x[1]+1;
	rabbit.x[5]=rabbit.x[1]-1;
	rabbit.x[4]=rabbit.x[1];
	rabbit.x[3]=rabbit.x[1]+1;
}


//*******************���򰴼�����***********************//
static void changeDir(unsigned char key)
{
	// ���򰴼��Ĺ���
	switch(key)
	{
		case speedup:	
			speedLevel--; break;
		case speeddown: 		
			speedLevel++; break;
		case left: 	
      snake.x[1]=snake.x[1]-1;	break;
		case right: 
			snake.x[1]=snake.x[1]+1;  break;
		default: break;
	}
}

//********************������Ϸ����������*********************//
void startRabbit()
{
	uchar i,j;
	initRabbit();
	while(1)
	{
		changeDir(keyValue);
		
		// �ϰ������е��ٶȣ���speedLevel����
		if(tCount >= speedLevel)
		{
			tCount=0;
			barrier.y--;
			runRabbit();
		}
			
		//**********************�������߼��ϰ���***************************//
		// �޶����ӻ��Χ
		if(snake.x[1]>(WIDTH-2))
		{
			Rabbit.Score=Rabbit.Score-5;
			snake.x[1]=snake.x[1]-1;
		}
		else if(snake.x[1]<1)
		{
			Rabbit.Score=Rabbit.Score-5;
			snake.x[1]=snake.x[1]+1;
		}
		// �����ϰ���
		for(i=0; i<3; i++)
	  {
		  for(j=0;j<3;j++)
		  {
		     if(barrier.x[j]==snake.x[i] && barrier.y[j]==snake.y[i])
		     Rabbit.Score=Rabbit.Score-5;
		  }
	  }  
		drawRabbit();
	}
}
