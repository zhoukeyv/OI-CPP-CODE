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
	memset(dp,0x3f,sizeof dp);
	cin>>n>>s;
	s='@'+s;
	int lst=1;
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
			if (dp[l][r]!=0)
			{
				continue;
			}
			int lst=l,nxt=r;
			while (s[lst+1]==s[lst])
			{
				lst++;
			}
			while (s[nxt-1]==s[nxt])
			{
				nxt--;
			}
			if (s[lst]==s[nxt])
			{
				dp[l][r]=
			}
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