#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
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



	//������Ϸ����
	initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE+120);
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
				inGame = 0;
				break;
			}
		}
	}
	system("PAUSE");//��ͣ���棬���ڹ۲�



	closegraph();
    return 0;
}
