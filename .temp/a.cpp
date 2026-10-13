#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	ll l,r;
	bool operator<(const Node& other)const
	{
		return l<other.l;
	}
};
ll insert(vector<Node>& painted,ll l,ll r)
{
	if (l>r)
	{
		return 0;
	}
	vector<Node> all;
	for (auto& seg:painted)
	{
		all.push_back(seg);
	}
	all.push_back({l,r});
	sort(all.begin(),all.end());
	vector<Node> merged;
	for (auto& seg:all)
	{
		if (merged.empty()||merged.back().r+1<seg.l)
		{
			merged.push_back(seg);
		}
		else
		{
			merged.back().r=max(merged.back().r,seg.r);
		}
	}
	ll old_len=0;
	for (auto& seg:painted)
	{
		old_len+=seg.r-seg.l+1;
	}
	ll new_len=0;
	for (auto& seg:merged)
	{
		new_len+=seg.r-seg.l+1;
	}
	painted=move(merged);
	return new_len-old_len;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<ll> p(n);
	for (int i=0;i<n;++i)
	{
		cin>>p[i];
	}
	vector<ll> l(m);
	for (int i=0;i<m;++i)
	{
		cin>>l[i];
	}
	vector<ll> cur=p;
	vector<ll> ans(n,0);
	vector<Node> painted;
	vector<int> order(n);
	iota(order.begin(),order.end(),0);
	sort(order.begin(),order.end(),[&](int a,int b)
		 {return p[a]>p[b];});
	for (int step=0;step<m;++step)
	{
		ll delta=l[step];
		vector<pair<ll,ll>> moves(n);
		for (int i=0;i<n;++i)
		{
			ll old_pos=cur[i];
			ll new_pos=old_pos+delta;
			cur[i]=new_pos;
			ll lo=min(old_pos,new_pos);
			ll hi=max(old_pos,new_pos);
			moves[i]={lo,hi};
		}
		for (int idx:order)
		{
			ll lo=moves[idx].first;
			ll hi=moves[idx].second;
			ll new_len=insert(painted,lo,hi);
			ans[idx]+=new_len;
		}
	}
	for (int i=0;i<n;++i)
	{
		cout<<ans[i]<<"\n";
	}
}
int main()
{
	// freopen("paint.in","r",stdin);
	// freopen("paint.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}