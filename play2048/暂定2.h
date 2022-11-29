#pragma once
extern int cb_size;
void move_up()
{

	for (int i = 0; i < cb_size; i++)
	{
		int temp = 0;
		for (int begin = 1; begin < cb_size; begin++)
		{
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])
				{
					map[temp][i] += map[begin][i];
					map[begin][i] = 0;
					temp++;
				}
			}
		}
	}
}