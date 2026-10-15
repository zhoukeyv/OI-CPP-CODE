#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<pair<int,int>>> graph;
vector<vector<int>> dcc;
vector<int> dfn,low;
vector<bool> vis;
stack<int> st;
int n,m,cnt=0,k=2;
void tarjan(int u,int in)
{
	low[u]=dfn[u]=++cnt;
	st.push(u);
	vis[u]=true;
	for (pair<int,int> x:graph[u])
	{
		int v=x.first,i=x.second;
		if (i==(in^1))
		{
			continue;
		}
		if (!dfn[v])
		{
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
		}
		else if (vis[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if (dfn[u]==low[u])
	{
		dcc.push_back({u});
		while (st.top()!=u)
		{
			dcc[dcc.size()-1].push_back(st.top());
			vis[st.top()]=false;
			st.pop();
		}
		st.pop();
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	dfn.resize(n+1,0);
	low.resize(n+1,0);
	graph.resize(n+1);
	vis.resize(n+1,false);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		if (u!=v)
		{
			graph[u].push_back({v,k++});
			graph[v].push_back({u,k++});
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!dfn[i])
		{
			tarjan(i,0);
		}
	}
	cout<<dcc.size()<<'\n';
	for (vector<int> i:dcc)
	{
		cout<<i.size()<<' ';
		for (int j:i)
		{
			cout<<j<< ' ';
		}
		cout<<'\n';
	}
	return 0;
}