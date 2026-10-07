#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=10010,V=2010;
int dp[N][V];
int a[N];
int n;
void solve()
{
	memset(dp,0x3f,sizeof dp);
	cin>>n;
	dp[0][0]=0;
	int maxx=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=2*maxx;j++)
		{
			cerr<<i<<' '<<j<<':'<<dp[i][j]<<'\n';
			if (dp[i][j]==inf)
			{
				continue;
			}
			dp[i+1][max(0ll,j-a[i+1])]=min(dp[i+1][max(0ll,j-a[i+1])],dp[i][j]+a[i+1]);
			if (j+a[i+1]<=2*maxx)
			{
				dp[i+1][j+a[i+1]]=min(dp[i+1][j+a[i+1]],max(0ll,dp[i][j]-a[i+1]));
			}
		}
	}
	int ans=inf;
	for (int j=0;j<=2*maxx;j++)
	{
		ans=min(ans,dp[n][j]+j);
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
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