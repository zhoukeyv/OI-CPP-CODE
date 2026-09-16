#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=2e5+10,mod=998244353;
struct Node
{
	int l,r,sum,lazy1,lazy2;
	bool flag;
}tr[N*16];
int tr_cnt=-1;
int new_node()
{
	tr_cnt++;
	tr[tr_cnt]={-1,-1,0,1,0,false};
	return tr_cnt;
}
void apply(int idx,int l,int r,int x,int y)
{
	tr[idx].sum=(tr[idx].sum*x%mod+y*(r-l+1)%mod)%mod;
	tr[idx].lazy1=(tr[idx].lazy1*x%mod+y)%mod;
	tr[idx].lazy2=tr[idx].lazy2*x%mod;
	return;
}
void push_down(int idx,int l,int r)
{
	if (tr[idx].lazy1==0&&tr[idx].lazy2==1)
	{
		return;
	}
	if (tr[idx].l==-1)
	{
		int lc=new_node();
		tr[idx].l=lc;
	}
	if (tr[idx].r==-1)
	{
		int rc=new_node();
		tr[idx].r=rc;
	}
	int mid=l+(r-l)/2;
	tr[tr[idx].l].sum=tr[tr[idx].l].sum*tr[idx].lazy2%mod;
	tr[tr[idx].r].sum=tr[tr[idx].r].sum*tr[idx].lazy2%mod;
	tr[tr[idx].l].lazy1=tr[tr[idx].l].lazy1*tr[idx].lazy2%mod;
	tr[tr[idx].r].lazy1=tr[tr[idx].r].lazy1*tr[idx].lazy2%mod;
	tr[tr[idx].l].lazy2=tr[tr[idx].l].lazy2*tr[idx].lazy2%mod;
	tr[tr[idx].r].lazy2=tr[tr[idx].r].lazy2*tr[idx].lazy2%mod;
	tr[tr[idx].l].sum=(tr[tr[idx].l].sum+tr[idx].lazy1*(mid-l+1)%mod)%mod;
	tr[tr[idx].r].sum=(tr[tr[idx].r].sum+tr[idx].lazy1*(r-mid)%mod)%mod;
	tr[tr[idx].l].lazy1=(tr[tr[idx].l].lazy1+tr[idx].lazy1)%mod;
	tr[tr[idx].r].lazy1=(tr[tr[idx].r].lazy1+tr[idx].lazy1)%mod;
	tr[idx].lazy1=0;
	tr[idx].lazy2=1;
	return;
}
void push_up(int idx)
{
	tr[idx].sum=0;
	if (tr[idx].l!=-1)
	{
		tr[idx].sum=(tr[idx].sum+tr[tr[idx].l].sum)%mod;
	}
	if (tr[idx].r!=-1)
	{
		tr[idx].sum=(tr[idx].sum+tr[tr[idx].r].sum)%mod;
	}
	return;
}
void update(int idx,int l,int r,int x,int v)
{
	if (l==r)
	{
		tr[idx].sum=v;
		return;
	}
	push_down(idx,l,r);
	int mid=l+(r-l)/2;
	if (x<=mid)
	{
		if (tr[idx].l==-1)
		{
			int lc=new_node();
			tr[idx].l=lc;
		}
		update(tr[idx].l,l,mid,x,v);
	}
	else
	{
		if (tr[idx].r==-1)
		{
			int rc=new_node();
			tr[idx].r=rc;
		}
		update(tr[idx].r,mid+1,r,x,v);
	}
	push_up(idx);
	return;
}
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