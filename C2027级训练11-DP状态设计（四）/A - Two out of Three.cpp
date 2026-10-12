#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1010;
int a[N],dp[N][N];
int n;
void solve()
{
	memset(dp,0x3f,sizeof dp);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1][1]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			if (i+2<=n+1)
			{
				dp[i+2][j]=min(dp[i+2][j],dp[i][j]+max(a[i],a[i+1]));
				dp[i+2][i]=min(dp[i+2][i],dp[i][j]+max(a[i+1],a[j]));
			}
			dp[i+1][i+1]=min(dp[i+1][i+1],dp[i][j]+max(a[i],a[j]));
		}
	}
	if (n%2==0)
	{
		
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