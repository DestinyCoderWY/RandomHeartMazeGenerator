#include<iostream>
#include <windows.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#include <cstring>

using namespace std;

//author 吴岳
bool SetConsoleColor(WORD forceGroundColor, WORD backGroundColor)

{
	// 获得缓冲区句柄。参数可以选择一下三种值：
	//// STD_INPUT_HANDLE            标准输入的句柄
	//// STD_OUTPUT_HANDLE            标准输出的句柄
	//// STD_ERROR_HANDLE`            标准错误的句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle == 0)
		return false;

	//设置光标变小
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(handle, &cci);

	//设置文本及背景颜色。
	BOOL ret = SetConsoleTextAttribute(handle, forceGroundColor | backGroundColor);
	return(ret == TRUE);
}

int main(void)
{
	//心形结构外界 0为不需打印处 1为边界 2，3为交替可出现通道处  若初始定为2则3为被2与2之间激活的通道 反之亦然
	//4，5为已激活打印通道 6为已激活打印边界 7为已打印墙壁 8为入口与出口处 9为将要补足打印的墙壁
	int heart[39][45] =
	{
	{ 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,8,3,2,3,2,3,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,3,2,3,2,3,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,3,2,3,2,3,2,3,1,1,0,0,0,0,0,0,0,0,0,1,1,3,2,3,2,3,2,3,1,1,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,1,1,3,2,3,2,3,2,3,2,3,1,1,0,0,0,0,0,0,0,1,1,3,2,3,2,3,2,3,2,3,1,1,0,0,0,0,0,0},
	{ 0,0,0,0,1,1,2,3,2,3,2,3,2,3,2,3,2,3,2,1,1,0,0,0,1,1,2,3,2,3,2,3,2,3,2,3,2,3,2,1,1,0,0,0,0 },
	{ 0,0,0,1,1,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,1,1,1,1,1,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,1,1,0,0,0 },
	{ 0,0,1,1,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,1,1,0,0 },
	{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 },
	{ 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	};

	//利用长方形阵列补足心形中2，3通道
	int p = 2;
	int inheart[39][45];
	for (int i = 0; i < 39; i++)
	{
		for (int j = 0; j < 45; j++)
		{
			inheart[i][j] = p;
			if (p == 2) p = 3;
			else p = 2;
		}
	}

	bool mutex = false;
	for (int i = 0; i < 39; i++)
	{
		for (int j = 0; j < 45; j++)
		{
			if (heart[i][j] == 1 && j <= 22) mutex = true;
			else if (heart[i][j] == 1 && j > 22) mutex = false;
			if (heart[i][j] == 1)
			{
				;
			}
			else
			{
				if (mutex == true)
				{
					if (i >= 7 && i <= 36)
					{
						heart[i][j] = inheart[i][j];
					}
				}
			}
		}
	}

	//毫秒种子生成器
	DWORD t_start, t_end;
	t_start = GetTickCount();//从操作系统启动所经过（elapsed）的毫秒数，它的返回值是DWORD。
	t_end = GetTickCount();

	srand(t_end-t_start);
	int ma = 2;
	t_end = GetTickCount();
	srand(t_end - t_start);
	int na = 9;


	int init = heart[ma][na];//初始迷宫通道产生点(ma,na)的值 若初始定为2 则3将为被2与2之间激活的通道 反之亦然
	heart[ma][na] = 5;


	while (true)
	{
		bool mutey = true;//通过此变量了解是否还有剩余可激活通道
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE, NULL);//设置颜色

		for (int i = 0; i < 39; i++)//打印结果
		{
			for (int j = 0; j < 45; j++)
			{
				if (heart[i][j] == 4 || heart[i][j] == 5)
				{
					if (heart[i+1][j] == 2 || heart[i+1][j] == 3)//打印墙壁
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i+1 });
						cout<< ("■");
					}
					if (heart[i -1][j] == 2 || heart[i -1][j] == 3)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i-1 });
						cout << ("■");
					}
					if (heart[i ][j+1] == 2 || heart[i ][j+1] == 3)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(j+1) * 2,(short)i });
						cout << ("■");
					}
					if (heart[i ][j-1] == 2 || heart[i][j-1] == 3)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(j-1) * 2,(short)i });
						cout << ("■");
					}
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j*2,(short)i });
					cout<< ("  ");//打印通道
				}
			}
		}

		int i = ma;
		int j = na;
		if (i == ma&&j == na)//找到终点延伸处 并进行终点延伸处判断是否周围有同类型（譬如初始为2即找到周围存在的2来激活通道）通道
		{
			t_end = GetTickCount();
			srand(t_end - t_start);
			int k = rand() % 4;
			if (k == 0)
			{
				if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
				{
					if (mutey)
					{
						heart[i - 2][j] = 4;
						if (heart[i - 1][j] != 1)
						{
							heart[i - 1][j] = 5;
						}
						mutey = false;
						ma = i - 2;
					}
				}
				else if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
				{
					if (mutey)
					{
						heart[i + 2][j] = 4;
						if (heart[i + 1][j] != 1)
						{
							heart[i + 1][j] = 5;
						}
						mutey = false;
						ma = i + 2;
					}
				}
				else if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
				{
					if (mutey)
					{
						heart[i][j - 2] = 4;
						if (heart[i][j-1] != 1)
						{
							heart[i][j - 1] = 5;
						}
						mutey = false;
						na = j - 2;
					}
				}
				else if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
				{
					if (mutey)
					{
						heart[i][j + 2] = 4;
						if (heart[i][j+1] != 1)
						{
							heart[i][j + 1] = 5;
						}
						mutey = false;
						na = j + 2;
					}
				}
			}
			else if (k == 1)
			{
				if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
				{
					if (mutey)
					{
						heart[i][j - 2] = 4;
						if (heart[i ][j-1] != 1)
						{
							heart[i][j - 1] = 5;
						}
						mutey = false;
						na = j - 2;
					}
				}
				else if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
				{
					if (mutey)
					{
						heart[i - 2][j] = 4;
						if (heart[i- 1][j] != 1)
						{
							heart[i - 1][j] = 5;
						}
						mutey = false;
						ma = i - 2;
					}
				}
				else if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
				{
					if (mutey)
					{
						heart[i + 2][j] = 4;
						if (heart[i + 1][j] != 1)
						{
							heart[i + 1][j] = 5;
						}
						mutey = false;
						ma = i + 2;
					}
				}
				else if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
				{
					if (mutey)
					{
						heart[i][j + 2] = 4;
						if (heart[i ][j+1] != 1)
						{
							heart[i][j + 1] = 5;
						}
						mutey = false;
						na = j + 2;
					}
				}
			}
			else if (k == 2)
			{
				if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
				{
					if (mutey)
					{
						heart[i][j + 2] = 4;
						if (heart[i][j+1] != 1)
						{
							heart[i][j + 1] = 5;
						}
						mutey = false;
						na = j + 2;
					}
				}
				else if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
				{
					if (mutey)
					{
						heart[i][j - 2] = 4;
						if (heart[i ][j-1] != 1)
						{
							heart[i][j - 1] = 5;
						}
						mutey = false;
						na = j - 2;
					}
				}
				else if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
				{
					if (mutey)
					{
						heart[i + 2][j] = 4;
						if (heart[i + 1][j] != 1)
						{
							heart[i + 1][j] = 5;
						}
						mutey = false;
						ma = i + 2;
					}
				}
				else if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
				{
					if (mutey)
					{
						heart[i - 2][j] = 4;
						if (heart[i - 1][j] != 1)
						{
							heart[i - 1][j] = 5;
						}
						mutey = false;
						ma = i - 2;
					}
				}
			}
			else if (k == 3)
			{
				if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
				{
					if (mutey)
					{
						heart[i][j + 2] = 4;
						if (heart[i][j+1] != 1)
						{
							heart[i][j + 1] = 5;
						}
						mutey = false;
						na = j + 2;
					}
				}
				else if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
				{
					if (mutey)
					{
						heart[i - 2][j] = 4;
						if (heart[i - 1][j] != 1)
						{
							heart[i - 1][j] = 5;
						}
						mutey = false;
						ma = i - 2;
					}
				}
				else if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
				{
					if (mutey)
					{
						heart[i + 2][j] = 4;
						if (heart[i + 1][j] != 1)
						{
							heart[i + 1][j] = 5;
						}
						mutey = false;
						ma = i + 2;
					}
				}
				else if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
				{
					if (mutey)
					{
						heart[i][j - 2] = 4;
						if (heart[i][j-1] != 1)
						{
							heart[i][j - 1] = 5;
						}
						mutey = false;
						na = j - 2;
					}
				}
			}
		}

		if (mutey)//倘若终点无延伸处 则任意找一个通道开始延伸  周围有同类型（譬如初始为2即找到周围存在的2来激活通道）通道的同类型通道
		{
			for (int i = 0; i < 39; i++)
			{
				for (int j = 0; j < 45; j++)
				{
					t_end = GetTickCount();
					srand(t_end - t_start);
					int k = rand() % 4;
					if (k == 0)
					{
						if (heart[i][j] == 4)//4是已被激活的通道节点 5是已被激活的连接通道
						{
							if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
							{
								if (mutey)
								{
									heart[i - 2][j] = 4;
									if (heart[i - 1][j] != 1)
									{
										heart[i - 1][j] = 5;
									}
									mutey = false;
									ma = i - 2;
									na = j;
								}
							}
							else if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
							{
								if (mutey)
								{
									heart[i + 2][j] = 4;
									if (heart[i + 1][j] != 1)
									{
										heart[i + 1][j] = 5;
									}
									mutey = false;
									ma = i + 2;
									na = j;
								}
							}
							else if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
							{
								if (mutey)
								{
									heart[i][j - 2] = 4;
									if (heart[i][j-1] != 1)
									{
										heart[i][j - 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j - 2;
								}
							}
							else if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
							{
								if (mutey)
								{
									heart[i][j + 2] = 4;
									if (heart[i ][j+1] != 1)
									{
										heart[i][j + 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j + 2;
								}
							}
						}
					}
					else if (k == 1)
					{
						if (heart[i][j] == 4)//4是已被激活的陆地 5是已被激活的海洋
						{
							if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
							{
								if (mutey)
								{
									heart[i + 2][j] = 4;
									if (heart[i + 1][j] != 1)
									{
										heart[i + 1][j] = 5;
									}
									mutey = false;
									ma = i + 2;
									na = j;
								}
							}
							else if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
							{
								if (mutey)
								{
									heart[i][j - 2] = 4;
									if (heart[i ][j-1] != 1)
									{
										heart[i][j - 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j - 2;
								}
							}
							else if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
							{
								if (mutey)
								{
									heart[i - 2][j] = 4;
									if (heart[i -1][j] != 1)
									{
										heart[i- 1][j] = 5;
									}
									mutey = false;
									ma = i - 2;
									na = j;
								}
							}

							else if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
							{
								if (mutey)
								{
									heart[i][j + 2] = 4;
									if (heart[i ][j+1] != 1)
									{
										heart[i][j + 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j + 2;
								}
							}
						}
					}
					else if (k == 2)
					{
						if (heart[i][j] == 4)//4是已被激活的陆地 5是已被激活的海洋
						{
							if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
							{
								if (mutey)
								{
									heart[i][j + 2] = 4;
									if (heart[i][j+1] != 1)
									{
										heart[i][j + 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j + 2;
								}
							}
							else if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
							{
								if (mutey)
								{
									heart[i + 2][j] = 4;
									if (heart[i + 1][j] != 1)
									{
										heart[i + 1][j] = 5;
									}
									mutey = false;
									ma = i + 2;
									na = j;
								}
							}
							else if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
							{
								if (mutey)
								{
									heart[i - 2][j] = 4;
									if (heart[i - 1][j] != 1)
									{
										heart[i - 1][j] = 5;
									}
									mutey = false;
									ma = i - 2;
									na = j;
								}
							}
							else if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
							{
								if (mutey)
								{
									heart[i][j - 2] = 4;
									if (heart[i ][j-1] != 1)
									{
										heart[i][j - 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j - 2;
								}
							}

						}
					}
					else if (k ==3)
					{
						if (heart[i][j] == 4)//4是已被激活的陆地 5是已被激活的海洋
						{
							if (i - 2 >= 0 && (heart[i - 2][j] == init || heart[i - 2][j] == 8))
							{
								if (mutey)
								{
									heart[i - 2][j] = 4;
									if (heart[i - 1][j] != 1)
									{
										heart[i - 1][j] = 5;
									}
									mutey = false;
									ma = i - 2;
									na = j;
								}
							}
							else if (j + 2 < 45 && (heart[i][j + 2] == init || heart[i][j + 2] == 8))
							{
								if (mutey)
								{
									heart[i][j + 2] = 4;
									if (heart[i ][j+1] != 1)
									{
										heart[i][j + 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j + 2;
								}
							}
							else if (i + 2 < 39 && (heart[i + 2][j] == init || heart[i + 2][j] == 8))
							{
								if (mutey)
								{
									heart[i + 2][j] = 4;
									if (heart[i + 1][j] != 1)
									{
										heart[i + 1][j] = 5;
									}
									mutey = false;
									ma = i + 2;
									na = j;
								}
							}
							else if (j - 2 >= 0 && (heart[i][j - 2] == init || heart[i][j - 2] == 8))
							{
								if (mutey)
								{
									heart[i][j - 2] = 4;
									if (heart[i][j - 1] != 1)
									{
										heart[i][j - 1] = 5;
									}
									mutey = false;
									ma = i;
									na = j - 2;
								}
							}
						}
					}
				}
			}
		}

		if (mutey)//没有陆地可走
		{
			break;
		}

	}

	for (int i = 0; i < 39; i++)//设置已打印内陆
	{
		for (int j = 0; j < 45; j++)
		{
			if (heart[i][j] == 4 || heart[i][j] == 5)
			{
				if (heart[i + 1][j] == 2 || heart[i + 1][j] == 3)
				{
					heart[i + 1][j] = 7;//7为已打印内陆 9为未打印内陆 依此递增以达到效果
				}
				if (heart[i - 1][j] == 2 || heart[i - 1][j] == 3)
				{
					heart[i - 1][j] = 7;
				}
				if (heart[i][j + 1] == 2 || heart[i][j + 1] == 3)
				{
					heart[i][j + 1] = 7;
				}
				if (heart[i][j - 1] == 2 || heart[i][j - 1] == 3)
				{
					heart[i][j - 1] = 7;
				}
			}
		}
	}

	//在上面的打印中已经打印过了所有可打印通路 所以下面无需打印通路

	while (true)//打印未打印内陆
	{
		bool mutez = true;
		for (int i = 0; i < 39; i++)
		{
			for (int j = 0; j < 45; j++)
			{
				if (mutez&&(heart[i][j] == 2 || heart[i][j] == 3))
				{
					heart[i][j] = 9;
					mutez = false;
				}

				if (heart[i][j] == 6)//外界墙壁
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("■");
				}
				//通路已打印过
				//else if (heart[i][j] == 4 || heart[i][j] == 5)//通路
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("  ");
				//}
				else if (heart[i][j] ==7)//已打印内陆墙壁
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("■");
				}
				else if (heart[i][j] == 9)//新未打印内陆墙壁
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("■");
				}
			}
		}
		if (mutez) break;//没有标志为1的边界物需要打印了}
	}

	while (true)//打印外界
	{
		bool mutez = true;
		for (int i = 0; i < 39; i++)
		{
			for (int j = 0; j < 45; j++)
			{
				if (mutez&&heart[i][j] == 1)
				{
					heart[i][j] = 6;
					mutez = false;
				}

				if (heart[i][j] == 6)//外界墙壁
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("■");
				}
				//下面由于之前打印过了通路和内陆墙壁 无需再打印
				//else if (heart[i][j] == 4 || heart[i][j] == 5)//通路
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("  ");
				//}
				//else if (heart[i][j] == 7)//已打印内陆墙壁
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("■");
				//}
				//else if (heart[i][j] == 9)//新未打印内陆墙壁
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("■");
				//}
			}
		}
		if (mutez) break;//没有标志为1的边界物需要打印了}
	}

	cout << '\n';
	cout << '\n';

	system("Pause");
	return 0;
}
