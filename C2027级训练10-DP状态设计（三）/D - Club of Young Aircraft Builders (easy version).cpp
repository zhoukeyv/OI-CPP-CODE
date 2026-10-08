#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=110,M=10010,mod=1e9+7;
int dp[N][M],a[N],fac[N],infac[N];
int n,c,m;
int power(int a,int b,int p)
{
	int res=1;
	while (b)
	{
		if (b&1)
		{
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int C(int a,int b)
{
	if (a<0||b<0||a<b)
	{
		return 0;
	}
	return fac[a]*infac[b]%mod*infac[a-b]%mod;
}
void solve()
{
	memset(dp,0,sizeof dp);
	cin>>n>>c>>m;
	fac[0]=1;
	for (int i=1;i<=c;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	infac[c]=power(fac[c],mod-2,mod);
	for (int i=c-1;i>=0;i--)
	{
		infac[i]=infac[i+1]*(i+1)%mod;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	dp[n][c]=1;
	for (int i=n-1;i>=1;i--)
	{
		for (int j=c;j<=m;j++)
		{
			for (int k=0;k<=c;k++)
			{
				dp[i][j]=(dp[i][j]+dp[i+1][j-k]*C(c,k)%mod)%mod;
			}
			// cerr<<i<<' '<<j<<':'<<dp[i][j]<<'\n';
		}
	}
	cout<<dp[1][m]<<'\n';
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