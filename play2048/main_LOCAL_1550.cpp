#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
int map[10][10];
#include "�ݶ�.h"
int main()
{
	
	int cb_size;  //���̽����С
	printf("������ÿ�ߵĸ�������");
	scanf("%d", &cb_size);
	input_number();
	//���ƽ���
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);//��������
	system("PAUSE");//��ͣ���棬���ڹ۲�
	closegraph();
    return 0;
}

