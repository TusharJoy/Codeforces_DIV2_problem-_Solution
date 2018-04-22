#include <iostream>
#include<cstdio>
#define MX 900
#define MX1 9000009
using namespace std ;

int n, m, data,f=0,e=1;
int dx[] ={0,0,1,-1} ;
int dy[] = {-1,1,0,0};

struct PAIR{
    int x,y ;
};

int visited[MX][MX] ;
PAIR que[MX1] ;
char g[MX][MX];

PAIR mp (int x,int y)
{
    PAIR t ;
    t.x= x ;
    t.y = y ;
    return t ;
}

int boundary(int x,int y)
{
    return x<m && x>=0 && y<n && y>=0 ;
}

void bfs1(int sx,int sy)
{
    que[0] = mp(sx,sy) ;
    visited[sy][sx] =1 ;
    while(f!=e)
    {
        PAIR u = que[f] ;
        for (int k=0;k<4;k++)
        {
            int vx =u.x+dx[k] ;
            int vy =u.y+dy[k] ;
            if (boundary(vx,vy)&& g[vy][vx]=='.' && visited[vy][vx]==0)
            {
                visited[vy][vx]=1 ;
                que[e++] = mp(vx,vy) ;
            }
        }
        f++ ;
    }
}

int main()
{
    cin>>n>>m>>data ;
    int x,y ;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>g[i][j] ;
            visited[i][j] =0 ;
            x=j;y=i;
        }
    }

    bfs1(x,y) ;
    for (int i=e-data;i<e;i++)
    {
        g[que[i].y][que[i].x] = 'X';
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout<<g[i][j];
        }
        cout<<endl;
    }
}
