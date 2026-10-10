#include<bits/stdc++.h>
using namespace std;
typedef long long int;
const int MAXN=500005;
int n,k;
vector<int> infected;
vector<pair<int,int>> graph[MAXN];
int solve1()
{
	int ans=LLONG_MAX;
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
		for (int c:infected)
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
	int ans=LLONG_MAX;
	for (int u=1;u<=n;++u)
	{
		ans=min(ans,2*dis[u]/g);
	}
	return ans;
}
int solve3()
{
	int K=infected.size();
	vector<vector<int>> dists(K,vector<int>(n+1,0));
	for (int i=0;i<K;++i)
	{
		int src=infected[i];
		vector<bool> vis(n+1,false);
		stack<int> st;
		st.push(src);
		vis[src]=true;
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
					dists[i][v]=dists[i][cur]+w;
					st.push(v);
				}
			}
		}
	}
	int ans=LLONG_MAX;
	for (int u=1;u<=n;++u)
	{
		int sum=0,g=0;
		bool all_zero=true;
		for (int i=0;i<K;++i)
		{
			int d=dists[i][u];
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	infected.resize(k);
	for (int i=0;i<k;++i)
	{
		cin>>infected[i];
	}
	for (int i=0;i<n-1;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	int ans;
	if (n<=2000)
	{
		ans=solve1();
	}
	else if (k==n)
	{
		ans=solve2();
	}
	else if (k<=20)
	{
		ans=solve3();
	}
	else
	{
		ans=solve1();
	}
	cout<<ans<<'\n';
	return 0;
}