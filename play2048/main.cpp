#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"claim.h"
int map[10][10];//װ�������ݵĶ�ά����
int cbSize = 4;//���̴�С��Ĭ��Ϊ4
char username[11] = { 0 };
int main()
{
	int order;//�˵��������������
	char trash;//����װ������ķǷ��ַ�
	printf("��ӭ����2048\n");
	while (1)
	{
		printf("����1�Կ�ʼ����Ϸ\n����2�Լ�����Ϸ\n");
		scanf("%d", &order);
		while ((trash = getchar()) != '\n');//������뻺����

		if (order == 1)
		{
			while (1)
			{
				printf("�������û�����");
				scanf("%s", &username);
				while ((trash = getchar()) != '\n');
				printf("�û���Ϊ��%s\n", username);
				if (username[10] != 0)
					printf("�û������������10����\n");
				else break;
			}
			while (1)
			{
				
				printf("������ÿ�ߵĸ�������4��9����");
				scanf("%d", &cbSize);
				while ((trash = getchar()) != '\n');
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
			printf("�Ͼ����Ϊ��%s", username);
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
	Sleep(3000);
	
	//������Ϸ����
	
	initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE+200);
	int inGame = 1;//��ʾ��һ�����Ϸ�����У�Ĭ��Ϊ1
	int flag = 0;//��ʾ������û�пո�Ĭ��Ϊ0
	while (inGame == 1 )
	{
		creBox(cbSize);//��������
		scoreA(cbSize);//��ʾ����
		if (readKey())//�жϸ�ָ���Ƿ���Ҫ���������
			inputNumber(cbSize);//����������뵽����
		scoreA(cbSize);//��ͼ�ν���ʵʱ��ʾ����
	 	maxScore();//��ʾ��߷�
		flag = 0;
	for(int i=0;i<cbSize;i++)
		for (int j = 0; j < cbSize; j++) {
			if (map[i][j] == 2048) {
				creBox(cbSize);
				scoreA(cbSize);
				prWin();//��ʾ��Ӯ��
				inGame = 0;
				break;
			}
			else if (map[i][j] == 0)
				flag = 1;
		}
	if (flag == 0)
		{
			creBox(cbSize);
			scoreA(cbSize);
			//������Ҫһ����ʾ��Ϸ�����ĺ���
			inGame = 0;
			break;
		}
	
	}
	system("PAUSE");//��ͣ���棬���ڹ۲�



	closegraph();
    return 0;
}
