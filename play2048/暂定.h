#pragma once
#define BOX_SIZE 100  //���Ӵ�С	
#define INTERVAL 15  //���Ӽ��

/// <summary>
/// ����a*a������
/// </summary>
/// <param name="a">�߳�</param>
void cre_box(int a)   //��������
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++) {
			int x = (j + 1) * INTERVAL + j * BOX_SIZE;
			int y = (i + 1) * INTERVAL + i * BOX_SIZE;
			setfillcolor(RGB(250, 193, 180));//���ø�����ɫ
			solidrectangle(x, y, x + BOX_SIZE, y + BOX_SIZE);

			outtextxy(x, y, "0");
		}
}