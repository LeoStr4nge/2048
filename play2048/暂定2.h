#pragma once
#include <wincrypt.h>
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
	}
	return 0;
}

/// <summary>
/// 保存游戏存档
/// </summary>
void saveGame()
{
	FILE * save = fopen("save.txt", "wb");
	if (save == NULL)
	{
		printf("文件错误\n");
		exit(1);
	}
	else
	{
		int sum = cbSize * cbSize;
		for (int i = 0; i < cbSize; i++)
		{
			for (int j = 0; j < cbSize; j++)
			{
				fwrite(map, sizeof(int), sum, save);
			}
		}
		fclose(save);
	}
}

/// <summary>
/// 加载存档
/// </summary>
void loadSave()
{
	FILE* save = fopen("save.txt", "r");
	if (save == NULL)
	{
		printf("文件错误\n");
		exit(1);
	}
	else
	{
		int sum = cbSize * cbSize;
		for (int i = 0; i < cbSize; i++)
		{
			for (int j = 0; j < cbSize; j++)
			{
				fread(&map[i][j], sizeof(int), sum, save);
			}
		}
		fclose(save);
	}
}