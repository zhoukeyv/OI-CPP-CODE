#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=5010;
int dp[N][N];
int a[N];
int n,ans=0;
bool check(int x,int y,int r)
{
	return (a[r]-a[y])*(r-x)>(a[r]-a[x])*(r-y);
}
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][i]=1;
		ans^=1;
	}
	for (int r=1;r<=n;r++)
	{
		int p=0,sum=1;
		for (int l=r-1;l>=1;l--)
		{
			if (p==0||check(l,p,r))
			{
				sum+=min(dp[l+1][p-1],dp[l+1][p]);
				p=l;
			}
			dp[l][r]=sum+min(dp[l][p-1],dp[l][p]);
			ans^=dp[l][r];
		}
	}
	cout<<ans<<'\n';
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