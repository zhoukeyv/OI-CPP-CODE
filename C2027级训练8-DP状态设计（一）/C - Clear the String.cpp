#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=510;
int dp[N][N];
string s;
int n;
void solve()
{
	cin>>n>>s;
	s='@'+s;
	for (int i=1;i<=n;i++)
	{
		dp[i][i]=1;
	}
	for (int len=2;len<=n;len++)
	{
		for (int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			if (s[l]==s[r])
			{
				dp[l][r]=dp[l][r-1];
			}
			else
			{
				dp[l][r]=inf;
				for (int k=l;k<r;k++)
				{
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	cout<<dp[1][n]<<'\n';
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