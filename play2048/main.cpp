#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"claim.h"
int map[10][10];//装棋盘数据的二维数组
int cbSize = 4;//棋盘大小，默认为4
char username[11] = { 0 };
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
			while (1)
			{
				printf("请输入用户名：");
				scanf("%s", &username);
				while ((trash = getchar()) != '\n');
				printf("用户名为：%s\n", username);
				if (username[10] != 0)
					printf("用户名过长，最多10个字\n");
				else break;
			}
			while (1)
			{
				
				printf("请输入每边的格子数（4～9）：");
				scanf("%d", &cbSize);
				while ((trash = getchar()) != '\n');
				if (cbSize < 4 || cbSize > 9)
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
			printf("上局玩家为：%s", username);
			break;
		}
		else printf("输入错误\n");
	}

	initgraph(600, 250);
	char str1[200] = { "抵制不良游戏，拒绝盗版游戏." };
	char str2[200] = "注意自我保护，谨防受骗上当.";
	char str3[200] = "适度游戏益脑，沉迷游戏伤身.";
	char str4[200] = "合理安排时间，享受健康生活.";
	settextstyle(40, 20, "黑体");


	outtextxy(20, 20, str1);
	outtextxy(20, 80, str2);
	outtextxy(20, 140, str3);
	outtextxy(20, 200, str4);
	Sleep(3000);
	
	//绘制游戏界面
	
	initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE+200);
	int inGame = 1;//表示玩家还在游戏进程中，默认为1
	int flag = 0;//表示棋盘上没有空格，默认为0
	while (inGame == 1 )
	{
		creBox(cbSize);//创建棋盘
		scoreA(cbSize);//显示数据
		if (readKey())//判断该指令是否需要产生随机数
			inputNumber(cbSize);//将随机数输入到数组
		scoreA(cbSize);//在图形界面实时显示分数
	 	maxScore();//显示最高分
		flag = 0;
	for(int i=0;i<cbSize;i++)
		for (int j = 0; j < cbSize; j++) {
			if (map[i][j] == 2048) {
				creBox(cbSize);
				scoreA(cbSize);
				prWin();//显示你赢了
				inGame = 0;
				break;
			}
			else if (map[i][j] == 0)
				flag = 1;
		}
	if (flag == 0)
		{
			creBox(cbSize);
			scoreA(cbSize);
			//这里需要一个显示游戏结束的函数
			inGame = 0;
			break;
		}
	
	}
	system("PAUSE");//暂停界面，便于观察



	closegraph();
    return 0;
}
