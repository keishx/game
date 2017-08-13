#include<stdio.h>
int main()
{
	int year=1900,month=1,y=0,d=0,days=30,i=0;
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("请输入你要查看的年份和月份\n");	
	scanf("%d%d",&year,&month);
	getchar();
	//计算距离1900.1.1有多少天
	if(year>=1900){
		for(i=0;i<(year-1900);i++){
			y=1900+i;
			if((y%4==0&&y%100!=0)||y%400==0)
				d=d+366;
			else
				d=d+365;
	 	}
			if((year%4==0&&year%100!=0)||year%400==0)
				m[1]=29;
			else
				m[1]=28;
			for(i=0;i<month-1;i++){
				d+=m[i];

			}	
				i=month-1;
				days=m[i];
				d+=1;
			printf("Sun\tMon\tTes\tWed\tTur\tFri\tSat\n");
			for(y=0;y<(d%7);y++)
				printf("\t");//余数正好等于多少个空格
			for(y=1;y<=days;y++){
				printf("%d\t",y);//把天数依次打印
				if((y+d%7)%7==0)
					printf("\n"); //每七个单位一换行
			}
				printf("\n");
	}else{
		if(year==1752&&month==9)
			m[8]=19;
		else m[8]=30;
			for(i=1;i<(1900-year);i++){
			y=1900-i;
			if((y%4==0&&y%100!=0)||y%400==0)
				d=d+366;
			else
				d=d+365;
	 	}
			if((year%4==0&&year%100!=0)||year%400==0)
				m[1]=29;
			else
				m[1]=28;
			for(i=12;i>=month;i--){
				d+=m[i-1];

			}	
				i=month-1;
				days=m[i];
				d-=1;
			printf("Sun\tMon\tTu\tWed\tTh\tFri\tSat\n");
		if(year==1752&&month==9)
			{
				for(y=0;y<7-(d%7);y++)
				printf("\t");//余数正好等于多少个空格
				printf("1\t2\t");
			for(y=14;y<=days+11;y++){
				printf("%d\t",y);//把天数依次打印
				if((y-11+(7-(d%7)))%7==0)
					printf("\n"); //每七个单位一换行
			}   return 0;
		}
		 if(d%7==0);
		 else{
			for(y=0;y<7-(d%7);y++)
				printf("\t");//余数正好等于多少个空格
		 }
			for(y=1;y<=days;y++){
				printf("%d\t",y);//把天数依次打印
				if((y+(7-(d%7)))%7==0)
					printf("\n"); //每七个单位一换行
			}
				printf("\n");
	}	
			return 0;
}
