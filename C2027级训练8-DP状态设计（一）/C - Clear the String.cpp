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
	queue<pair<int,int>> q;
	for (int i=1;i<=n;i++)
	{
		if (i==n||s[i]!=s[i+1])
		{
			q.push({lst,i});
			lst=i+1;
		}
	}
	while (!q.empty())
	{
		pair<int,int> cur=q.front();
		q.pop();
		if (cur.first==1&&cur.second==n)
		{
			continue;
		}
		if (cur.first!=1&&cur.second!=n&&s[cur.first-1]==s[cur.second+1])
		{
			
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