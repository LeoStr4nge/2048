#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int map[10][10];//װ�������ݵĶ�ά����
int cbSize;//���̴�С
#include "�ݶ�.h"
#include "�ݶ�2.h"
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
			while (1)//�Զ�������
			{
				printf("������ÿ�ߵĸ�������4��9����");
				scanf("%d", &cbSize);
				while ((trash = getchar()) != '\n');//������뻺����
				if (cbSize < 2 || cbSize > 9)
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



	
	//���ƽ���
	initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE+120);
	int inGame = 1;
	while (inGame == 1 )
	{
	
		creBox(cbSize);//��������
	
		if (readKey())//��������
		inputNumber(cbSize);//����������뵽����
		scoreA(cbSize);//��ͼ�ν���ʵʱ��ʾ����
		maxScore();//��ʾ��߷�
	for(int i=0;i<cbSize;i++)
		for (int j = 0; j < cbSize; j++) {
			if (map[i][j] == 2048) {
				saveGame();
				inGame = 0;
				break;
			}
		}
	}
	system("PAUSE");//��ͣ���棬���ڹ۲�



	closegraph();
    return 0;
}
