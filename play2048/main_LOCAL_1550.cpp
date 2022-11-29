#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
int map[10][10];
#include "暂定.h"
int main()
{
	
	int cb_size;  //棋盘界面大小
	printf("请输入每边的格子数：");
	scanf("%d", &cb_size);
	input_number();
	//绘制界面
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);//创建界面
	system("PAUSE");//暂停界面，便于观察
	closegraph();
    return 0;
}

