#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1010;
int a[N],dp[N][N],way[N][N];
int n;
int update(pair<int,int> i,pair<int,int> j,int v)
{
	
}
void solve()
{
	memset(dp,0x3f,sizeof dp);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1][1]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			if (i+2<=n+1)
			{
				dp[i+2][j]=min(dp[i+2][j],dp[i][j]+max(a[i],a[i+1]));
				dp[i+2][i]=min(dp[i+2][i],dp[i][j]+max(a[i+1],a[j]));
			}
			dp[i+1][i+1]=min(dp[i+1][i+1],dp[i][j]+max(a[i],a[j]));
			cerr<<i<<' '<<j<<':'<<dp[i][j]<<'\n';
		}
		if (i+3<=n+1)
		{
			dp[i+3][i]=min(dp[i+3][i],dp[i][i]+max(a[i+1],a[i+2]));
			dp[i+3][i+1]=min(dp[i+3][i+1],dp[i][i]+max(a[i],a[i+2]));
		}
		if (i+2<=n+1)
		{
			dp[i+2][i+2]=min(dp[i+2][i+2],dp[i][i]+max(a[i],a[i+1]));
		}
		cerr<<i<<' '<<i<<':'<<dp[i][i]<<'\n';
	}
	if (n%2==0)
	{
		cout<<dp[n+1][n+1]<<'\n';
	}
	else
	{
		int ans=inf;
		for (int i=1;i<=n;i++)
		{
			ans=min(ans,dp[n+1][i]+a[i]);
		}
		cout<<ans<<'\n';
	}
	return;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
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