#include<iostream>
#include <iomanip>
#include <queue>
#include<stdlib.h>
using namespace std;

//定義出某一格子中用X,Y兩種方向來表示可能的八種走法 
int fx[] = { 2,1,-1,-2,-2,-1,1,2 };
int fy[] = { -1,-2,-2,-1,1,2,2,1 };

typedef struct
{
	int x, y; //座標
	int number; //序號 
} Point;//取名為point 

Point board[100000][100000];//棋盤中的格子總數，設為十萬讓接受範圍變多 
int n; //棋盤大小
int step = 1; //序號 

void outputResult(int n)//輸出棋盤 
{
	for (int i = 1; i <= n; i++)
	{
		cout << endl << endl << endl ;//空三列讓版面更加清晰 
		for (int j = 1; j <= n; j++)
		{
			cout << setw(3) << board[i][j].number << " ";//字與字間空出3格使版面清晰 (setw)
		}
	}
	cout << endl << endl;
}

bool check(int x, int y)//判斷是否是可走的路 
{
	if (x<1 || y<1 || x>n || y>n || board[x][y].number != 0)
		return false;//若x,y值錯誤則回傳false 
	else
		return true;//若x,y值正確則執行 
}

int nextSteps(int x, int y)//下一位置有多少種走法

{
	int steps = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (check(x + fx[i], y + fy[i]))//若成功則執行增加step 
			steps++;
	}
	return steps;
}

void Run(Point point)
{
	queue<Point> pointQueue;//做出一個Queue 
	pointQueue.push(point);

	Point top;
	

	while (!pointQueue.empty())//將走的路徑記錄下來
	{
		top = pointQueue.front();
		pointQueue.pop();

		board[top.x][top.y].number = step;
		step++;
		int minStep = 8;//判斷最少步數 

		int f= 0;//為了後面能判斷 

		for (int i = 0; i<8; i++) //出下一位置走法最少的進入隊列
		{
			int x = top.x + fx[i];
			int y = top.y + fy[i];

			if (check(x, y))
			{
				if (nextSteps(x, y) <= minStep)
				{
					minStep = nextSteps(x, y);//將最少步數更新為新的 minstep

					Point t;//做出一個structure來儲存執行的x,ym 
					t.x = x;
					t.y = y;

					if (f)//當minstep=0時到此判斷，代表走到死路無法繼續走，因此將資料pop出來 
						pointQueue.pop();

					pointQueue.push(t);//若能執行則push至Queue中 
					f = 1;
				}
			}
		}
	}
}

int main()
{
	cout << "Please enter the chess board size:";
	cin >> n;
	Point startPoint;
	startPoint.x = 1;//定義出起始位置 
	startPoint.y = 1;
	Run(startPoint);
	outputResult(n);//輸出結果 
	system("pause");
	return 0;
}
