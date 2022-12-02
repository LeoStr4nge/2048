#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
extern int cbSize;
extern int map[10][10];
/// <summary>
/// ���������ƶ�
/// </summary>
void moveUp()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cbSize; begin++)
		{
			if (map[begin][i] != 0)//�ҵ���Ҫ�ƶ��ĸ���
			{
				if (map[temp][i] == 0)//�Ϸ�����Ϊ��
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])//�Ϸ���������ͬ����
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp++;
				}
				else //�Ϸ��и������ֲ�ͬ
				{
					map[temp + 1][i] = map[begin][i];
					if (temp + 1 != begin)
					{
						map[begin][i] = 0;
					}
					temp++;
				}
			}
		}
	}
}

/// <summary>
/// ���������ƶ�
/// </summary>
void moveDown()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = cbSize - 1;
		for (int begin = cbSize - 2; begin >= 0; begin--)
		{
			if (map[begin][i] != 0)//�ҵ���Ҫ�ƶ��ĸ���
			{
				if (map[temp][i] == 0)//�·�����Ϊ��
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])//�·���������ͬ����
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp--;
				}
				else//�·��и������ֲ�ͬ
				{
					map[temp - 1][i] = map[begin][i];
					if (temp - 1 != begin)
					{
						map[begin][i] = 0;
					}
					temp--;
				}
			}
		}
	}
}

/// <summary>
/// ���������ƶ�
/// </summary>
void moveLeft()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cbSize; begin++)
		{
			if (map[i][begin] != 0)//�ҵ���Ҫ�ƶ��ĸ���
			{
				if (map[i][temp] == 0)//�󷽸���Ϊ��
				{
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])//�󷽸�������ͬ����
				{
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					temp++;
				}
				else//���и������ֲ�ͬ
				{
					map[i][temp + 1] = map[i][begin];
					if (temp + 1 != begin)
					{
						map[i][begin] = 0;
					}
					temp++;
				}
			}
		}
	}
}

/// <summary>
/// ���������ƶ�
/// </summary>
void moveRight()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = cbSize - 1;
		for (int begin = cbSize - 2; begin >= 0; begin--)
		{
			if (map[i][begin] != 0)//�ҵ���Ҫ�ƶ��ĸ���
			{
				if (map[i][temp] == 0)//�ҷ�����Ϊ��
				{
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])//�ҷ���������ͬ����
				{
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					temp--;
				}
				else//�ҷ��и������ֲ�ͬ
				{
					map[i][temp - 1] = map[i][begin];
					if (temp - 1 != begin)
					{
						map[i][begin] = 0;
					}
					temp--;
				}
			}
		}
	}
}


/// <summary>
/// ��������
/// </summary>
/// <returns>1��0��wasd��������1��������������0</returns>
void saveGame();//����readKey�н�Ҫ�õ����Զ��庯��
int readKey()
{
	char key = _getch();
	switch (key)
	{
	case'w':
	case'W':
		moveUp();
		return 1;
		break;
	case'a':
	case'A':
		moveLeft();
		return 1;
		break;
	case's':
	case'S':
		moveDown();
		return 1;
		break;
	case'd':
	case'D':
		moveRight();
		return 1;
		break;
	case'I':
	case'i':
		saveGame();
		return 0;
		break;
	}
	return 0;
}

/// <summary>
/// ������Ϸ�浵
/// </summary>
void saveGame()
{
	FILE* save = fopen("save.txt", "wb");
	if (save == NULL)
	{
		printf("�ļ�����\n");
		exit(1);
	}
	else
	{
		fwrite(&cbSize, sizeof(int), 1, save);
		int sum = cbSize * 10;
		fwrite(map, sizeof(int), sum, save);
		fclose(save);
	}
}

/// <summary>
/// ���ش浵
/// </summary>
void loadSave()
{
	FILE* save = fopen("save.txt", "rb");
	if (save == NULL)
	{
		printf("�ļ�����\n");
		exit(1);
	}
	else
	{
		fread(&cbSize, sizeof(int), 1, save);
		int sum = cbSize * 10;
		fread(map, sizeof(int), sum, save);
		fclose(save);
	}
}

/// <summary>
/// �������
/// </summary>
/// <param name="score">����</param>
void saveScore(int score)
{
	FILE* fscore = fopen("score.txt", "wb");
	if (fscore == NULL)
	{
		printf("�ļ�����\n");
		exit(1);
	}
	else 
	{
		fwrite(&score, sizeof(int), 1, fscore);
		fclose(fscore);
	}
}
/// <summary>
/// ��ȡ����
/// </summary>
/// <returns>�������ļ���ķ���</returns>
int loadScore()
{
	int score;
	FILE* fscore = fopen("score.txt", "rb");
	if (fscore == NULL)
	{
		printf("�ļ�����\n");
		exit(1);
	}
	else
	{
		fread(&score, sizeof(int), 1, fscore);
		fclose(fscore);
		return score;
	}
}