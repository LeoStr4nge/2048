#pragma once
/// <summary>
/// 格子向上移动
/// </summary>
void move_up()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cb_size; begin++)
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
void move_down()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = cb_size - 1;
		for (int begin = cb_size - 2; begin >= 0; begin--)
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
void move_left()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cb_size; begin++)
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
void move_right()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = cb_size - 1;
		for (int begin = cb_size - 2; begin >= 0; begin--)
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
int read_key()
{
	char key = _getch();
	switch (key)
	{
	case'w':
	case'W':
		move_up();
		return 1;
		break;
	case'a':
	case'A':
		move_left();
		return 1;
		break;
	case's':
	case'S':
		move_down();
		return 1;
		break;
	case'd':
	case'D':
		move_right();
		return 1;
		break;
	}
	return 0;
}