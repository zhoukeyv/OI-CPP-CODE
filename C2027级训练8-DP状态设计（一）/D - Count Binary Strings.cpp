#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=110,mod=998244353;
int a[N][N],b[N],c[N],t[N];
int n;
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]==1)
			{
				for (int k=i+1;k<=j;k++)
				{
					t[k]=1;
				}
			}
			else if (a[i][j]==2)
			{
				c[j]=max(c[j],i);
			}
		}
	}
	int lst=1;
	b[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (t[i]==0)
		{
			lst=i;
		}
		b[i]=lst;
	}
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i-b[i]+1;j>max(2ll,i-c[i]+1);j--)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
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