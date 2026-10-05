#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-8;
const int inf=0x3f3f3f3f3f3f3f3f,N=5e5+10;
vector<int> graph[N];
int c[N],sz[N],dp[N];
int n;
void DFS1(int u,int f)
{
	sz[u]=1;
	for (int v:graph[u])
	{
		if (v==f)
		{
			continue;
		}
		DFS1(v,u);
		sz[u]+=sz[v];
	}
	return;
}
void DFS2(int u,int f)
{
	dp[u]=c[u];
	vector<pair<int,int>> temp;
	for (int v:graph[u])
	{
		if (v==f)
		{
			continue;
		}
		DFS2(v,u);
		temp.push_back({2*sz[v]-dp[v],v});
	}
	sort(temp.begin(),temp.end());
	int sum=0;
	for (pair<int,int> i:temp)
	{
		dp[u]=max(dp[u],sum+dp[i.second]+1);
		sum+=sz[i.second]*2;
	}
//	cerr<<u<<':'<<dp[u]<<'\n';
	return;
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
	DFS1(1,-1);
	DFS2(1,-1);
	cout<<max(dp[1],2*(n-1)+c[1])<<'\n';
	return;
}
signed main()
{
//	freopen("farm/farm4.in","r",stdin);
//	freopen("farm/farm.out","w",stdout);
	freopen("farm.in","r",stdin);
	freopen("farm.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TestCase=1;
//	cin>>TestCase;
	for (int CaseId=1;CaseId<=TestCase;CaseId++)
	{
		solve();
	}
	return 0;
}



/*
6
1 8 9 6 3 2
1 3
2 3
3 4
4 5
4 6

11
*/