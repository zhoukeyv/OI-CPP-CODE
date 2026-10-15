#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=110,K=40,V=3010;
int dp[N][V];
int n,k,mod,ans=0;
void solve()
{
	cin>>n>>k>>mod;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n*(k-1);j++)
		{
			for (int l=0;l<=min(k-1,j);l++)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j-l])%mod;
			}
		}
	}
	for (int i=0;i<=V;i++)
	{
		for (int j=0;j<=min(k-1,i);j++)
		{
			if ((i-j)%k!=j)
			{
				continue;
			}
			ans=(ans+dp[n-1][i-j]*n%mod)%mod;
		}
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