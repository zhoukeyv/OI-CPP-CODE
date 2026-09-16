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
int power(int a,int b,int p)
{
	int res=1;
	while (b)
	{
		if (b&1)
		{
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int new_node()
{
	tr_cnt++;
	tr[tr_cnt]={-1,-1,0,1,0,false};
	return tr_cnt;
}
void apply(int idx,int l,int r,int x,int y)
{
	tr[idx].sum=(tr[idx].sum*y%mod+x*(r-l+1)%mod)%mod;
	tr[idx].lazy1=(tr[idx].lazy1*y%mod+x)%mod;
	tr[idx].lazy2=tr[idx].lazy2*y%mod;
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
	apply(tr[idx].l,l,mid,tr[idx].lazy1,tr[idx].lazy2);
	apply(tr[idx].r,mid+1,r,tr[idx].lazy1,tr[idx].lazy2);
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
int merge(int idx1,int idx2,int l,int r)
{
	if (idx1==-1||idx2==-1)
	{
		return max(idx1,idx2);
	}
	if (!(tr[idx1].flag&tr[idx2].flag))
	{
		if (!tr[idx2].flag)
		{
			swap(idx1,idx2);
		}
		apply(idx2,l,r,0,tr[idx1].sum*power(r-l+1,mod-2,mod)%mod);
		return idx2;
	}
	if (l==r)
	{
		tr[idx1].sum=tr[idx1].sum*tr[idx2].sum%mod;
		return idx1;
	}
	push_down(idx1,l,r);
	push_down(idx2,l,r);
	int mid=l+(r-l)/2;
	tr[idx1].l=merge(tr[idx1].l,tr[idx2].l,l,mid);
	tr[idx1].r=merge(tr[idx1].r,tr[idx2].r,mid+1,r);
	push_up(idx1);
	return idx1;
}
vector<int> graph[N];
int c[N],dp[N],rt[N];
int n;
void DFS(int u,int f)
{
	if(graph[u].size()==1&&u!=1)
	{
		dp[u]=1;
		rt[u]=update(rt[u],1,n,c[u],1);
		apply(rt[u],1,n,dp[u],1);
		return ;
	}
}
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
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