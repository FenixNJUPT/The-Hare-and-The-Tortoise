/*
rabbit 012
       543
*/
#include "config.h"

struct Rabbit
{
	char x[3];
	char y[2];
  unsigned char Score;	// 兔子的分数
	unsigned char Speed;	// 兔子的速度
}rabbit;	// 兔子结构体

static struct Barrier
{
	char x[3];	// 障碍物的横坐标
	char y;	// 障碍物的纵坐标
//	unsigned char yes;
}barrier;	// 障碍物结构体


enum Dir{ speedup, speeddown, left, right}; //方向枚举


//***********变量声明***************//
unsigned char DispRAM[8]={0}; // 蛇坐标缓存
unsigned char tCount;
unsigned char keyValue;
unsigned char speedLevel=25;
extern uchar keyVal; // 来源于key.c
//**********************************//
static void createBarrier()
{
	barrier.x[0] = rand()%(WIDTH-3);
	barrier.x[1] = barrier.x[0]+1;
	barrier.x[2] = barrier.x[0]+2;
	barrier.y = WIDTH-1;
}

//****************初始化兔子的位置等***********************//
static void initRabbit()
{
	//********初始化兔子参数**********//
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

//********************刷新界面*******************//
static void drawRabbit()
{
	unsigned char i=0;
	for(i=0; i<8; i++) DispRAM[i]=0;
	for(i=0; i<6; i++)
		DispRAM[rabbit.y[i]] |= 1<<rabbit.x[i];
	scanDisplay(DispRAM);
	drawPoint(food.x, food.y);
}

//********************兔子运动坐标刷新*******************//
static void runRabbit()
{
	rabbit.x[0]=rabbit.x[1]-1;
	rabbit.x[2]=rabbit.x[1]+1;
	rabbit.x[5]=rabbit.x[1]-1;
	rabbit.x[4]=rabbit.x[1];
	rabbit.x[3]=rabbit.x[1]+1;
}


//*******************方向按键处理***********************//
static void changeDir(unsigned char key)
{
	// 方向按键的规则
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

//********************启动游戏（主函数）*********************//
void startRabbit()
{
	uchar i,j;
	initRabbit();
	while(1)
	{
		changeDir(keyValue);
		
		// 障碍物运行的速度，由speedLevel决定
		if(tCount >= speedLevel)
		{
			tCount=0;
			barrier.y--;
			runRabbit();
		}
			
		//**********************触碰边线及障碍物***************************//
		// 限定兔子活动范围
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
		// 触及障碍物
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
