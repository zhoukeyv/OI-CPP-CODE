#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=2e5+10;
struct Node
{
	int l,r,sum,mul,lazy;
}tr[N*16];
int tr_cnt=-1;
int new_node()
{
	tr_cnt++;
	tr[tr_cnt]={-1,-1,0,1,0};
	return tr_cnt;
}
void push_down(int l,int r,)
vector<int> graph[N];
int dp[N];
int n;
void solve()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
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