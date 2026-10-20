#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> g[20];
vector<int> conflict[20];// conflict[u] = 距离 u 不超过 2 的其他点
int color[20];
long long ans=0;
void dfs(int u)
{
	if (u>n)
	{
		++ans;
		return;
	}
	for (int c=1;c<=k;c++)
	{
		bool ok=true;
		for (int v:conflict[u])
		{
			if (v<u&&color[v]==c)
			{
				ok=false;
				break;
			}
		}
		if (ok)
		{
			color[u]=c;
			dfs(u+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for (int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// 对每个点 BFS 求距离 <= 2 的点
	for (int s=1;s<=n;s++)
	{
		vector<int> dist(n+1,-1);
		queue<int> q;
		dist[s]=0;
		q.push(s);
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			if (dist[u]>=2)
			{
				continue;
			}
			for (int v:g[u])
			{
				if (dist[v]==-1)
				{
					dist[v]=dist[u]+1;
					q.push(v);
				}
			}
		}
		for (int v=1;v<=n;v++)
		{
			if (v!=s&&dist[v]>=1&&dist[v]<=2)
			{
				conflict[s].push_back(v);
			}
		}
	}
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}