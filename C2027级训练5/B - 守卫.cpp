#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=5010;
int dp[N][N];
int a[N];
int n;
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][i]=1;
	}
	for (int r=1;r<=n;r++)
	{
		for (int l=r-1;l>=1;l--)
		{
			
		}
	}
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