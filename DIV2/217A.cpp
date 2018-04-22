#include <iostream>
#define MX 1005

using namespace std ;
int n ;

struct PAIR{

    int x,y ;
};

PAIR mp (int x,int y)
{
    PAIR t ;
    t.x= x ;
    t.y = y ;
    return t ;
}

int visited[MX][MX] ;
PAIR graph [MX] ;
PAIR que[MX] ;


void bfs(int sx,int sy)
{
    int f=0, e=1 ;
    que[0] = mp(sx,sy) ;
    visited[sx][sy] =1 ;
    while(f!=e)
    {
        PAIR u = que[f] ;
        for (int k=0;k<n ;k++)
        {
            int vx =graph[k].x  ;
            int vy = graph[k].y ;
            if ((vx==sx || vy==sy) && visited[vx][vy]==0)
            {
                visited[vx][vy]=1 ;
                que[e++] = mp(vx,vy) ;
            }
        }
        f++ ;
    }
}

//int b =0 ;
void dfs(int sx,int sy)
{
    visited[sx][sy] =1 ;
    for (int i=0;i<n;i++)
    {
        int vx =graph[i].x  ;
        int vy = graph[i].y ;
        if ((vx==sx || vy==sy) && visited[vx][vy]==0)
            {
               // cout<<"HRE for"<<b++<<endl;
                dfs(vx,vy) ;
            }
    }
}

int main()
{
    cin>>n ;
    for (int i=0;i<n;i++)
    {
        int x,y ;
        cin>>x>>y ;
        graph[i] = mp(x,y) ;
    }
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        int sx= graph[i].x ;
        int sy = graph[i].y;
        if (visited[sx][sy]==0) {dfs(sx,sy) ;cnt++;}
    }
    cout<<cnt-1<<endl ;
}
