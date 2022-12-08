#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include"claim.h"
#define BOXSIZE 80  //格子大小	
#define INTERVAL 12  //格子间隔
extern int cbSize;
extern int map[10][10];
extern int preMap1[10][10];
extern int preMap2[10][10];
extern char username[11];
extern int count;
/// <summary>
/// 格子向上移动
/// </summary>
void moveUp()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cbSize; begin++)
		{
			if (map[begin][i] != 0)//找到需要移动的格子
			{
				if (map[temp][i] == 0)//上方格子为空
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])//上方格子有相同数字
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp++;
				}
				else //上方有格子数字不同
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
/// 格子向下移动
/// </summary>
void moveDown()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = cbSize - 1;
		for (int begin = cbSize - 2; begin >= 0; begin--)
		{
			if (map[begin][i] != 0)//找到需要移动的格子
			{
				if (map[temp][i] == 0)//下方格子为空
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])//下方格子有相同数字
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp--;
				}
				else//下方有格子数字不同
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
/// 格子向左移动
/// </summary>
void moveLeft()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cbSize; begin++)
		{
			if (map[i][begin] != 0)//找到需要移动的格子
			{
				if (map[i][temp] == 0)//左方格子为空
				{
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])//左方格子有相同数字
				{
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					temp++;
				}
				else//左方有格子数字不同
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
/// 格子向右移动
/// </summary>
void moveRight()
{

	for (int i = 0; i < cbSize; i++)
	{
		int temp = cbSize - 1;
		for (int begin = cbSize - 2; begin >= 0; begin--)
		{
			if (map[i][begin] != 0)//找到需要移动的格子
			{
				if (map[i][temp] == 0)//右方格子为空
				{
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])//右方格子有相同数字
				{
					map[i][temp] += map[i][begin];
					map[i][begin] = 0;
					temp--;
				}
				else//右方有格子数字不同
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
/// 按键操作
/// </summary>
/// <returns>1或0，wasd操作返回1，其他操作返回0</returns>
void saveGame();//声明readKey中将要用到的自定义函数
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
		initgraph((cbSize + 1) * INTERVAL + cbSize * BOXSIZE, (cbSize + 1) * INTERVAL + cbSize * BOXSIZE + 200);
		return 0;
		break;
	case'R':
	case'r':
		if (count % 2 == 0)
			memcpy(map, preMap1, sizeof(int) * 100);
		else memcpy(map, preMap2, sizeof(int) * 100);
		creBox(cbSize);
		return 0;
	}
	return 0;
}

/// <summary>
/// 保存游戏存档
/// </summary>
void saveGame()
{
	FILE* save = fopen("save.txt", "wb");
	if (save == NULL)
	{
		printf("文件错误\n");
	}
	else
	{
		fwrite(username, sizeof(char), 11, save);
		fwrite(&cbSize, sizeof(int), 1, save);
		int sum = cbSize * 10;
		fwrite(map, sizeof(int), sum, save);
		fclose(save);
		initgraph(300, 200);
		char str[10] = "已保存";
		settextstyle(40, 30, "华文琥珀");
		outtextxy(50, 75, str);
		Sleep(2000);
		closegraph();
	}
	
}

/// <summary>
/// 加载存档
/// </summary>
void loadSave()
{
	FILE* save = fopen("save.txt", "rb");
	if (save == NULL)
	{
		printf("文件丢失\n");
		exit(1);
	}
	else
	{
		fread(username, sizeof(char), 11, save);
		fread(&cbSize, sizeof(int), 1, save);
		int sum = cbSize * 10;
		fread(map, sizeof(int), sum, save);
		fclose(save);
	}
}

/// <summary>
/// 保存用户名及分数
/// </summary>
/// <param name="score">分数</param>
void saveScore(int score)
{
	FILE* fscore = fopen("score.txt", "wb");
	if (fscore == NULL)
	{
		printf("文件丢失\n");
		exit(1);
	}
	else 
	{
		fwrite(username, sizeof(char), 11, fscore);
		fwrite(&score, sizeof(int), 1, fscore);
		fclose(fscore);
	}
}
/// <summary>
/// 加载分数
/// </summary>
/// <param name="preUsername">前用户名的首地址</param>
/// <returns>保存的最高分</returns>
int loadScore(char* preUsername)
{
	int score;
	FILE* fscore = fopen("score.txt", "rb");
	if (fscore == NULL)
	{
		printf("文件错误或初次运行\n已创建新的score文件\n");
		FILE* fscore = fopen("score.txt", "wb");
		fclose(fscore);
	}
	else
	{
		fread(preUsername, sizeof(char), 11, fscore);
		fread(&score, sizeof(int), 1, fscore);
		fclose(fscore);
		return score;
	}
}

