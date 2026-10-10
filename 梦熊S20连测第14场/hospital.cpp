#include<bits/stdc++.h>
using namespace std;
typedef long long int;
const int MAXN=500005;
int n,k;
vector<int> a;
vector<pair<int,int>> graph[MAXN];
int solve1()
{
	int ans=inf;
	for (int u=1;u<=n;++u)
	{
		vector<int> dist(n+1,0);
		vector<bool> vis(n+1,false);
		stack<int> st;
		st.push(u);
		vis[u]=true;
		while (!st.empty())
		{
			int cur=st.top();
			st.pop();
			for (pair<int,int> e:graph[cur])
			{
				int v=e.first,w=e.second;
				if (!vis[v])
				{
					vis[v]=true;
					dist[v]=dist[cur]+w;
					st.push(v);
				}
			}
		}
		int sum=0,g=0;
		bool all_zero=true;
		for (int c:a)
		{
			int d=dist[c];
			sum+=d;
			if (d!=0)
			{
				all_zero=false;
			}
			g=__gcd(g,d);
		}
		if (all_zero)
		{
			return 0;
		}
		ans=min(ans,2*sum/g);
	}
	return ans;
}
int solve2()
{
	int g=0;
	for (int u=1;u<=n;++u)
	{
		for (pair<int,int> e:graph[u])
		{
			if (u<e.first)
			{
				g=__gcd(g,(int)e.second);
			}
		}
	}
	vector<int> sz(n+1),dp(n+1),dis(n+1);
	function<void(int,int)> DFS1=[&](int u,int p)
	{
		sz[u]=1;
		for (pair<int,int> e:graph[u])
		{
			int v=e.first,w=e.second;
			if (v==p)
			{
				continue;
			}
			DFS1(v,u);
			sz[u]+=sz[v];
			dp[u]+=dp[v]+(int)sz[v]*w;
		}
	};
	DFS1(1,0);
	function<void(int,int,int)> DFS2=[&](int u,int p,int val)
	{
		dis[u]=val;
		for (pair<int,int> e:graph[u])
		{
			int v=e.first,w=e.second;
			if (v==p)
			{
				continue;
			}
			int nv=val-(int)sz[v]*w+(int)(n-sz[v])*w;
			DFS2(v,u,nv);
		}
	};
	DFS2(1,0,dp[1]);
	int ans=inf;
	for (int u=1;u<=n;++u)
	{
		ans=min(ans,2*dis[u]/g);
	}
	return ans;
}
int main()
{
	freopen("hospital.in","r",stdin);
	freopen("hospital.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	a.resize(k);
	for (int i=0;i<k;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<n-1;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	int ans;
	if (k==n)
	{
		ans=solve2();
	}
	else
	{
		ans=solve1();
	}
	cout<<ans<<'\n';
	return 0;
}