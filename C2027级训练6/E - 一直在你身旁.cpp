#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=7110;
int a[N],dp[N][N];
int n;
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(dp,0x3f,sizeof dp);
	dp[1][n]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=n;j>=i;j--)
		{
			if (i==1&&j==n)
			{
				continue;
			}
			for (int k=max(0ll,2*i-j-2);k<=i-1;k++)
			{
				dp[i][j]=min(dp[i][j],dp[k][j]+a[i-1]);
			}
			for (int k=j+1;k<=min(n,2*j-i+2);k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+a[j+1]);
			}
		}
	}
	int ans=-inf;
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][i]);
	}
	cout<<ans<<'\n';
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
	cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}