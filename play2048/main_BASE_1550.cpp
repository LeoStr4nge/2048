#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include "�ݶ�.h"

int main()
{
	int cb_size;  //���̴�С
	printf("������ÿ�ߵĸ�������");
	scanf("%d", &cb_size);
	//���ƽ���
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);//��������
	system("PAUSE");//��ͣ���棬���ڹ۲�
	closegraph();
    return 0;
}
