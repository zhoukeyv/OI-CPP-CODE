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
	int lst=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			dp[i][j]=inf;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (i==n||s[i]!=s[i+1])
		{
			for (int j=lst;j<=i;j++)
			{
				for (int k=j;k<=i;k++)
				{
					dp[j][k]=1;
				}
			}
			lst=i+1;
		}
	}
	for (int len=1;len<=n;len++)
	{
		for (int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			if (dp[l][r]!=inf)
			{
				continue;
			}
			int lst=l,suml=0,nxt=r,sumn=0;
			while (lst<r&&s[lst+1]==s[lst])
			{
				lst++;
			}
			while (s[nxt-1]==s[nxt])
			{
				nxt--;
			}
			if (s[lst]==s[nxt])
			{
				dp[l][r]=min(dp[l][r],dp[lst+1][nxt-1]+1);
			}
			dp[l][r]=min(dp[l][r],dp[lst+1][r]+1);
			dp[l][r]=min(dp[l][r],dp[l][nxt-1]+1);
			for (int mid=l;mid<r;mid++)
			{
				dp[l][r]=min(dp[l][r],dp[l][mid]+dp[mid+1][r]);
			}
			cerr<<l<<' '<<r<<' '<<dp[l][r]<<'\n';
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