#pragma once
#define BOX_SIZE 100  //���Ӵ�С	
#define INTERVAL 15  //���Ӽ��

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
			solidrectangle(x, y, x + BOX_SIZE, y + BOX_SIZE);
			settextstyle(50, 0,"����");//���ָ�ʽ
			setbkmode(1);//���ֱ�����ɫ͸��
			char str[10]= "";//��int ת����char
			sprintf_s(str, "%d", map[i][j]); 
			//ʹ���־��ڸ��ӵ��м�
			int th=textheight(str);
			int tw = textwidth(str);
			int x_temp = (100 - tw) / 2;
			int y_temp = (100 - th) / 2;
			if (map[i][j] != 0) {
				outtextxy(x + x_temp, y + y_temp, str);
			}// �������ڸ�������ʾ
		}
}
/// <summary>
/// ���������
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
/// ����������뵽����
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
/// <summary>
/// ��¼����
/// </summary>
void record_score(int a)
{
	int  score=0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++) {
			score = score + map[i][j];
		}

	
}
