#pragma once
#define BOXSIZE 80  //���Ӵ�С	
#define INTERVAL 12  //���Ӽ��

/// <summary>
/// ��ͼ�ν�����ʾʵʱ����
/// </summary>
/// <param name="a">������cbSize</param>
void scoreA(int a);

/// <summary>
/// ����a*a������
/// </summary>
/// <param name="a">�߳�</param>
void creBox(int a);

/// <summary>
/// ���������
/// </summary>
/// <returns>2��4</returns>
int creNumber();

/// <summary>
/// ����������뵽����
/// </summary>
void inputNumber(int a);

/// <summary>
/// ��ͼ�α�ʾ��ʷ��ߣ�
/// </summary>
void maxScore();

/// <summary>
/// ���������ƶ�
/// </summary>
void moveUp();

/// <summary>
/// ���������ƶ�
/// </summary>
void moveDown();

/// <summary>
/// ���������ƶ�
/// </summary>
void moveLeft();

/// <summary>
/// ���������ƶ�
/// </summary>
void moveRight();

/// <summary>
/// ������Ϸ�浵
/// </summary>
void saveGame();

/// <summary>
/// ��������
/// </summary>
/// <returns>1��0��wasd��������1��������������0</returns>
int readKey();

/// <summary>
/// ���ش浵
/// </summary>
void loadSave();
