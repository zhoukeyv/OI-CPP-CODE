#include<bits/stdc++.h>
using namespace std;
int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n=rng()%7+2;
	int k=rng()%n+2;
	if (k>n)
	{
		k=n;
	}
	cout<<n<<" "<<k<<"\n";
	for (int i=2;i<=n;i++)
	{
		int p=rng()%(i-1)+1;
		if (rng()&1)
		{
			cout<<p<<" "<<i<<"\n";
		}
		else
		{
			cout<<i<<" "<<p<<"\n";
		}
	}
	return 0;
}