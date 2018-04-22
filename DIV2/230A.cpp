#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int s,n ;
    cin>>s>>n ;
    int x[n],y[n] ;
    vector <pair<int,int>>data ;
    for(int i=0;i<n;i++)
    {
        int x,y ;
        cin>>x>>y ;
        data.push_back(make_pair(x,y)) ;
    }

    sort(data.begin(),data.end()) ;
    int sum =s ;
    for (int i=0;i<n;i++)
    {
        if (sum>data[i].first)
        {
            sum  += data[i].second ;
        }
        else {
            cout<<"NO\n" ;
            return  0 ;
        }
    }
    cout<<"YES\n" ;
}
