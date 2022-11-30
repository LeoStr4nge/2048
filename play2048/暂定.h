#pragma once
#define BOX_SIZE 80  //格子大小	
#define INTERVAL 12  //格子间隔

/// <summary>
/// 在图形界面显示实时分数
/// </summary>
/// <param name="a"></param>
void score_a(int a)
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
		int x_temp = (148 - tw) / 2;
		int y_temp = (108 - th) / 2; 
		outtextxy(x_temp+12, y_temp+12, str);

}

/// <summary>
/// 创建a*a的棋盘
/// </summary>
/// <param name="a">边长</param>
void cre_box(int a )   //创建棋盘
{
	setbkcolor(RGB(187, 173, 160));//设置背景颜色
	cleardevice();//清屏
	
	
		for (int i = 0; i < a; i++)
			for (int j = 0; j < a; j++) {
				int x = (j + 1) * INTERVAL + j * BOX_SIZE;
				int y = (i + 1) * INTERVAL + i * BOX_SIZE;
				setfillcolor(RGB(205, 193, 180));//设置格子颜色
				solidroundrect(x, y+120, x + BOX_SIZE, y + BOX_SIZE+120,10,10);
				settextstyle(40, 0,"黑体");//文字格式
				setbkmode(1);//文字背景颜色透明
				char str[10]= "";//将int 转换成char
				sprintf_s(str, "%d", map[i][j]); 
				//使数字居于格子的中间
				int th = textheight(str);
				int tw = textwidth(str);
				int x_temp = (80 - tw) / 2;
				int y_temp = (80 - th) / 2;
				if (map[i][j] != 0) {
					outtextxy(x + x_temp, y + y_temp+120, str);
					
				}// 将数字在格子中显示

				
			}
		score_a(a);//显示实时分数；
}
/// <summary>
/// 创建随机数
/// </summary>
/// <returns>2或4</returns>
int cre_number()
{
	srand((unsigned)time(NULL)+clock());
	rand();
	if (rand()%8==0) {
		return 4;
	}
	else {
		return 2;
	}
}
/// <summary>
/// 将随机数输入到数组
/// </summary>
void input_number(int a)
{
	int i;
	for (i = 0; i < 2;)
	{
		int c = rand() % 9;
		int b = rand() % 9;
		if(c<a && b<a)
		if (map[c][b] == 0) {
			map[c][b] = cre_number();
			i++;
		}
	}
	
}
/// <summary>
/// 在图形表示历史最高；
/// </summary>
void max_score()
{
	char cf[15] = { "Highest score:" };
	settextstyle(30, 0, "楷体");//文字格式
	outtextxy(5,5, cf);
}
