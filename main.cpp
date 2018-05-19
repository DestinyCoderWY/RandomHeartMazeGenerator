#include<iostream>
#include <windows.h>  
#include<stdlib.h>
#include<time.h>
#include<string>
#include <cstring>

using namespace std;

//author ����
bool SetConsoleColor(WORD forceGroundColor, WORD backGroundColor)

{
	// ��û������������������ѡ��һ������ֵ�� 
	//// STD_INPUT_HANDLE            ��׼����ľ�� 
	//// STD_OUTPUT_HANDLE            ��׼����ľ�� 
	//// STD_ERROR_HANDLE`            ��׼����ľ�� 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle == 0)
		return false;

	//���ù���С
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(handle, &cci);

	//�����ı���������ɫ�� 
	BOOL ret = SetConsoleTextAttribute(handle, forceGroundColor | backGroundColor);
	return(ret == TRUE);
}

int main(void)
{
	//���νṹ��� 0Ϊ�����ӡ�� 1Ϊ�߽� 2��3Ϊ����ɳ���ͨ����  ����ʼ��Ϊ2��3Ϊ��2��2֮�伤���ͨ�� ��֮��Ȼ
	//4��5Ϊ�Ѽ����ӡͨ�� 6Ϊ�Ѽ����ӡ�߽� 7Ϊ�Ѵ�ӡǽ�� 8Ϊ�������ڴ� 9Ϊ��Ҫ�����ӡ��ǽ��
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

	//���ó��������в���������2��3ͨ��
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

	//��������������
	DWORD t_start, t_end;
	t_start = GetTickCount();//�Ӳ���ϵͳ������������elapsed���ĺ����������ķ���ֵ��DWORD��  
	t_end = GetTickCount();

	srand(t_end-t_start);
	int ma = 2;
	t_end = GetTickCount();
	srand(t_end - t_start);
	int na = 9;


	int init = heart[ma][na];//��ʼ�Թ�ͨ��������(ma,na)��ֵ ����ʼ��Ϊ2 ��3��Ϊ��2��2֮�伤���ͨ�� ��֮��Ȼ
	heart[ma][na] = 4;
	

	while (true)
	{
		bool mutey = true;//ͨ���˱����˽��Ƿ���ʣ��ɼ���ͨ��
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE, NULL);//������ɫ

		for (int i = 0; i < 39; i++)//��ӡ���
		{
			for (int j = 0; j < 45; j++)
			{
				if (heart[i][j] == 4 || heart[i][j] == 5)
				{
					if (heart[i+1][j] == 2 || heart[i+1][j] == 3)//��ӡǽ��
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i+1 });
						cout<< ("��");
					}
					if (heart[i -1][j] == 2 || heart[i -1][j] == 3)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i-1 });
						cout << ("��");
					}
					if (heart[i ][j+1] == 2 || heart[i ][j+1] == 3)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(j+1) * 2,(short)i });
						cout << ("��");
					}
					if (heart[i ][j-1] == 2 || heart[i][j-1] == 3)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(j-1) * 2,(short)i });
						cout << ("��");
					}
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j*2,(short)i });
					cout<< ("  ");//��ӡͨ��
				}
			}
		}

		int i = ma;
		int j = na;
		if (i == ma&&j == na)//�ҵ��յ����촦 �������յ����촦�ж��Ƿ���Χ��ͬ���ͣ�Ʃ���ʼΪ2���ҵ���Χ���ڵ�2������ͨ����ͨ��
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

		if (mutey)//�����յ������촦 ��������һ��ͨ����ʼ����  ��Χ��ͬ���ͣ�Ʃ���ʼΪ2���ҵ���Χ���ڵ�2������ͨ����ͨ����ͬ����ͨ��
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
						if (heart[i][j] == 4)//4���ѱ������ͨ���ڵ� 5���ѱ����������ͨ��
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
						if (heart[i][j] == 4)//4���ѱ������½�� 5���ѱ�����ĺ���
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
						if (heart[i][j] == 4)//4���ѱ������½�� 5���ѱ�����ĺ���
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
						if (heart[i][j] == 4)//4���ѱ������½�� 5���ѱ�����ĺ���
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

		if (mutey)//û��½�ؿ���
		{
			break;
		}

	}

	for (int i = 0; i < 39; i++)//�����Ѵ�ӡ��½
	{
		for (int j = 0; j < 45; j++)
		{
			if (heart[i][j] == 4 || heart[i][j] == 5)
			{
				if (heart[i + 1][j] == 2 || heart[i + 1][j] == 3)
				{
					heart[i + 1][j] = 7;//7Ϊ�Ѵ�ӡ��½ 9Ϊδ��ӡ��½ ���˵����ԴﵽЧ��
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
	
	//������Ĵ�ӡ���Ѿ���ӡ�������пɴ�ӡͨ· �������������ӡͨ·

	while (true)//��ӡδ��ӡ��½
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

				if (heart[i][j] == 6)//���ǽ��
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("��");
				}
				//ͨ·�Ѵ�ӡ��
				//else if (heart[i][j] == 4 || heart[i][j] == 5)//ͨ·
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("  ");
				//}
				else if (heart[i][j] ==7)//�Ѵ�ӡ��½ǽ��
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("��");
				}
				else if (heart[i][j] == 9)//��δ��ӡ��½ǽ��
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("��");
				}
			}
		}
		if (mutez) break;//û�б�־Ϊ1�ı߽�����Ҫ��ӡ��}
	}

	while (true)//��ӡ���
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

				if (heart[i][j] == 6)//���ǽ��
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
					cout << ("��");
				}
				//��������֮ǰ��ӡ����ͨ·����½ǽ�� �����ٴ�ӡ
				//else if (heart[i][j] == 4 || heart[i][j] == 5)//ͨ·
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("  ");
				//}
				//else if (heart[i][j] == 7)//�Ѵ�ӡ��½ǽ��
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("��");
				//}
				//else if (heart[i][j] == 9)//��δ��ӡ��½ǽ��
				//{
				//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)j * 2,(short)i });
				//	cout << ("��");
				//}
			}
		}
		if (mutez) break;//û�б�־Ϊ1�ı߽�����Ҫ��ӡ��}
	}

	cout << '\n';
	cout << '\n';

	system("Pause");
	return 0;
}
 