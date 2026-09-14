#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=310,V=1e5+10;
bool dp[V];
int a[N],way[V];
int n;
void solve()
{
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	dp[0]=true;
	int lim=ceil(sum/2.0);
	for (int i=1;i<=n;i++)
	{
		for (int j=lim-1;j>=0;j--)
		{
			if (dp[j]==1)
			{
				dp[j+a[i]]=1;
				way[j+a[i]]=j;
			}
		}
	}
	int idx=0;
	for (int i=(int)1e5;i>=1;i--)
	{
		if (dp[i])
		{
			idx=i;
			break;
		}
	}
	while (idx!=0)
	{
		
	}
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