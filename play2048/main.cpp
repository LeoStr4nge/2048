#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int map[10][10];//装棋盘数据的二维数组
int cb_size;//棋盘大小
#include "暂定.h"
#include "暂定2.h"
int main()
{
	int order;//菜单界面输入的命令
	char trash;//用来装多输入的非法字符
	printf("欢迎游玩2048\n");
	while (1)
	{
		printf("输入1以开始新游戏\n输入2以继续游戏\n");
		scanf("%d", &order);
		while ((trash = getchar()) != '\n');//清空输入缓冲区


		if (order == 1)
		{
			while (1)//自定义棋盘
			{
				printf("请输入每边的格子数（2～9）：");
				scanf("%d", &cb_size);
				while ((trash = getchar()) != '\n');//清空输入缓冲区
				if (cb_size < 2 || cb_size > 9)
				{
					printf("输入错误,");
				}
				else break;
			}
			break;
		}

		else if (order == 2)
		{
			printf("存档系统还没做好呢");
			return 0;

		}
		else printf("输入错误\n");
	}





	//绘制界面
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE+60);
	while (1)
	{
	input_number();
	score_a(cb_size);
	cre_box(cb_size);//创建棋盘
	read_key();

	}	system("PAUSE");//暂停界面，便于观察



	closegraph();
    return 0;
}

