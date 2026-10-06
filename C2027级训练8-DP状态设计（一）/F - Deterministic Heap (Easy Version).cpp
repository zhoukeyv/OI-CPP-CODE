#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=510;
int dp1[N][N],dp2[N][N],s[N][N];
int n,k,mod;
void solve()
{
	memset(dp1,0,sizeof dp1);
	memset(dp2,0,sizeof dp2);
	memset(s,0,sizeof s);
	cin>>n>>k>>mod;
	for (int j=0;j<=k;j++)
	{
		dp1[n][j]=dp2[n][j]=1;
		s[n][j]=(j+1)%mod;
	}
	for (int i=n-1;i>=1;i--)
	{
		for (int j=0;j<=k;j++)
		{
			for (int x=0;x<=j;x++)
			{
				if (x)
				{
					dp1[i][j]+=2ll*dp1[i+1][x]*s[i+1][min(x-1,j-x)]%mod;
				}
				dp2[i][j]+=dp2[i+1][x]*s[i+1][j-x]%mod;
			}
			dp1[i][j]%=mod,dp2[i][j]%=mod;
			s[i][j]=((j?s[i][j-1]:0ll)+dp2[i][j])%mod;
		}
	}
	cout<<dp1[1][k]<<'\n';
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