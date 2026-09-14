#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=310,V=1e5+10;
bool dp[N][V];
int a[N];
int n;
void solve()
{
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		int lim=ceil(sum/2.0);
		for (int j=0;j<lim;j++)
		{
			dp[i][j]=
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