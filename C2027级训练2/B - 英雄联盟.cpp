#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=130,V=3e5+10;
int k[N],c[N],dp[N][V];
int n,m;
int prod(int x,int y)
{
	__int128 t=(__int128)x*y;
	if (t>=m)
	{
		return m;
	}
	return x*y;
}
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int sum=0;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for (int j=1;j<=k[i];j++)
		{
			for (int t=sum;t>=0;t--)
			{
				// cerr<<t<<"->"<<t+j*c[i]<<' '<<j<<'\n';
				dp[t+j*c[i]]=max(dp[t+j*c[i]],prod(dp[t],j));
			}
		}
		sum+=k[i]*c[i];
	}
	for (int i=1;i<=sum;i++)
	{
		// cerr<<i<<' '<<dp[i]<<'\n';
		if (dp[n][i]>=m)
		{
			cout<<i<<'\n';
			return;
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