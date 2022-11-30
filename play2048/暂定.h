#pragma once
#define BOX_SIZE 80  //格子大小	
#define INTERVAL 12  //格子间隔

/// <summary>
/// 创建a*a的棋盘
/// </summary>
/// <param name="a">边长</param>
void cre_box(int a )   //创建棋盘
{
	
	
		for (int i = 0; i < a; i++)
			for (int j = 0; j < a; j++) {
				int x = (j + 1) * INTERVAL + j * BOX_SIZE;
				int y = (i + 1) * INTERVAL + i * BOX_SIZE;
				setfillcolor(RGB(250, 193, 180));//设置格子颜色
				solidrectangle(x, y, x + BOX_SIZE, y + BOX_SIZE);
				settextstyle(50, 0,"黑体");//文字格式
				setbkmode(1);//文字背景颜色透明
				char str[10]= "";//将int 转换成char
				sprintf_s(str, "%d", map[i][j]); 
				//使数字居于格子的中间
				int th = textheight(str);
				int tw = textwidth(str);
				int x_temp = (80 - tw) / 2;
				int y_temp = (80 - th) / 2;
				if (map[i][j] != 0) {
					outtextxy(x + x_temp, y + y_temp, str);
				}// 将数字在格子中显示
		
			}
}
/// <summary>
/// 创建随机数
/// </summary>
/// <returns></returns>
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
void input_number()
{
	int i;
	for (i = 0; i < 2;)
	{
		int c = rand() % 4;
		int b = rand() % 4;
		if (map[c][b] == 0) {
			map[c][b] = cre_number();
			i++;
		}
	}
	
}
void score_a(int a)
{
	char cf[10] = { "SCORE:"};
	outtextxy(5, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, cf);
	int score = 0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			score  += map[i][j];
	
	char str[10] = "";
	sprintf_s(str, "%d", score);
	outtextxy(160, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, str);

}