#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
int map[10][10];
#include "暂定.h"
int main()
{
<<<<<<< HEAD
	
	int cb_size;  //棋盘界面大小
	printf("请输入每边的格子数：");
	scanf("%d", &cb_size);
	input_number();
=======
	int cb_size;  //棋盘大小
	while(1)
	{
		char trash;//用来装多输入的非法字符
		printf("请输入每边的格子数（2～7）：");
		scanf("%d", &cb_size);
		while ((trash = getchar()) != '\n');
		if (cb_size < 2 || cb_size > 7)
			printf("输入错误,");
		else break;
	}

>>>>>>> Leo
	//绘制界面
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);//创建界面
	system("PAUSE");//暂停界面，便于观察
	closegraph();
    return 0;
}

