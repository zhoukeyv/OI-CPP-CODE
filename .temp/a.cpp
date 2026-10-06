#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=510;
int dp[N][N];
string s;
int n;
void solve()
{
	cin>>n>>k>>p;
	const int mod=p;
	for (int j=0;j<=k;++j)
	{
		f[n][j]=g[n][j]=1ll,s[n][j]=(j+1)%mod;
	}
	for (int i=n-1;i>=1;--i)
	{
		for (int j=0;j<=k;++j)
		{
			f[i][j]=g[i][j]=0ll;
			for (int x=0;x<=j;++x)
			{
				if (x)
				{
					f[i][j]+=2ll*f[i+1][x]*s[i+1][min(x-1,j-x)]%mod;
				}
				g[i][j]+=g[i+1][x]*s[i+1][j-x]%mod;
			}
			f[i][j]%=mod,g[i][j]%=mod;
			s[i][j]=((j?s[i][j-1]:0ll)+g[i][j])%mod;
		}
	}
	cout<<f[1][k]<<'\n';
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