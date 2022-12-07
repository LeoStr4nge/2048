#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include"claim.h"
#define BOXSIZE 80  //���Ӵ�С	
#define INTERVAL 12  //���Ӽ��
extern int map[10][10];
extern int cbSize;

/// <summary>
/// ��ͼ�ν�����ʾ���ֲ���
/// </summary>
/// <param name="a">������cbSize</param>
void scoreA(int a)
{
	solidroundrect(12, 12, 160, 120, 10, 10);
	int score = 0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			score += map[i][j];

	char str[10] = "";
	sprintf_s(str, "%d", score);
	settextstyle(20, 20, "��������");
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
	char regret[10] = "����(R)";
	settextstyle(20, 12, "����");
	outtextxy(184, 90, regret);

	solidroundrect(278, 78, 360, 122, 10, 10);
	char anew[14] = "����(I)";
	settextstyle(20, 12, "����");
	outtextxy(278, 90, anew);
	//������߷��ж�
	//�޸ĵ�
	int preScore = 0;
	char preUsername[11] = { 0 };
	preScore = loadScore(preUsername);
	char pre[11] = "0";
	if (score > preScore)
		preScore = score;
	sprintf_s(pre, "%d", preScore);
	outtextxy(200, 25, preScore);



}

/// <summary>
/// ����a*a������
/// </summary>
/// <param name="a">�߳�</param>
void creBox(int a)   //��������
{
	setbkcolor(RGB(187, 173, 160));//���ñ�����ɫ
	cleardevice();//����


	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++) {
			int x = (j + 1) * INTERVAL + j * BOXSIZE;
			int y = (i + 1) * INTERVAL + i * BOXSIZE;
			setfillcolor(RGB(205, 193, 180));//���ø�����ɫ
			solidroundrect(x, y + 200, x + BOXSIZE, y + BOXSIZE + 200, 10, 10);
			settextstyle(40, 0, "����");//���ָ�ʽ
			setbkmode(1);//���ֱ�����ɫ͸��
			char str[10] = "";//��int ת����char
			sprintf_s(str, "%d", map[i][j]);
			//ʹ���־��ڸ��ӵ��м�
			int th = textheight(str);
			int tw = textwidth(str);
			int xTemp = (80 - tw) / 2;
			int yTemp = (80 - th) / 2;
			if (map[i][j] != 0) {
				outtextxy(x + xTemp, y + yTemp + 200, str);

			}// �������ڸ�������ʾ


		}

}
/// <summary>
/// ���������
/// </summary>
/// <returns>2��4</returns>
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
/// ����������뵽����
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
/// ��ͼ�α�ʾ��ʷ��ߣ�
/// </summary>
void maxScore()
{
	char cf[15] = { "Highest score:" };
	settextstyle(30, 0, "����");//���ָ�ʽ
	outtextxy(5, 5, cf);
}
/// <summary>
/// ���Ӯ�˽���
/// </summary>
void prWin()
{
	initgraph(300,300);
	char str[10] = "��Ӯ��";
	settextstyle(30, 30, "����");//���ָ�ʽ
	outtextxy(5, 5, str);
}
/// <summary>
/// ��ʾ������
/// </summary>
void prLost()
{
	initgraph(300, 300);
	char str[10] = "������";
	settextstyle(30, 30, "����");//���ָ�ʽ
	outtextxy(5, 5, str);
}

/// <summary>
/// �����Ծ���
/// </summary>
void antiAddiction()
{
	char str1[200] = { "���Ʋ�����Ϸ���ܾ�������Ϸ." };
	char str2[200] = "ע�����ұ�����������ƭ�ϵ�.";
	char str3[200] = "�ʶ���Ϸ���ԣ�������Ϸ����.";
	char str4[200] = "������ʱ�䣬���ܽ�������.";
	settextstyle(40, 20, "����");


	outtextxy(20, 20, str1);
	outtextxy(20, 80, str2);
	outtextxy(20, 140, str3);
	outtextxy(20, 200, str4);
}
	
