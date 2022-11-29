#pragma once
#define BOX_SIZE 80  //格子大小	
#define INTERVAL 12  //格子间隔

/// <summary>
/// 创建a*a的棋盘
/// </summary>
/// <param name="a">边长</param>
void cre_box(int a)   //创建棋盘
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++) {
			int x = (j + 1) * INTERVAL + j * BOX_SIZE;
			int y = (i + 1) * INTERVAL + i * BOX_SIZE;
			setfillcolor(RGB(250, 193, 180));//设置格子颜色
			solidrectangle(x, y, x + BOX_SIZE, y + BOX_SIZE);

			outtextxy(x, y, "0");
		}
}