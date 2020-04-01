///*********************************************************************
//			贪吃蛇源码snake.c
//**********************************************************************/
//#include "config.h"
//static struct Food
//{
//	unsigned char x;	// 食物的横坐标
//	unsigned char y;	// 食物的纵坐标
////	unsigned char yes;
//}food;	// 食物结构体

//struct Snake
//{
//	char x[SNAKE_Max_Long];
//	char y[SNAKE_Max_Long];
//	unsigned char Long;		// 蛇的长度
//	unsigned char Life;		// 蛇的生命
////	unsigned char Score;	// 蛇的分数，本例中没使用
//	unsigned char Level;	// 蛇的等级
//	unsigned char Dir;		// 蛇移动方向
//}snake;	// 蛇结构体
////****************************************//

//enum Dir{up, down, left, right}; //方向枚举


////***********变量声明***************//
//unsigned char DispRAM[8]={0}; // 蛇坐标缓存
//unsigned char tCount;
//unsigned char keyValue=right;
//unsigned char speedLevel=25;
//extern uchar keyVal; // 来源于key.c
////**********************************//


//// 用此函数来产生食物最好使蛇的长度不要那么长，蛇越长，点越难找，递归越深
//static void createFood()
//{
//	unsigned char i;
//	food.x = rand()%WIDTH;
//	food.y = rand()%LENGTH;
//	for(i=0; i<snake.Long; i++)
//	{
//		if(food.x==snake.x[i] && food.y==snake.y[i])
//		createFood();	
//	}
//}

////****************初始化蛇的位置等***********************//
//static void initSnake()
//{
//	//********清除内存数据**********//
//	unsigned char i;
//	for(i=0; i<SNAKE_Max_Long; i++)
//	{
//		snake.x[i]=-1;
//		snake.y[i]=-1;
//	}
//	
//	//********初始化蛇参数**********//
//	snake.Long=2;	// 初始化蛇的长度为两节
//	snake.Life=1;	//初始化蛇活着
//	snake.Dir=right;
//	snake.x[1]=0;
//	snake.y[1]=2;
//	snake.x[0]=1;
//	snake.y[0]=2;
//	createFood();
//}

////********************刷新界面*******************//
//static void drawSnake()
//{
//	unsigned char i=0;
//	for(i=0; i<8; i++) DispRAM[i]=0;
//	for(i=0; i<snake.Long; i++)
//		DispRAM[snake.y[i]] |= 1<<snake.x[i];
//	scanDisplay(DispRAM);
//	drawPoint(food.x, food.y);
//}

////********************蛇运动坐标刷新*******************//
//static void runSnake()
//{
//	unsigned char i;
//	
//	// 蛇身体坐标移动，蛇头方向坐标逐渐向蛇尾方向移动
//	for(i=snake.Long; i>0; i--)
//	{	
//		snake.y[i]=snake.y[i-1];
//		snake.x[i]=snake.x[i-1];
//	}
//	
//	// 重新获得蛇的头部位置
//	switch(snake.Dir)
//	{	
//		case up:	snake.y[0]-=1; break;
//		case down:	snake.y[0]+=1; break;
//		case left:	snake.x[0]-=1; break;
//		case right: snake.x[0]+=1; break;
//		default: break;
//	}
//	
//	// 蛇吃到食物
//	if(snake.x[0]==food.x && snake.y[0]==food.y)
//	{
//		snake.Long++;
//		createFood();
//	}
//	

//}

////*******************方向按键处理***********************//
//static void changeDir(unsigned char key)
//{
//	// 方向按键的规则
//	switch(key)
//	{
//		case up:	if(snake.Dir != down)	snake.Dir=up; 		break;
//		case down: 	if(snake.Dir != up)		snake.Dir=down; 	break;
//		case left: 	if(snake.Dir != right) 	snake.Dir=left; 	break;
//		case right: if(snake.Dir != left) 	snake.Dir=right;	break;
//		default: break;
//	}
//}

