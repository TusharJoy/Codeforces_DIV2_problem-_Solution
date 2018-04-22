#include <bits/stdc++.h>
#define MX 900009

using namespace std ;
int n,x ;
int que[MX] ;
int lvl[MX] ;
int visited[MX] ;
vector<int>adj[MX] ;
int parent[MX] ;

void bfs(int src)
{
    lvl[src] =0 ;
    int dis =0 ;
    int f=0,e=1 ;
    que[0] =src ;
    parent[src] =src ;
    visited[src] =1 ;
    while(f!=e)
    {
        int u = que[f] ;
        for(int i=0;i<adj[u].size();i++)
        {
                int v = adj[u][i] ;
                if (visited[v]==0)
                {
                    lvl[v] =lvl[u]+1 ;
                    visited[v] =1 ;
                    que[e++] = v ;
                    parent[v] =u ;
                }
        }
        f++ ;
    }
}

int main()
{
    cin>>n>>x ;
    for (int i=1;i<n;i++)
    {
        int x,y ;
        cin>>x>>y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    bfs(1) ;
 	for (int i=0;i<n;i++)
 	{

 	}
    int mx =-1 ;
    for (int i=1;i<=n;i++)
    {
        if (lvl[i]>mx)
        {
            mx  =lvl[i] ;
        }
    }
    cout<<(mx*2)<<endl;
}
