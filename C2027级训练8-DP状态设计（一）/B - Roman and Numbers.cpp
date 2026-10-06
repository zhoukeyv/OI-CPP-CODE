#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,B=1<<18,M=110;
int dp[B][M];
string s;
int n,m;
void solve()
{
	cin>>s>>m;
	n=s.size();
	dp[0][0]=1;
	for (int i=0;i<(1<<n)-1;i++)
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