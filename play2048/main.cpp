#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int map[10][10];//װ�������ݵĶ�ά����
int cb_size;//���̴�С
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
				printf("������ÿ�ߵĸ�������2��9����");
				scanf("%d", &cb_size);
				while ((trash = getchar()) != '\n');//������뻺����
				if (cb_size < 2 || cb_size > 9)
				{
					printf("�������,");
				}
				else break;
			}
			break;
		}

		else if (order == 2)
		{
			printf("�浵ϵͳ��û������");
			return 0;

		}
		else printf("�������\n");
	}



	
	//���ƽ���
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE+120);
	while (1)
	{
	
		cre_box(cb_size);//��������
	
		if (read_key())//��������
		input_number(cb_size);//����������뵽����
		score_a(cb_size);//��ͼ�ν���ʵʱ��ʾ����
		max_score();//��ʾ��߷�
	for(int i=0;i<cb_size;i++)
		for (int j = 0; j < cb_size; j++) {
			if (map[i][j] == 2048) {
				return 0;
			}
		}
	}
	system("PAUSE");//��ͣ���棬���ڹ۲�



	closegraph();
    return 0;
}
