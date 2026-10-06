#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
vector<vector<int>> dp;
string s;
int n;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	s='@'+s;
	n=s.size()-1;
	dp.resize(n+1,vector<int>(n+1));
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
				dp[l][r]=1e18;
				for (int k=l;k<r;k++)
				{
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}