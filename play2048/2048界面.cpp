#include<stdio.h>
#include<graphics.h>
#define BOX_SIZE 100  //���Ӵ�С	
#define INTERVAL 15  //���Ӽ��

/// <summary>
/// ����a*a�Ľ���
/// </summary>
/// <param name="a">�߳�</param>
void cre_box(int a)   //��������
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
	int cb_size;  //���̴�С
	scanf("%d", &cb_size);
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);
	while (1);
	closegraph();
    return 0;
}
//����һ��������
//����һ��������
//����һ��������
//����һ��������
//����һ��������