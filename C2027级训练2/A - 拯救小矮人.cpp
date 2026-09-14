#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=2010;
struct Node
{
	int a,b;
	bool operator<(const Node& x)const
	{
		return a+b<x.a+x.b;
	}
}a[N];
int dp[N];
int n,h;
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
		dp[0]+=a[i].a;
		dp[i]=-inf;
	}
	cin>>h;
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
    {
		for (int j=i;j>=1;j--)
        {
			if (dp[j-1]+a[i].b>=h)
			{
				dp[j]=max(dp[j],dp[j-1]-a[i].a);
			}
		}
	}
	for (int i=n;i>=0;i--)
	{
		if (dp[i]>=0)
		{
			cout<<i<<'\n';
			return;
		}
	}
    for(int i = n; i >= 0; --i)
        if(dp[i] >= 0) {
            printf("%d\n", i);
	return;
}
signed main()
{
#ifndef LOCAL_cph
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TestCase=1;
	// cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}