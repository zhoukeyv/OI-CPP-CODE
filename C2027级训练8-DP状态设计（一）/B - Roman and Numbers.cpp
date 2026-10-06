#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,B=1<<18,M=110;
int dp[B][M];
string s;
int n,m;
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
void print(int x)
{
	bitset<3> b(x);
	cerr<<b;
}
void solve()
{
	cin>>s>>m;
	n=s.size();
	dp[0][0]=1;
	for (int i=0;i<(1<<n)-1;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (dp[i][j]==0)
			{
				continue;
			}
			for (int k=0;k<n;k++)
			{
				if (((i>>k)&1)||s[k]=='0'&&i==0)
				{
					continue;
				}
				dp[i|(1<<k)][(j+(s[k]-'0')*power(10,n-__builtin_popcount(i)-1,m))%m]+=dp[i][j];
			}
		}
	}
	for (int i=0;i<(1<<n);i++)
	{
		for (int j=0;j<m;j++)
		{
			print(i);
			cerr<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	cout<<dp[(1<<n)-1][0]<<'\n';
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