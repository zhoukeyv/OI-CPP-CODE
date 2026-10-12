#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=5010;
int dp[N][N];
int a[N],s[N];
int n;
void solve()
{
	memset(dp,0x3f,sizeof dp);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for (int i=1;i<=n;i++)
	{
		dp[1][i]=i-1;
	}
	for (int j=2;j<=n;j++)
	{
		int idx=j,minn=inf;
		for (int i=j;i<=n;i++)
		{
			while (idx>1&&s[j-1]-s[idx-2]<=s[i]-s[j-1])
			{
				idx--;
				minn=min(minn,dp[idx][j-1]);
			}
			
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			cerr<<i<<' '<<j<<':'<<dp[i][j]<<'\n';
		}
	}
	int ans=inf;
	for (int i=1;i<=n;i++)
	{
		ans=min(ans,dp[n][i]);
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
	// cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}