#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include "�ݶ�.h"

int main()
{
	int cb_size;  //���̴�С
	while(1)
	{
		char trash;//����װ������ķǷ��ַ�
		printf("������ÿ�ߵĸ�������2��7����");
		scanf("%d", &cb_size);
		while ((trash = getchar()) != '\n');
		if (cb_size < 2 || cb_size > 7)
			printf("�������,");
		else break;
	}

	//���ƽ���
	initgraph((cb_size + 1) * INTERVAL + cb_size * BOX_SIZE, (cb_size + 1) * INTERVAL + cb_size * BOX_SIZE);
	cre_box(cb_size);//��������
	system("PAUSE");//��ͣ���棬���ڹ۲�
	closegraph();
    return 0;
}