////********************启动贪吃蛇游戏（主函数）*********************//
//void startSnake()
//{
//	uchar i=0;
//	initSnake();
//	while(snake.Life)
//	{
//		changeDir(keyValue);
//		
//		// 蛇运行的速度，由speedLevel决定
//		if(tCount >= speedLevel)
//		{
//			tCount=0;
//			runSnake();
//		}
//			
//		//**********************蛇之dead***************************//
//		// 限定蛇活动范围，超范围就dead
//		if((snake.x[0]>(WIDTH-1)) || (snake.x[0]<0) || (snake.y[0]>(LENGTH-1)) || (snake.y[0]<0))
//		{
//			snake.Life=0;	
//			snake.Level=1;
//			speedLevel=25;
//			keyVal=right;	
//		}
//		// 蛇自杀检测
//		for(i=4; i<=snake.Long; i++)
//		{
//			if(snake.x[i-1]==snake.x[0] && snake.y[i-1]==snake.y[0])
//			{
//				snake.Life=0;
//				snake.Level=1;
//				speedLevel=25;
//				keyVal=right;	
//			}
//		}
//		//***********************************************************//
//		
//		// 等级越高速度越快
//		if(snake.Long >= SNAKE_Max_Long)
//		{
//			delayMs(500); // 延一下时
//			initSnake();
//			speedLevel-=5;
//			keyVal=right;			
//			if(++snake.Level > 5)
//			{
//				// 大神，你已经打爆机了，现在从头再来。。。
//				snake.Level=1;
//				speedLevel=25;						
//			}
//			tCount=0;
//		}
//		drawSnake();
//	}
//}

/*
rabbit 012
       543
*/
#include "config.h"
struct Rabbit
{
	char x[6];
	char y[6];
  int Score;	// 兔子的分数
	unsigned char Speed;	// 兔子的速度
}rabbit;	// 兔子结构体

struct Tor
{
	char x[6];
	char y[6];
  int Score;	// 乌龟的分数
	unsigned char Speed;	// 乌龟的速度
}tor;	// 乌龟结构体

static struct Barrier
{
	char x[3];	// 障碍物的横坐标
	char y;	// 障碍物的纵坐标
//	unsigned char yes;
}barrier;	// 障碍物结构体


enum Dir{ speedup1, speeddown1, left1, right1, speedup2, speeddown2, left2, right2, nothing}; //方向枚举


//***********变量声明***************//
unsigned char DispRAM[8]={0}; // 坐标缓存
unsigned char DisplayData[8]={0};
unsigned char code smgduan[11]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09,0x31};//显示0~F的值
unsigned char code smgduandot[10]={0x02,0x9e,0x24,0x0c,0x98,0x48,0x40,0x1e,0x00,0x08,};//显示0~F的值
unsigned char tCount=0;
unsigned char keyValue;
unsigned char speedLevel=25;
unsigned char skillflag=0,skillflag2=0,v=0;
extern uchar keyVal; // 来源于key.c
extern unsigned int sec;
//**********************************//
void createBarrier()
{
	unsigned char mod;
	if(sec/10==0)
		mod=0;
	else if(sec/10==1)
		mod=1;
	else
		mod=2;
	switch(mod)
	{
		case 0:
		barrier.x[0] = rand()%(WIDTH);
	  barrier.x[1] = barrier.x[0];
	  barrier.x[2] = barrier.x[0];
	  barrier.y = WIDTH-1;
		break;
	  case 1:
		barrier.x[0] = rand()%(WIDTH-1);
	  barrier.x[1] = barrier.x[0]+1;
	  barrier.x[2] = barrier.x[0];
	  barrier.y = WIDTH-1;
    break;
		case 2:
	  barrier.x[0] = rand()%(WIDTH-2);
	  barrier.x[1] = barrier.x[0]+1;
	  barrier.x[2] = barrier.x[0]+2;
	  barrier.y = WIDTH-1;
		break;
	}
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
	
	rabbit.x[0]=1;
	rabbit.x[1]=2;
	rabbit.x[2]=3;
	rabbit.x[3]=3;
	rabbit.x[4]=2;
	rabbit.x[5]=1;
	rabbit.Score=0;
	createBarrier();
}

static void initTor()
{
	//********初始化tor参数**********//
	tor.y[0]=2;
	tor.y[1]=2;
	tor.y[2]=1;
	tor.y[3]=1;
	tor.y[4]=0;
	tor.y[5]=0;
	
	tor.x[0]=5;
	tor.x[1]=6;
	tor.x[2]=5;
	tor.x[3]=6;
	tor.x[4]=5;
	tor.x[5]=6;
	tor.Score=0;
	createBarrier();
}

//********************刷新界面*******************//
static void drawRabbit()
{
	unsigned char i,j;
	for(i=0; i<8; i++) 
	  DispRAM[i]=0;
	for(j=0; j<6; j++)
		DispRAM[rabbit.x[j]] |= 1<<rabbit.y[j];
	for(j=0;j<3;j++)
	  DispRAM[barrier.x[j]] |= 1<<barrier.y;
	scanDisplay(DispRAM);
}

