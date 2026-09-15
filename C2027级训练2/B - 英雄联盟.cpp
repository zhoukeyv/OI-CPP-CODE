#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=130,V=3e5+10;
int k[N],c[N];
int n,m;
int prod(int x,int y)
{
	__int128 t=(__int128)x*y;
	if (t>=m)
	{
		return m+1;
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