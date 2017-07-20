#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int in();
void fight(int *a,int size);
int life(int *a,int size);
int success();
int result(int life1,int life2);
void rule(int *a,int *b,int size,int ch);
//void menu();
int main()
{
	srand((unsigned)time(NULL));
	int user[15]={0},com[15]={0},life1=0,life2=0,ch=0,i=0;
	for(i=0;i<15;i++){
		user[i]=1;
		com[i]=1;
	}
//	fight(user,15);
//	ch=life(user,15);
//	printf("%d",ch);
	while(1){
		ch=in();
		rule(user,com,15,ch); 
	}
	return 0;
}
//void register(char *name,char *passwd);


//注册和登录
/*void menu()
{
	char name[20]={'\0'};
	char passwd[20]={'\0'};
	while(1)
	{
		system(clear);
		printf("1-->注册\n"
				"2-->登录\n"
				"q-->退出\n"
				"请输入你的选择:\n");
		char ch='\0';
		scanf("%c",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case '1':
				//注册功能

				break;
			case '2':
				//登录功能
				break;
			case 'q':
				//退出功能
				break;
			default:
				printf("输入错误，请重新输入\n");
	}

}*/
//输入选择
int in()
{
	while(1)
	{
		char i='0';
		printf("烽烟起，天下需要您这样的战士，请选择您的战略\n 1--进攻\n2--撤退\n");
		scanf("%c",&i);
		while(getchar()!='\n');
		if(i=='1'){
			printf("天下英雄还看今朝，您选择的是进攻，战斗开始\n");
			return 1;
		}
		else //if(i=='2')
		{
				printf("见好就收，您选择的是撤退\n");
				return 0;
		}
	}
		//	else
		//		printf("暂未有此类型战略，请重新开始您的选择\n");
		//		return 2;
}
//进攻
void fight(int *a,int size)
{
	int i=0,j=0;
	for(i=0;i<3;i++){
		j=rand()%size;
		a[j]=0;
	}
}
//判断生命值
int life(int *a,int size)
{
	int i=0,life=0;
	for(i=0;i<size;i++)
	{
		life+=a[i];
	}
	return life;
}
//判断是否撤退成功
int success()
{
	int i=0,j=0;
	i=rand()%4;
	if(i!=0)
	{
		printf("留得青山在，撤退成功\n");
		return 1;
	}
	else
	{
		printf("糟糕，撤退失败，敌方开始了他们的反击\n");
		return 0;
	}
}
//判断是否胜利
int result(int life1,int life2)
{
	int i=0;
	if(life1==0){
		printf("胜者为王，恭喜您，赢得了胜利\n");
		exit(1);
	}
	else if(life2==0){
		printf("很遗憾，您失败了，我们会记住您对人类做出的贡献\n");
		exit(1);
	}

	
}
//游戏规则
void rule(int *a,int *b,int size,int ch)
{
	if(ch==1){				//攻击
		fight(b,size);
		fight(a,size);
	}
	else if(success())				//撤退
	{
		exit(1);
	}
	else
	{
		fight(a,size);
	}
	int life_c=life(b,size);
	printf("攻击结束，敌方的生命值还剩下%d\n",life_c);
	int life_u=life(a,size);
	printf("对方反攻，我方的生命值还有%d\n",life_u);

	result(life_c,life_u);
	

}