static void drawTor()
{
	unsigned char i,j;
	for(i=0; i<8; i++) 
	  DispRAM[i]=0;
	for(j=0; j<6; j++)
		DispRAM[tor.x[j]] |= 1<<tor.y[j];
	for(j=0;j<3;j++)
	  DispRAM[barrier.x[j]] |= 1<<barrier.y;
	scanDisplay(DispRAM);
}

//********************运动坐标刷新*******************//
static void runRabbit()
{
	rabbit.x[0]=rabbit.x[1]-1;
	rabbit.x[2]=rabbit.x[1]+1;
	rabbit.x[5]=rabbit.x[1]-1;
	rabbit.x[4]=rabbit.x[1];
	rabbit.x[3]=rabbit.x[1]+1;
}

static void runTor()
{
	if(skillflag==0)
	{
	  tor.x[0]=tor.x[1]-1;
 	  tor.x[2]=tor.x[1]-1;
	  tor.x[3]=tor.x[1];
	  tor.x[4]=tor.x[1]-1;
	  tor.x[5]=tor.x[1];
		tor.y[0]=2;
		tor.y[2]=1;
		tor.y[3]=1;
		tor.y[4]=0;
		tor.y[5]=0;
	}
	else
	{
		tor.x[0]=tor.x[1];
 	  tor.x[2]=tor.x[1];
	  tor.x[3]=tor.x[1];
	  tor.x[4]=tor.x[1];
	  tor.x[5]=tor.x[1];
		tor.y[0]=3;
		tor.y[2]=3;
		tor.y[3]=1;
		tor.y[4]=0;
		tor.y[5]=0;
	}
}


//*******************方向按键处理***********************//
static void changeDir(unsigned char key)
{
	static unsigned char temp,tempskill;
	// 方向按键的规则
  if(temp!=key)
  {	
	switch(key)
	{
		case speedup1:	
			speedLevel--; break;
		case speeddown1: 		
			speedLevel++; 
		  if((tempskill==speedup1)&&(v<5))
			{
			  skillflag2=1;
				v++;
			}
		  break;
		case left1: 	
      rabbit.x[1]=rabbit.x[1]-1;	break;
		case right1: 
			rabbit.x[1]=rabbit.x[1]+1;  break;
		case speedup2:	
			speedLevel--;	break;
		case speeddown2: 		
			speedLevel++; 
		  if(tempskill==speedup2)
			  skillflag=~skillflag;
		  break;
		case left2: 	
      tor.x[1]=tor.x[1]-1;	break;
		case right2: 
			tor.x[1]=tor.x[1]+1;  break;
		case nothing:
			if(temp!=nothing)
				tempskill=temp;
			break;
		default: break;
	}
	temp=key;
  }
}

//********************启动游戏（主函数）*********************//
void startRabbit()
{
	uchar i,j;
	uint soc=0;
	initRabbit();
	while(1)
	{
		if(sec>29)
			TR0=0;
		changeDir(keyValue);
		runRabbit();
		if(barrier.y<0)
		{
			createBarrier();
		}
		// 障碍物运行的速度，由speedLevel决定
		if(tCount >= speedLevel)
		{
			tCount=0;
			barrier.y--;
			soc++;
			if(soc>4)
				{
					soc=0;
			    rabbit.Score++;
				}
		}
			
		//**********************触碰边线及障碍物***************************//
		// 限定兔子活动范围
		if(rabbit.x[1]>(WIDTH-2))
		{
			rabbit.Score=rabbit.Score-3;
			rabbit.x[1]=rabbit.x[1]-1;
		}
		else if(rabbit.x[1]<1)
		{
			rabbit.Score=rabbit.Score-3;
			rabbit.x[1]=rabbit.x[1]+1;
		}
		// 触及障碍物
		for(i=0; i<6; i++)
	  {
		  for(j=0;j<3;j++)
		  {
		     if(barrier.x[j]==rabbit.x[i] && barrier.y==rabbit.y[i])
				 {
					 if(skillflag2==0)
		         rabbit.Score=rabbit.Score-3;
					 else
						 skillflag2=0;
				   createBarrier();
				 }
		  }
	  }
		if(rabbit.Score<0)
			rabbit.Score=0;
		if(sec%10==0&&sec<30)
		{
			DisplayData[1]=smgduan[10];
	    DisplayData[0]=smgduan[sec/10+1];
		}
		else
		{
	    DisplayData[0]=smgduan[rabbit.Score%10];
	    DisplayData[1]=smgduan[rabbit.Score/10];
		}
		drawRabbit();
	}
}



/********************************************************************************************
********************************************************************************************/



