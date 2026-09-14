#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=2010;
struct Node
{
	int a,b;
	bool operator<(const Node& x)const
	{
		return a<x.a;
	}
}a[N];
int n,h;
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	cin>>h;
	sort(a+1,a+n+1,greater<Node>());
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