#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int map[10][10];//装棋盘数据的二维数组
int cbSize;//棋盘大小
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
				printf("请输入每边的格子数（4～9）：");
				scanf("%d", &cbSize);
				while ((trash = getchar()) != '\n');//清空输入缓冲区
				if (cbSize < 2 || cbSize > 9)
				{
					printf("输入错误,");
				}
				else break;
			}
			break;
		}

		else if (order == 2)
		{
			loadSave();
			break;
		}
		else printf("输入错误\n");
	}



	
	//绘制界面
	initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE+120);
	int inGame = 1;
	while (inGame == 1 )
	{
	
		creBox(cbSize);//创建棋盘
	
		if (readKey())//按键操作
		inputNumber(cbSize);//将随机数输入到数组
		scoreA(cbSize);//在图形界面实时显示分数
		maxScore();//显示最高分
	for(int i=0;i<cbSize;i++)
		for (int j = 0; j < cbSize; j++) {
			if (map[i][j] == 2048) {
				saveGame();
				inGame = 0;
				break;
			}
		}
	}
	system("PAUSE");//暂停界面，便于观察



	closegraph();
    return 0;
}
