#pragma once
/// <summary>
/// ���������ƶ�
/// </summary>
void move_up()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cb_size; begin++)
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
void move_down()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = cb_size - 1;
		for (int begin = cb_size - 2; begin >= 0; begin--)
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
void move_left()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cb_size; begin++)
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
void move_right()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = cb_size - 1;
		for (int begin = cb_size - 2; begin >= 0; begin--)
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
void read_key()
{
	char key = _getch();
	switch (key)
	{
	case'w':
	case'W':
	case 72:
		move_up();
		break;
	case'a':
	case'A':
	case 75:
		move_left();
		break;
	case's':
	case'S':
	case 80:
		move_down();
		break;
	case'd':
	case'D':
	case 77:
		move_right();
		break;
	}
}