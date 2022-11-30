#pragma once
#define BOX_SIZE 80  //���Ӵ�С	
#define INTERVAL 12  //���Ӽ��

/// <summary>
/// ��ͼ�ν�����ʾʵʱ����
/// </summary>
/// <param name="a"></param>
void score_a(int a)
{
		char cf[10] = { "score:" };
		outtextxy(5, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE+80, cf);
		int score = 0;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < a; j++)
				score += map[i][j];
		solidrectangle(160,80+ (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, 290, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE+40+80);
		char str[10] = "";
		sprintf_s(str, "%d", score);
		outtextxy(160, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE+80, str);
	

}

/// <summary>
/// ����a*a������
/// </summary>
/// <param name="a">�߳�</param>
void cre_box(int a )   //��������
{
	
	
		for (int i = 0; i < a; i++)
			for (int j = 0; j < a; j++) {
				int x = (j + 1) * INTERVAL + j * BOX_SIZE;
				int y = (i + 1) * INTERVAL + i * BOX_SIZE;
				setfillcolor(RGB(250, 193, 180));//���ø�����ɫ
				solidrectangle(x, y+80, x + BOX_SIZE, y + BOX_SIZE+80);
				settextstyle(40, 0,"����");//���ָ�ʽ
				setbkmode(1);//���ֱ�����ɫ͸��
				char str[10]= "";//��int ת����char
				sprintf_s(str, "%d", map[i][j]); 
				//ʹ���־��ڸ��ӵ��м�
				int th = textheight(str);
				int tw = textwidth(str);
				int x_temp = (80 - tw) / 2;
				int y_temp = (80 - th) / 2;
				if (map[i][j] != 0) {
					outtextxy(x + x_temp, y + y_temp+80, str);
					
				}// �������ڸ�������ʾ

				
			}
}
/// <summary>
/// ���������
/// </summary>
/// <returns>2��4</returns>
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
/// ����������뵽����
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
/// ��ͼ�α�ʾ��ʷ��ߣ�
/// </summary>
void max_score()
{
	char cf[15] = { "Highest score:" };
	settextstyle(30, 0, "����");//���ָ�ʽ
	outtextxy(5,5, cf);
}
