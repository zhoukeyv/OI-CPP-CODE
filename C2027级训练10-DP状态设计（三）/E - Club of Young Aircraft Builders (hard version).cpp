#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=110,M=10010,mod=1e9+7;
int dp[N][M],s[M][N],a[M],cnt[N],fac[M],infac[M];
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
	cin>>n>>c>>m;
	fac[0]=1;
	for (int i=1;i<=m;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	infac[m]=power(fac[m],mod-2,mod);
	for (int i=m-1;i>=0;i--)
	{
		infac[i]=infac[i+1]*(i+1)%mod;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			s[i][j]=s[i-1][j];
		}
		for (int j=1;j<a[i];j++)
		{
			s[i][j]++;
		}
	}
	dp[1][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			
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
	// cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}