#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,mod=998244353;
vector<unordered_map<int,int>*> mp;
vector<int> l,a,fa,sz,hev,b,ans;
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
		res.push_back({p,e});
	}
	return res;
}
void solve()
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
			for (auto it=child->begin();it!=child->end();++it)
			{
				int p=it->first;
				int e=it->second;
				auto res=cur->insert({p,e});
				if (!res.second)
				{
					if (res.first->second<e)
					{
						int old=res.first->second;
						ans[u]=ans[u]*power(p,e-old)%mod;
						res.first->second=e;
					}
				}
				else
				{
					ans[u]=ans[u]*power(p,e)%mod;
				}
			}
			child->clear();
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
	return;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
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