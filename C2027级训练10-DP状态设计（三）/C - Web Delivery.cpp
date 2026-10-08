#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=260,M=65550;
int dp[N][M],a[N][N],d[N];
int n,m;
void solve()
{
	memset(dp,0x3f,sizeof dp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[j][i];
		}
	}
	for (int i=1;i<=m;i++)
	{
		cin>>d[i];
	}
	if (m>n)
	{
		dp[0][0]=0;
		for (int i=1;i<=m;i++)
		{
			for (int j=0;j<(1<<n);j++)
			{
				dp[i][j]=dp[i-1][j];
			}
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<(1<<n);k++)
				{
					if (k>>j&1)
					{
						continue;
					}
					dp[i][k|(1<<j)]=min(dp[i][k]+a[i][j+1],dp[i][k|(1<<j)]);
				}
			}
			for (int j=0;j<1<<n;j++)
			{
				dp[i][j]=min(dp[i][j]+d[i],dp[i-1][j]);
			}
		}
		cout<<dp[m][(1<<n)-1]<<'\n';
	}
	else
	{
		dp[0][0]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<(1<<m);j++)
			{
				for (int k=0;k<m;k++)
				{
					if (j>>k&1)
					{
						dp[i][j]=min(dp[i][j],dp[i-1][j]+a[k+1][i]);
					}
					else
					{
						dp[i][j|(1<<k)]=min(dp[i][j|(1<<k)],dp[i-1][j]+a[k+1][i]+d[k+1]);
					}
				}
			}
		}
		int ans=inf;
		for (int i=1;i<1<<m;i++)
		{
			ans=min(ans,dp[n][i]);
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