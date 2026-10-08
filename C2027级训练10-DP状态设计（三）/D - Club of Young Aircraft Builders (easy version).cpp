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
void solve()
{
	cin>>n>>c>>m;
	for (int i=1;i<=n;i++)
	{
		
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
		}
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
	cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}