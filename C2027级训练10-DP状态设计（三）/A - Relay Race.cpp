#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=310;
int dp[2][N][N];
int a[N][N];
int n;
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int k=2;k<=2*n;k++)
	{
		memset(dp[k&1],-0x3f,sizeof dp[k&1]);
		for (int i1=1;i1<=n;i1++)
		{
			for (int i2=1;i2<=n;i2++)
			{
				int j1=k-i1,j2=k-i2,t=a[i1][j1];
				if (i1!=i2||j1!=j2)
				{
					t+=a[i2][j2];
				}
				if (j1>=1&&j1<=n&&j2>=1&&j2<=n)
				{
					dp[k&1][i1][i2]=max(dp[k&1][i1][i2],dp[k&1^1][i1-1][i2-1]+t);
					dp[k&1][i1][i2]=max(dp[k&1][i1][i2],dp[k&1^1][i1-1][i2]+t);
					dp[k&1][i1][i2]=max(dp[k&1][i1][i2],dp[k&1^1][i1][i2-1]+t);
					dp[k&1][i1][i2]=max(dp[k&1][i1][i2],dp[k&1^1][i1][i2]+t);
				}
			}
		}
	}
	cout<<dp[2*n][n][n];
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