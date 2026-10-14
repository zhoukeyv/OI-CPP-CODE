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
int a[N],ans[N],t[N];
int n,m;
void add(int l,int r,int x)
{
	if (l>r)
	{
		return;
	}
	ans[l]+=x;
	ans[r+1]-=x;
	return;
}
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<n;i++)
	{
		b[i].id=i;
		b[i].x=a[i+1]-a[i];
	}
	sort(b+1,b+n);
	int sum=0,l=0,r=0,idx=1;
	for (int i=1;i<n;i++)
	{
		cerr<<b[i].id<<' '<<b[i].x<<'\n';
	}
	for (int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		if (x>0)
		{
			if (x<l)
			{
				l-=x;
				continue;
			}
			x-=l;
			l=0;
			r=x;
			while (idx<=n&&b[idx].x-sum<x)
			{
				add(idx,idx,b[idx].x-sum);
				b[idx].x=0;
				idx++;
			}
			add(idx+1,n,x);
			sum+=x;
		}
		else if (x<0)
		{
			x=-x;
			if (x<r)
			{
				r-=x;
				continue;
			}
			x-=r;
			r=0;
			l=x;
			while (idx<=n&&b[idx].x-sum<x)
			{
				add(idx+1,idx+1,b[idx].x-sum);
				b[idx].x=0;
				idx++;
			}
			add(idx+2,n,x);
			sum+=x;
		}
	}
	for (int i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		t[b[i].id]=ans[i];
	}
	for (int i=1;i<=n;i++)
	{
		cout<<t[i]<<'\n';
	}
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