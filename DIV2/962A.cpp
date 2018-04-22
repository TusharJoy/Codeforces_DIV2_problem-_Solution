#include <bits/stdc++.h>

using namespace std ;

int main()
{
	int n ,tot=0;
	cin>>n ;
	int arr[n] ;
	for (int i=0;i<n;i++)
	{
		int x ; cin>>x ;
		arr[i]=x ;
		tot +=x ;
	}

	if (tot%2==0) tot = tot/2 ;
	else tot = (tot/2) +1

	int sum=0 ;
	for (int i=0;i<n;i++)
	{
		if (sum>=tot) {cout<<i+1<<endl; return 0 ;}
		else {
			sum +=arr[i] ;
		}
	}
}