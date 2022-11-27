#include<stdio.h>
#include<graphics.h>
#define BOX_SIZE 100  //格子大小	
#define INTERVAL 15  //格子间隔

/// <summary>
/// 创建a*a的界面
/// </summary>
/// <param name="a">边长</param>
void cre_box(int a)   //创建界面
{
	for(int i=0;i<a;i++)
		for (int j=0; j < a; j++) {
			int x = (j + 1) * INTERVAL + j * BOX_SIZE;
			int y = (i + 1) * INTERVAL + i * BOX_SIZE;
			setfillcolor(RGB(250, 193, 180));
			solidrectangle(x, y, x + BOX_SIZE, y + BOX_SIZE);
		}
}
int main()
{
	int cb_size;  //棋盘大小
	scanf("%d", &cb_size);
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);
	while (1);
	closegraph();
    return 0;
}
//这是一句测试语句
//这是一句测试语句
//这是一句测试语句
//这是一句测试语句
//这是一句测试语句