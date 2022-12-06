#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#define BOXSIZE 80  //格子大小	
#define INTERVAL 12  //格子间隔
extern int map[10][10];
extern int cbSize;

/// <summary>
/// 在图形界面显示实时分数
/// </summary>
/// <param name="a">格子数cbSize</param>
void scoreA(int a)
{
	solidroundrect(12, 12, 160, 120, 10, 10);
	int score = 0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			score += map[i][j];

	char str[10] = "";
	sprintf_s(str, "%d", score);
	settextstyle(20, 20, "华文琥珀");
	int th = textheight(str);
	int tw = textwidth(str);
	int xTemp = (148 - tw) / 2;
	int yTemp = (108 - th) / 2;
	outtextxy(xTemp + 12, yTemp + 12, str);
	solidroundrect(184, 12, 360, 66, 10, 10);
	char top[10] = { "top:" };
	settextstyle(50, 20, "Matura MT Script Capitals");
	outtextxy(184, 24, top);
	solidroundrect(184, 78, 266, 122, 10, 10);
	char regret[10] = "悔棋(R)";
	settextstyle(20, 12, "楷体");
	outtextxy(184, 90, regret);

	solidroundrect(278, 78, 360, 122, 10, 10);
	char anew[14] = "保存(I)";
	settextstyle(20, 12, "楷体");
	outtextxy(278, 90, anew);


}

/// <summary>
/// 创建a*a的棋盘
/// </summary>
/// <param name="a">边长</param>
void creBox(int a)   //创建棋盘
{
	setbkcolor(RGB(187, 173, 160));//设置背景颜色
	cleardevice();//清屏


	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++) {
			int x = (j + 1) * INTERVAL + j * BOXSIZE;
			int y = (i + 1) * INTERVAL + i * BOXSIZE;
			setfillcolor(RGB(205, 193, 180));//设置格子颜色
			solidroundrect(x, y + 200, x + BOXSIZE, y + BOXSIZE + 200, 10, 10);
			settextstyle(40, 0, "黑体");//文字格式
			setbkmode(1);//文字背景颜色透明
			char str[10] = "";//将int 转换成char
			sprintf_s(str, "%d", map[i][j]);
			//使数字居于格子的中间
			int th = textheight(str);
			int tw = textwidth(str);
			int xTemp = (80 - tw) / 2;
			int yTemp = (80 - th) / 2;
			if (map[i][j] != 0) {
				outtextxy(x + xTemp, y + yTemp + 200, str);

			}// 将数字在格子中显示


		}

}
/// <summary>
/// 创建随机数
/// </summary>
/// <returns>2或4</returns>
int creNumber()
{
	srand((unsigned)time(NULL) + clock());
	rand();
	if (rand() % 8 == 0) {
		return 4;
	}
	else {
		return 2;
	}
}
/// <summary>
/// 将随机数输入到数组
/// </summary>
void inputNumber(int a)
{
	int i;
	for (i = 0; i < 2;)
	{
		int c = rand() % 9;
		int b = rand() % 9;
		if (c < a && b < a)
			if (map[c][b] == 0) {
				map[c][b] = creNumber();
				i++;
			}
	}

}
/// <summary>
/// 在图形表示历史最高；
/// </summary>
void maxScore()
{
	char cf[15] = { "Highest score:" };
	settextstyle(30, 0, "楷体");//文字格式
	outtextxy(5, 5, cf);
}
/// <summary>
/// 输出赢了界面
/// </summary>
void prWin()
{
	initgraph(300,300);
	char str[10] = "你赢麻了";
	settextstyle(30, 30, "楷体");//文字格式
	outtextxy(5, 5, str);
}

/// <summary>
/// 防沉迷警告
/// </summary>
void antiAddiction()
{
	char str1[200] = { "抵制不良游戏，拒绝盗版游戏." };
	char str2[200] = "注意自我保护，谨防受骗上当.";
	char str3[200] = "适度游戏益脑，沉迷游戏伤身.";
	char str4[200] = "合理安排时间，享受健康生活.";
	settextstyle(40, 20, "黑体");


	outtextxy(20, 20, str1);
	outtextxy(20, 80, str2);
	outtextxy(20, 140, str3);
	outtextxy(20, 200, str4);
}
	
