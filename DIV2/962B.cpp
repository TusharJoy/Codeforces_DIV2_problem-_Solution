#include <bits/stdc++.h>

using namespace std ;

struct greater1
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main()
{
	int n,a,b,cnt=0 ;
	cin>>n>>a>>b ;
	string s ;
	cin>>s ;
	vector<int>data ;
	for (int i=0;i<s.size();i++)
	{
	  //  cout<<"index   "<<i;
	    if (s[i]=='.') cnt++ ;
		if (s[i]=='*' && cnt!=0) {data.push_back(cnt);cnt =0; }
       // cout<<cnt<<endl ;
	}
	data.push_back(cnt) ;

	sort(data.begin(),data.end(),greater1()) ;
	int lsum =0,ssum=0 ;

	for(int i=0;i<data.size();i++)
	{
		int val = data[i] ;
		if (val>1) {
			lsum+=val ;
		}
		else if(val==1)
		{
			ssum +=val ;
		}
	}
    cout<<"\n"<<lsum<<"    "<<ssum<<endl ;
	int result =0 ;

    if (lsum%2==0)
    {
        int v = lsum/2 ;
        if (v<=a ) {result +=v ; a -=v ; }
        if(v<=b) {  result +=v ; b -=v ;}
    }
    if(lsum%2==1)
    {
        int f =1 ;
        int v= lsum/2 ;
        if (v<=a )
        {
            if (v+1 <=a && f==1)
            {
                result += (v+1) ;
                a -=(v+1) ;
                f==0 ;
            }
            else {
                result +=v ; a -=v ;
            }
        }
        if (v<=b )
        {
            if (v+1 <=b && f==1)
            {
                f=0 ;
                result += (v+1) ;
                b -=(v+1) ;
            }
            else {
                result +=v ; b -=v ;
            }
        }
    }

	if (ssum<=a || ssum<=b )
	{
		result +=ssum ;
	}
	cout<<result<<endl ;
}
