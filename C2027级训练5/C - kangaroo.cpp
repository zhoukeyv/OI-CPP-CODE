#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=2010,mod=1e9+7;
int dp[N][N];
int n,s,t;
void solve()
{
	cin>>n>>s>>t;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i][j]+(j-(i>s)-(i>j))*dp[i-1][j-1]%mod+dp[i-1][j+1]*j%mod)%mod;
		}
	}
	cout<<dp[n][1]<<'\n';
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