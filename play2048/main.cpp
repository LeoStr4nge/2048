#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include "暂定.h"

int main()
{
	int cb_size;  //棋盘大小
	printf("请输入每边的格子数：");
	scanf("%d", &cb_size);
	//绘制界面
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);//创建棋盘
	system("PAUSE");//暂停界面，便于观察
	closegraph();
    return 0;
}
