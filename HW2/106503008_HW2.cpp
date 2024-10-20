#include<iostream>
#include <iomanip>
#include <queue>
#include<stdlib.h>
using namespace std;

//�w�q�X�Y�@��l����X,Y��ؤ�V�Ӫ�ܥi�઺�K�ب��k 
int fx[] = { 2,1,-1,-2,-2,-1,1,2 };
int fy[] = { -1,-2,-2,-1,1,2,2,1 };

typedef struct
{
	int x, y; //�y��
	int number; //�Ǹ� 
} Point;//���W��point 

Point board[100000][100000];//�ѽL������l�`�ơA�]���Q�U�������d���ܦh 
int n; //�ѽL�j�p
int step = 1; //�Ǹ� 

void outputResult(int n)//��X�ѽL 
{
	for (int i = 1; i <= n; i++)
	{
		cout << endl << endl << endl ;//�ŤT�C��������[�M�� 
		for (int j = 1; j <= n; j++)
		{
			cout << setw(3) << board[i][j].number << " ";//�r�P�r���ťX3��Ϫ����M�� (setw)
		}
	}
	cout << endl << endl;
}

bool check(int x, int y)//�P�_�O�_�O�i������ 
{
	if (x<1 || y<1 || x>n || y>n || board[x][y].number != 0)
		return false;//�Yx,y�ȿ��~�h�^��false 
	else
		return true;//�Yx,y�ȥ��T�h���� 
}

int nextSteps(int x, int y)//�U�@��m���h�ֺب��k

{
	int steps = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (check(x + fx[i], y + fy[i]))//�Y���\�h����W�[step 
			steps++;
	}
	return steps;
}

void Run(Point point)
{
	queue<Point> pointQueue;//���X�@��Queue 
	pointQueue.push(point);

	Point top;
	

	while (!pointQueue.empty())//�N�������|�O���U��
	{
		top = pointQueue.front();
		pointQueue.pop();

		board[top.x][top.y].number = step;
		step++;
		int minStep = 8;//�P�_�̤֨B�� 

		int f= 0;//���F�᭱��P�_ 

		for (int i = 0; i<8; i++) //�X�U�@��m���k�̤֪��i�J���C
		{
			int x = top.x + fx[i];
			int y = top.y + fy[i];

			if (check(x, y))
			{
				if (nextSteps(x, y) <= minStep)
				{
					minStep = nextSteps(x, y);//�N�̤֨B�Ƨ�s���s�� minstep

					Point t;//���X�@��structure���x�s���檺x,ym 
					t.x = x;
					t.y = y;

					if (f)//��minstep=0�ɨ즹�P�_�A�N���즺���L�k�~�򨫡A�]���N���pop�X�� 
						pointQueue.pop();

					pointQueue.push(t);//�Y�����hpush��Queue�� 
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
	startPoint.x = 1;//�w�q�X�_�l��m 
	startPoint.y = 1;
	Run(startPoint);
	outputResult(n);//��X���G 
	system("pause");
	return 0;
}
