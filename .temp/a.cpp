#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
const int MAXA=1000005;
int n;
vector<int> a;
vector<vector<int>> adj;
vector<int> spf(MAXA);// 最小质因数
ll modpow(ll a,ll e)
{
	ll res=1;
	while (e)
	{
		if (e&1)
		{
			res=res*a%MOD;
		}
		a=a*a%MOD;
		e>>=1;
	}
	return res;
}
// 分解质因数
vector<pair<int,int>> factorize(int x)
{
	vector<pair<int,int>> res;
	while (x>1)
	{
		int p=spf[x];
		int e=0;
		while (x%p==0)
		{
			x/=p;
			e++;
		}
		res.emplace_back(p,e);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// 线性筛预处理最小质因数
	for (int i=2;i<MAXA;i++)
	{
		if (!spf[i])
		{
			spf[i]=i;
			for (ll j=(ll)i*i;j<MAXA;j+=i)
			{
				if (!spf[j])
				{
					spf[j]=i;
				}
			}
		}
	}
	cin>>n;
	a.resize(n+1);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	adj.resize(n+1);
	for (int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// 迭代后序遍历建树，确定父子关系和重儿子
	vector<int> parent(n+1,0),order;
	vector<vector<int>> children(n+1);
	stack<int> st;
	st.push(1);
	parent[1]=-1;
	while (!st.empty())
	{
		int u=st.top();
		st.pop();
		order.push_back(u);
		for (int v:adj[u])
		{
			if (v!=parent[u])
			{
				parent[v]=u;
				children[u].push_back(v);
				st.push(v);
			}
		}
	}
	vector<int> sz(n+1,1),heavy(n+1,0);
	for (int i=order.size()-1;i>=0;i--)
	{
		int u=order[i];
		int max_sz=0;
		for (int v:children[u])
		{
			sz[u]+=sz[v];
			if (sz[v]>max_sz)
			{
				max_sz=sz[v];
				heavy[u]=v;
			}
		}
	}
	vector<unordered_map<int,int>*> mp(n+1,nullptr);
	vector<ll> ans(n+1,1);
	// 后序遍历处理每个节点
	for (int i=order.size()-1;i>=0;i--)
	{
		int u=order[i];
		unordered_map<int,int>* cur;
		if (heavy[u])
		{
			cur=mp[heavy[u]];
			ans[u]=ans[heavy[u]];
		}
		else
		{
			cur=new unordered_map<int,int>();
			ans[u]=1;
		}
		for (int v:children[u])
		{
			if (v==heavy[u])
			{
				continue;
			}
			unordered_map<int,int>* child=mp[v];
			for (auto it=child->begin();it!=child->end();)
			{
				auto node=child->extract(it++);
				int p=node.key();
				int e=node.mapped();
				auto res=cur->insert(std::move(node));
				if (!res.inserted)
				{
					if (res.position->second<e)
					{
						int old=res.position->second;
						ans[u]=ans[u]*modpow(p,e-old)%MOD;
						res.position->second=e;
					}
				}
				else
				{
					ans[u]=ans[u]*modpow(p,e)%MOD;
				}
			}
			delete child;
			mp[v]=nullptr;
		}
		vector<pair<int,int>> fac=factorize(a[u]);
		for (auto& pr:fac)
		{
			int p=pr.first,e=pr.second;
			auto it=cur->find(p);
			if (it==cur->end())
			{
				(*cur)[p]=e;
				ans[u]=ans[u]*modpow(p,e)%MOD;
			}
			else if (it->second<e)
			{
				int old=it->second;
				ans[u]=ans[u]*modpow(p,e-old)%MOD;
				it->second=e;
			}
		}
		mp[u]=cur;
	}
	for (int i=1;i<=n;i++)
	{
		cout<<ans[i]<<'\n';
	}
	return 0;
}