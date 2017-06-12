#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#define uint unsigned int
#define uchar unsigned char
using namespace std;
class cleanbomb
{
public:
	 cleanbomb(uint s)
	{
		bn=s*s/4;
		size=s-1;
	}
	 ~cleanbomb(){};
	void game();
	void newcap();
private:
	uint bn;
	uint size;
	uint a[30][30];
	uint b[30][30];
	void delay(uint t);
	void display();
};
void cleanbomb::delay(uint t)
{
    uint i,j,k;
    for(i=0;i<=t;i++)
    {
        for(j=0;j<=10000;j++)
        {
            for(k=0;k<=1000;k++);
        }
    }
}
void cleanbomb::display()
{
	uint i,j;
	uchar xianshi_1[13][4]={"  ","¡ñ","¡ï","¡ö","¡õ"," 1"," 2"," 3"," 4"," 5"," 6"," 7"," 8"};
	cout<<"welcome to clean the bomb"<<endl;
	cout<<"use the keys W/S/A/D to move"<<endl;
	cout<<"use J to open"<<endl;
	cout<<"use K to sign the bomb"<<endl;
	cout<<"use Q to quit the game"<<endl;
    for(j=0;j<=size;j++)
    {
        for(i=0;i<=size;i++)
        {
            cout<<xianshi_1[b[j][i]];
        }
        cout<<"\n";
    }
}
void cleanbomb::game()
{
	uint i,j,tx[100],ty[100],bomb=0;
	uint ti,tj,tp=1,tn;
	uint x=0,y=0,lx=0,ly=0;
	uchar enter='B';
	uint n=size;
	uint c[30][30];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			b[i][j]=3;
			c[i][j]=3;
		}
	}
	while(enter!='Q')
	{
		system("cls");
		b[ly][lx]=c[ly][lx];
		b[y][x]=4;
		display();
		lx=x;
		ly=y;
		char cin=getch();
		enter=cin;
		if(enter=='W')
		{
			if(y-1>=0)y--;
		}
		if(enter=='S')
		{
			if(y+1<=n)y++;
		}
		if(enter=='A')
		{
			if(x-1>=0)x--;
		}
		if(enter=='D')
		{
			if(x+1<=n)x++;
		}
		if(enter=='K')
		{
			if(c[y][x]==2)c[y][x]=3;
			else 
			{
				if(c[y][x]==3)c[y][x]=2;
			}
		}
		if(enter=='J')
		{
			if(c[y][x]!=1)
			{
				c[y][x]=a[y][x];
				if(c[y][x]==0)
				{
					for(i=0;i<=99;i++)
					{
						ty[i]=0;
						tx[i]=0;
					}
					tx[0]=x;
					ty[0]=y;
					ti=0;
					tn=0;
					while(ti<=tn)
					{
						if(c[ty[ti]][tx[ti]]==0)
						{
							if(ty[ti]-1>=0&&tx[ti]-1>=0)
							{
								c[ty[ti]-1][tx[ti]-1]=a[ty[ti]-1][tx[ti]-1];
								if(c[ty[ti]-1][tx[ti]-1]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if((ty[ti]-1)==ty[tj]&&tx[ti]-1==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti]-1;
										tx[tn]=tx[ti]-1;
									}
								}
							}
							if(ty[ti]-1>=0)
							{
								c[ty[ti]-1][tx[ti]]=a[ty[ti]-1][tx[ti]];
								if(c[ty[ti]-1][tx[ti]]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if(ty[tj]==(ty[ti]-1)&&tx[ti]==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti]-1;
										tx[tn]=tx[ti];
									}
								}
							}
							if(ty[ti]-1>=0&&tx[ti]+1<=n)
							{
								c[ty[ti]-1][tx[ti]+1]=a[ty[ti]-1][tx[ti]+1];
								if(c[ty[ti]-1][tx[ti]+1]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if(ty[ti]-1==ty[tj]&&tx[ti]+1==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti]-1;
										tx[tn]=tx[ti]+1;
									}
								}
							}
							if(tx[ti]-1>=0)
							{
								c[ty[ti]][tx[ti]-1]=a[ty[ti]][tx[ti]-1];
								if(c[ty[ti]][tx[ti]-1]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if(ty[ti]==ty[tj]&&tx[ti]-1==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti];
										tx[tn]=tx[ti]-1;
									}
								}
							}
							if(tx[ti]+1<=n)
							{
								c[ty[ti]][tx[ti]+1]=a[ty[ti]][tx[ti]+1];
								if(c[ty[ti]][tx[ti]+1]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if(ty[ti]==ty[tj]&&tx[ti]+1==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti];
										tx[tn]=tx[ti]+1;
									}
								}
							}
							if(ty[ti]+1<=n&&tx[ti]-1>=0)
							{
								c[ty[ti]+1][tx[ti]-1]=a[ty[ti]+1][tx[ti]-1];
								if(c[ty[ti]+1][tx[ti]-1]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if(ty[ti]+1==ty[tj]&&tx[ti]-1==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti]+1;
										tx[tn]=tx[ti]-1;
									}
								}
							}
							if(ty[ti]+1<=n)
							{
								c[ty[ti]+1][tx[ti]]=a[ty[ti]+1][tx[ti]];
								if(c[ty[ti]+1][tx[ti]]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if(ty[ti]+1==ty[tj]&&tx[ti]==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti]+1;
										tx[tn]=tx[ti];
									}
								}
							}
							if(ty[ti]+1<=n&&tx[ti]+1<=n)
							{
								c[ty[ti]+1][tx[ti]+1]=a[ty[ti]+1][tx[ti]+1];
								if(c[ty[ti]+1][tx[ti]+1]==0)
								{
									for(tj=0;tj<=tn;tj++)
									{
										if(ty[ti]+1==ty[tj]&&tx[ti]+1==tx[tj])
										{
											tp=1;
											break;
										}
										tp=0;
									}
									if(tp==0)
									{
										tn++;
										ty[tn]=ty[ti]+1;
										tx[tn]=tx[ti]+1;
									}
								}
							}
						}
						ti++;
					}
					for(i=0;i<=n;i++)
						for(j=0;j<=n;j++)b[i][j]=c[i][j];
				}
			}
		}
		if(c[y][x]==1)
		{
			system("cls");
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=n;j++)b[i][j]=a[i][j];
			}
			display();
			cout<<"you lose the game!"<<endl;
			break;
		}
		bomb=0;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(c[i][j]==2&&a[i][j]==1)bomb++;
			}
		}
		if(bomb==bn)
		{
			cout<<"you win"<<endl;
			break;
		}
	}
}
void cleanbomb::newcap()
{
	uint i,j,num=0,t,p=1;
	uint x[1000],y[1000];
	for(i=0;i<bn;i++)
	{
		x[i]=0;
		y[i]=0;
	}
	for(i=0;i<=size;i++)
		for(j=0;j<=size;j++)a[i][j]=0;
	num=0;
	srand(time(0));
	while(num<=bn-1)
	{
		
		i=rand()%size;
		j=rand()%size;
		for(t=0;t<=num;t++)
		{
			if(i==y[t]&&j==x[t])
			{
				p=1;
				break;
			}
			p=0;
		}
		if(p==0)
		{
			a[i][j]=1;
			x[num]=j;
			y[num]=i;
			num++;
		}
	}
	for(i=0;i<=size;i++)
	{
		for(j=0;j<=size;j++)
		{
			num=0;
			if(a[i][j]!=1)
			{
				if(i-1>=0&&j-1>=0&&a[i-1][j-1]==1)num++;
				if(i-1>=0&&a[i-1][j]==1)num++;
				if(i-1>=0&&j+1<=24&&a[i-1][j+1]==1)num++;
				if(j-1>=0&&a[i][j-1]==1)num++;
				if(j+1<=24&&a[i][j+1]==1)num++;
				if(i+1<=24&&j-1>=0&&a[i+1][j-1]==1)num++;
				if(i+1<=24&&a[i+1][j]==1)num++;
				if(i+1<=24&&j+1<=24&&a[i+1][j+1]==1)num++;
				if(num==0)a[i][j]=0;
				else a[i][j]=num+4;	
			}
		}
	}
}
int main()
{
	system("title É¨À×");
	system("mode con cols=60 lines=32");
	system("color C7");
	char choose='B';
	while(choose!='Q')
	{
		uint *size=new uint;
		here:
		cout<<"please enter the size of board"<<endl;
		cin>>*size;
		while(!cin)
		{
			cin.clear();
			cin.ignore (1000,'\n');
			cout<<"please enter the number from 10 to 30"<<endl;
			goto here;
		}
		if(*size<10||*size>30)
		{
			cout<<"please enter the number from 10 to 30"<<endl;
			goto here;
		}
		cleanbomb *cb=new cleanbomb(*size);
		cb->newcap();
		cb->game();
		delete cb;
		delete size;
		cout<<"new game(G) or quit(Q)?";
		cin>>choose;
	}
}