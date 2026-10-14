#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=2e5+10;
struct Node
{
	int id,x;
	bool operator<(const Node& w)const
	{
		return x<w.x;
	}
}b[N];
int a[N];
int n,m;
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (i<n)
		{
			b[i].id=i;
			b[i].x=a[i];
		}
	}
	sort(b+1,b+n);
	
	return;
}
signed main()
{
	// freopen("paint.in","r",stdin);
	// freopen("paint.out","w",stdout);
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