#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"claim.h"
int map[10][10];//װ�������ݵĶ�ά����
int cbSize = 4;//���̴�С��Ĭ��Ϊ4
int main()
{
	int order;//�˵��������������
	char trash;//����װ������ķǷ��ַ�
	printf("��ӭ����2048\n");
	while (1)
	{
		printf("����1�Կ�ʼ����Ϸ\n����2�Լ�����Ϸ\n");
		scanf("%d", &order);
		while ((trash = getchar()) != '\n');//���������������


		if (order == 1)
		{
			while (1)//�Զ�������
			{
				printf("������ÿ�ߵĸ�������4��9����");
				scanf("%d", &cbSize);
				while ((trash = getchar()) != '\n');//���������������
				if (cbSize < 4 || cbSize > 9)
				{
					printf("�������,");
				}
				else break;
			}
			break;
		}

		else if (order == 2)
		{
			loadSave();
			break;
		}
		else printf("�������\n");
	}

	initgraph(600, 250);
	char str1[200] = { "���Ʋ�����Ϸ���ܾ�������Ϸ." };
	char str2[200] = "ע�����ұ�����������ƭ�ϵ�.";
	char str3[200] = "�ʶ���Ϸ���ԣ�������Ϸ����.";
	char str4[200] = "������ʱ�䣬���ܽ�������.";
	settextstyle(40, 20, "����");


	outtextxy(20, 20, str1);
	outtextxy(20, 80, str2);
	outtextxy(20, 140, str3);
	outtextxy(20, 200, str4);
		

	system("PAUSE");
	//������Ϸ����
	
	initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE+200);
	int inGame = 1;//��ʾ��һ�����Ϸ�����У�Ĭ��Ϊ1
	
	while (inGame == 1 )
	{
		creBox(cbSize);//��������
	
		if (readKey())//�жϸ�ָ���Ƿ���Ҫ���������
			inputNumber(cbSize);//����������뵽����
		else break;
		scoreA(cbSize);//��ͼ�ν���ʵʱ��ʾ����
		maxScore();//��ʾ��߷�
	for(int i=0;i<cbSize;i++)
		for (int j = 0; j < cbSize; j++) {
			if (map[i][j] == 2048) {

				//������Ҫһ������ʾ����Ӯ�ˡ���ͼ�κ���
				prWin();
				inGame = 0;
				break;
			}
		}
	}
	system("PAUSE");//��ͣ���棬���ڹ۲�



	closegraph();
    return 0;
}
