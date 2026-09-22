#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=3e5+10,M=6e5+10;
int tr[N];
int update(int x,int v)
{
	while (x<=n)
	{
		tr[x]+=v;
		x+=lowbit(x);
	}
}
void solve()
{
	
	return;
}
signed main()
{
#ifndef LOCAL_cph
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
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