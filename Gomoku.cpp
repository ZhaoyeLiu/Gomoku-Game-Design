#include <iostream>
#include <windows.h>
using namespace std;
const int N=15;
class Gobang;
class Player
{
	private:
		int a[N][N];
	public:
		Player()
		{
			int i,j;
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
					a[i][j]=0;
		}
		friend Gobang;
};
class Gobang
{
	private:
		Player p1,p2;
		static int scorep1;
		static int scorep2;
	public:
		Gobang()
		{}
		void play();
		void recreatetable();
		int judgewin();
};
void pos(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	HANDLE hOutPut;
    hOutPut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutPut,coord);
}
void createtable()//初始化棋盘 
{
	int i,j;
	for(i=27;i<=85;i=i+4)
	for(j=3;j<=33;j=j+2)
	{
		pos(i,j);
		cout<<"_";
		pos(i,j);
		cout<<"_";
	}
	for(i=27;i<=85;i=i+4)
	{
		pos(i,2);
		cout<<(i-23)/4;
	}
	for(i=4;i<34;i++)
	for(j=25;j<=85;j=j+4)
	{
		pos(j,i);
		cout<<"|";
		pos(j,i);
		cout<<"|";
	}
	for(j=4;j<=33;j=j+2)
	{
		pos(23,j);
		cout<<(j-1)/2;
	}
}
void Gobang::recreatetable()//重新打印棋盘 
{
	createtable();
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(p1.a[i][j]==1)
			{
				pos(4*(i+1)+23,2*(j+1)+3);
				cout<<"●";
			}
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(p2.a[i][j]==1)
			{
				pos(4*(i+1)+23,2*(j+1)+3);
				cout<<"Ο";
			}
	pos(87,7);
	cout<<"The number of P1's game winning:"<<scorep1;
	pos(87,11);
	cout<<"The number of P2's game winning:"<<scorep2;
}
int Gobang::judgewin()//判断某方胜利 
{
	int i,j,judge=0;
	for(i=0;i<10;i++)
		for(j=0;j<N;j++)
		if(p1.a[i][j]==1&&p1.a[i+1][j]==1&&p1.a[i+2][j]==1&&p1.a[i+3][j]==1&&p1.a[i+4][j]==1) 
		{
			judge=1;
		}
	for(i=0;i<N;i++)
		for(j=0;j<10;j++)
		if(p1.a[i][j]==1&&p1.a[i][j+1]==1&&p1.a[i][j+2]==1&&p1.a[i][j+3]==1&&p1.a[i][j+4]==1) 
		{
			judge=1;
		}
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		if(p1.a[i][j]==1&&p1.a[i+1][j+1]==1&&p1.a[i+2][j+2]==1&&p1.a[i+3][j+3]==1&&p1.a[i+4][j+4]==1) 
		{
			judge=1;
		}
	for(i=0;i<10;i++)
		for(j=0;j<N;j++)
		if(p2.a[i][j]==1&&p2.a[i+1][j]==1&&p2.a[i+2][j]==1&&p2.a[i+3][j]==1&&p2.a[i+4][j]==1) 
		{
			judge=2;
		}
	for(i=0;i<N;i++)
		for(j=0;j<10;j++)
		if(p2.a[i][j]==1&&p2.a[i][j+1]==1&&p2.a[i][j+2]==1&&p2.a[i][j+3]==1&&p2.a[i][j+4]==1) 
		{
			judge=2;
		}
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		if(p2.a[i][j]==1&&p2.a[i+1][j+1]==1&&p2.a[i+2][j+2]==1&&p2.a[i+3][j+3]==1&&p2.a[i+4][j+4]==1) 
		{
			judge=2;
		}
	return judge;
}
void Gobang::play()
{
	here1:
	Gobang t;
	system("cls");
	t.recreatetable();
	int x,y,c;
	while(1)
	{
		here:
		pos(24,35);
		cout<<"P1 input your coordinate:";
		cin>>x>>y;
		if(x<1||x>15||y<1||y>15)
		{
			pos(28,38);
			cout<<"Wrong coordinate!";
			goto here;
		}
		if(t.p1.a[x-1][y-1]==1||t.p2.a[x-1][y-1]==1)
		{
			pos(28,38);
			cout<<"Player 1:The position already has a piece!Input it again!";
			goto here;
		}
		t.p1.a[x-1][y-1]=1;
		system("cls");
		t.recreatetable();
		if(t.judgewin()==1)
		{
			scorep1++;
			system("cls");
			t.recreatetable();
			pos(29,35);
			cout<<"P1 win!";
			pos(29,37);
			cout<<"A game again!-1 Exit-2:";
			cin>>c;
			switch(c)
			{
				case 1:goto here1;
				case 2:break;
			}
		}
		there:
		pos(24,35);
		cout<<"P2 input your coordinate:";
		cin>>x>>y;
		if(x<1||x>15||y<1||y>15)
		{
			pos(28,38);
			cout<<"Wrong coordinate!";
			goto there;
		}
		if(t.p1.a[x-1][y-1]==1||t.p2.a[x-1][y-1]==1)
		{
			pos(28,38);
			cout<<"Player 2:The position already has a piece!Input it again!";
			goto there;
		}
		t.p2.a[x-1][y-1]=1;
		system("cls");
		t.recreatetable();
		if(t.judgewin()==2)
		{
			scorep2++;
			system("cls");
			t.recreatetable();
			pos(29,35);
			cout<<"P2 win!";
			pos(29,37);
			cout<<"A game again!-1 Exit-2:";
			cin>>c;
			switch(c)
			{
				case 1:goto here1;
				case 2:break;
			}
		}
	}
}
int Gobang::scorep1=0;
int Gobang::scorep2=0;
int main()
{
	system("mode con cols=140 lines=60");
	system("color F1");
	createtable();
	Gobang b;
	b.play();
	return 0;
}
