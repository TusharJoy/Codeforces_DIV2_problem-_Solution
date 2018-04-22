#include <bits/stdc++.h>
#define MX 100009
#define MX1 1000000009
using namespace std ;
int n,m ;
long long int c ;

vector<int> adj[MX];
vector<int>cost ;
vector<int> visited(MX,0);
int cnt =0 ;

void dfs(int src,int cnt)
{
	if (visited[src]>0) return ;

	visited[src] =cnt ;

	for (int i=0;i<adj[src].size();i++)
	{
		int v = adj[src][i] ;
		dfs(v,cnt) ;
	}
}

int main()
{
	cin>>n>>m ;
	for (int i=0;i<n;i++)
	{
		int x ;cin>>x ;
		cost.push_back(x);
	}
	for (int i=0;i<m;i++)
	{
		int x,y ;cin>>x>>y ;
		adj[x-1].push_back(y-1) ;
		adj[y-1].push_back(x-1) ;
	}

	for (int i=0;i<n;i++)
	{
		if (visited[i]==0)
		{
			cnt++ ;
			dfs(i,cnt) ;
		}
	}
	vector<int>sum(cnt,1129999999) ;
        for (int i=0;i<n;i++)
        {
            int in = visited[i]-1 ;
            sum[in] =min(sum[in],cost[i]) ;
        }
		long long summa=0 ;
		for (int i=0;i<sum.size();i++)
        {
            summa +=sum[i] ;
        }
        cout<<summa<<endl;
}
