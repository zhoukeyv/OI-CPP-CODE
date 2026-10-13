#include<bits/stdc++.h>
using namespace std;
typedef long long int;
const int mod=998244353;
vector<unordered_map<int,int>*> mp;
vector<int> l,a,fa,sz,hev,a,b,ans;
vector<vector<int>> graph,g;
stack<int> st;
int n;
int power(int a,int e)
{
	int res=1;
	while (e)
	{
		if (e&1)
		{
			res=res*a%mod;
		}
		a=a*a%mod;
		e>>=1;
	}
	return res;
}
vector<pair<int,int>> get(int x)
{
	vector<pair<int,int>> res;
	while (x>1)
	{
		int p=l[x];
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
	a.resize(n+1);
	g.resize(n+1);
	fa.resize(n+1);
	hev.resize(n+1);
	sz.resize(n+1,1);
	ans.resize(n+1,1);
	graph.resize(n+1);
	mp.resize(n+1,nullptr);
	l.resize(1e6+10);
	for (int i=2;i<(int)1e6+10;i++)
	{
		if (!l[i])
		{
			l[i]=i;
			for (int j=(int)i*i;j<(int)1e6+10;j+=i)
			{
				if (!l[j])
				{
					l[j]=i;
				}
			}
		}
	}
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	st.push(1);
	fa[1]=-1;
	while (!st.empty())
	{
		int u=st.top();
		st.pop();
		b.push_back(u);
		for (int v:graph[u])
		{
			if (v!=fa[u])
			{
				fa[v]=u;
				g[u].push_back(v);
				st.push(v);
			}
		}
	}
	for (int i=b.size()-1;i>=0;i--)
	{
		int u=b[i];
		int max_sz=0;
		for (int v:g[u])
		{
			sz[u]+=sz[v];
			if (sz[v]>max_sz)
			{
				max_sz=sz[v];
				hev[u]=v;
			}
		}
	}
	for (int i=b.size()-1;i>=0;i--)
	{
		int u=b[i];
		unordered_map<int,int>* cur;
		if (hev[u])
		{
			cur=mp[hev[u]];
			ans[u]=ans[hev[u]];
		}
		else
		{
			cur=new unordered_map<int,int>();
			ans[u]=1;
		}
		for (int v:g[u])
		{
			if (v==hev[u])
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
						ans[u]=ans[u]*power(p,e-old)%mod;
						res.position->second=e;
					}
				}
				else
				{
					ans[u]=ans[u]*power(p,e)%mod;
				}
			}
			delete child;
			mp[v]=nullptr;
		}
		vector<pair<int,int>> fac=get(a[u]);
		for (auto& pr:fac)
		{
			int p=pr.first,e=pr.second;
			auto it=cur->find(p);
			if (it==cur->end())
			{
				(*cur)[p]=e;
				ans[u]=ans[u]*power(p,e)%mod;
			}
			else if (it->second<e)
			{
				int old=it->second;
				ans[u]=ans[u]*power(p,e-old)%mod;
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