void startTor()
{
	uchar i,j;
	uint soc=0;
	initTor();
	while(1)
	{
		if(sec>29)
			TR0=0;
		changeDir(keyValue);
		runTor();
		if(barrier.y<0)
		{
			createBarrier();
		}
		// 障碍物运行的速度，由speedLevel决定
		if(tCount >= speedLevel)
		{
			tCount=0;
			barrier.y--;
			soc++;
			if(soc>4)
				{
					soc=0;
			    tor.Score++;
				}
		}
			
		//**********************触碰边线及障碍物***************************//
		// 限定乌龟活动范围
		if(tor.x[1]>(WIDTH-1))
		{
			tor.Score=tor.Score-3;
			tor.x[1]=tor.x[1]-1;
		}
		else if(((tor.x[1]<1)&&(skillflag==0))||((tor.x[1]<0)&&(skillflag==1)))
		{
			tor.Score=tor.Score-3;
			tor.x[1]=tor.x[1]+1;
		}
		// 触及障碍物
		for(i=0; i<6; i++)
	  {
		  for(j=0;j<3;j++)
		  {
		     if(barrier.x[j]==tor.x[i] && barrier.y==tor.y[i])
				 {
		       tor.Score=tor.Score-3;		 
				   createBarrier();
				 }
		  }
	  }
		if(tor.Score<0)
			tor.Score=0;
		if(sec%10==0&&sec<30)
		{
			DisplayData[3]=smgduan[10];
	    DisplayData[2]=smgduandot[sec/10+1];
		}
		else
		{
	    DisplayData[2]=smgduandot[tor.Score%10];
	    DisplayData[3]=smgduan[tor.Score/10];
		}
		drawTor();
	}
}


/***********************************************************************************************
************************************************************************************************/


void startDuel()
{
	uchar i,j;
	uint soc=0;
	initRabbit();
	initTor();
	while(1)
	{
		if(sec>29)
			TR0=0;
		changeDir(keyValue);
		runRabbit();
		runTor();
		if(barrier.y<0)
		{
			createBarrier();
		}
		// 障碍物运行的速度，由speedLevel决定
		if(tCount >= speedLevel)
		{
			tCount=0;
			barrier.y--;
			soc++;
			if(soc>4)
				{
					soc=0;
			    rabbit.Score++;
					tor.Score++;
				}
		}
			
		//**********************触碰边线及障碍物***************************//
		// 限定活动范围
		if(rabbit.x[1]>(WIDTH-2))
		{
			rabbit.Score=rabbit.Score-3;
			rabbit.x[1]=rabbit.x[1]-1;
		}
		else if(rabbit.x[1]<1)
		{
			rabbit.Score=rabbit.Score-3;
			rabbit.x[1]=rabbit.x[1]+1;
		}
		
		if(tor.x[1]>(WIDTH-1))
		{
			tor.Score=tor.Score-3;
			tor.x[1]=tor.x[1]-1;
		}
		else if(((tor.x[1]<1)&&(skillflag==0))||((tor.x[1]<0)&&(skillflag==1)))
		{
			tor.Score=tor.Score-3;
			tor.x[1]=tor.x[1]+1;
		}
		
		// 触及障碍物
		for(i=0; i<6; i++)
	  {
		  for(j=0;j<3;j++)
		  {
		     if(barrier.x[j]==rabbit.x[i] && barrier.y==rabbit.y[i])
				 {
           if(skillflag2==0)
		         rabbit.Score=rabbit.Score-3;
					 else
						 skillflag2=0;					 
				   createBarrier();
				 }
		  }
	  }
		for(i=0; i<6; i++)
	  {
		  for(j=0;j<3;j++)
		  {
		     if(barrier.x[j]==tor.x[i] && barrier.y==tor.y[i])
				 {
		       tor.Score=tor.Score-3;		 
				   createBarrier();
				 }
		  }
	  }
		if(rabbit.Score<0)
			rabbit.Score=0;
		if(tor.Score<0)
			tor.Score=0;
		if(sec%10==0&&sec<30)
		{
			DisplayData[3]=smgduan[10];
	    DisplayData[2]=smgduandot[sec/10+1];
			DisplayData[1]=smgduan[10];
	    DisplayData[0]=smgduan[sec/10+1];
		}
		else
		{
	    DisplayData[0]=smgduan[rabbit.Score%10];
	    DisplayData[1]=smgduan[rabbit.Score/10];
		  DisplayData[2]=smgduandot[tor.Score%10];
	    DisplayData[3]=smgduan[tor.Score/10];
		}
		drawRabbit();
		drawTor();
	}
}