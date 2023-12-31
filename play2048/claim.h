#pragma once
#define BOXSIZE 80  //格子大小	
#define INTERVAL 12  //格子间隔

/// <summary>
/// 显示各种参数
/// </summary>
/// <param name="a">格子数cbSize</param>
void pram(int a);

/// <summary>
/// 创建a*a的棋盘
/// </summary>
/// <param name="a">边长</param>
void creBox(int a);

/// <summary>
/// 创建随机数
/// </summary>
/// <returns>2或4</returns>
int creNumber();

/// <summary>
/// 将随机数输入到数组
/// </summary>
void inputNumber(int a);

/// <summary>
/// 格子向上移动
/// </summary>
void moveUp();

/// <summary>
/// 格子向下移动
/// </summary>
void moveDown();

/// <summary>
/// 格子向左移动
/// </summary>
void moveLeft();

/// <summary>
/// 格子向右移动
/// </summary>
void moveRight();

/// <summary>
/// 保存游戏存档
/// </summary>
void saveGame();

/// <summary>
/// 按键操作
/// </summary>
/// <returns>1或0，wasd操作返回1，其他操作返回0</returns>
int readKey();

/// <summary>
/// 加载存档
/// </summary>
void loadSave();

/// <summary>
/// 保存分数
/// </summary>
/// <param name="score">分数</param>
void saveScore(int score);

/// <summary>
/// 加载分数
/// </summary>
/// <param name="preUsername">前用户名的首地址</param>
/// <returns>保存的最高分</returns>
int loadScore(char* preUsername);

/// <summary>
/// 输出赢了界面
/// </summary>
void prWin();

/// <summary>
/// 显示你输了
/// </summary>
void prLost();