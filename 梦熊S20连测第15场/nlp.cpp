#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10,V=2e6+10;
unordered_map<int,int> um1[V],um2[V];
set<int> pl;
int a[N],l[N],r[N];
int n,m;
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if (!um1[x].count(y))
		{
			um1[x][y]=z;
			um2[y][x]=z;
		}
	}
	for (int i=1;i<n;i++)
	{
		l[i]=i-1;
		r[i]=i+1;
		if (um1[a[i]].count(a[i+1]))
		{
			pl.insert(i);
		}
	}
	l[i]=1;
	r[i]=n;
	while (!)
	return;
}
signed main()
{
	// freopen("nlp.in","r",stdin);
	// freopen("nlp.out","w",stdout);
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