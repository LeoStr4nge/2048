#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include"claim.h"
int map[10][10];//װ�������ݵĶ�ά����
int preMap1[10][10];//װ�������̵Ķ�ά����
int preMap2[10][10];
int cbSize = 4;//���̴�С��Ĭ��Ϊ4
int count = 0;//��¼��Ϸ�����˼���
char username[11] = { 0 };
typedef struct rank
{
	char names[10];
	int scores[10];
}rank;
int main()
{
	rank rankings;
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
	
	initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE+120);
	int inGame = 1;//��ʾ��һ�����Ϸ�����У�Ĭ��Ϊ1
	int flag = 0;//��ʾ������û�пո�Ĭ��Ϊ0
	while (inGame == 1 )
	{
		creBox(cbSize);//��������
		pram(cbSize);//��ʾ����
		if (readKey())//�жϸ�ָ���Ƿ���Ҫ���������
			inputNumber(cbSize);//����������뵽����
		pram(cbSize);//��ͼ�ν���ʵʱ��ʾ����
		flag = 0;
		if (count % 2 == 0)
			memcpy(preMap1, map, sizeof(int) * 100);
		else memcpy(preMap2, map, sizeof(int) * 100);
		int score = 0;
		for (int i = 0; i < cbSize; i++)
			for (int j = 0; j < cbSize; j++)
				score += map[i][j];
		


	for(int i=0;i<cbSize;i++)
		for (int j = 0; j < cbSize; j++) {
			if (map[i][j] == 2048) {
				creBox(cbSize);
				pram(cbSize);
				prWin();//��ʾ��Ӯ��
				Sleep(3000);
				inGame = 0;
				break;
			}
			else if (map[i][j] == 0)
				flag = 1;
		}
	if (flag == 0)
		{
			creBox(cbSize);
			pram(cbSize);
			//������Ҫһ����ʾ��Ϸ�����ĺ���
			prLost();
			Sleep(3000);
			inGame = 0;
			break;
		}
	count++;
	}
	int score = 0;
	for (int i = 0; i < cbSize; i++)
		for (int j = 0; j < cbSize; j++)
			score += map[i][j];
	//������߷��ж�
	int preScore = 0;
	char preUsername[11] = { 0 };
	preScore = loadScore(preUsername);
	printf("Ŀǰ�����ǣ�%s %d\n", preUsername, preScore);
	if (score > preScore)
		saveScore(score);
	//system("PAUSE");//��ͣ���棬���ڹ۲�
	closegraph();
    return 0;
}
