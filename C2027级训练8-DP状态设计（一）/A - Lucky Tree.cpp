#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e5+10;
vector<pair<int,bool>> graph[N];
int sz[N],t1[N],t2[N];
int n;
bool check(int x)
{
	while (x>0)
	{
		if (x%10!=4&&x%10!=7)
		{
			return false;
		}
		x/=10;
	}
	return true;
}
void DFS1(int u,int f)
{
	sz[u]=1;
	for (pair<int,int> v:graph[u])
	{
		if (v.first==f)
		{
			continue;
		}
		DFS1(v.first,u);
		sz[u]+=sz[v.first];
	}
	return;
}
void DFS2(int u,int f)
{
	for (pair<int,int> v:graph[u])
	{
		if (v.first==f)
		{
			continue;
		}
		DFS2(v.first,u);
		if (v.second)
		{
			t1[u]+=sz[v.first];
		}
		else
		{
			t1[u]+=t1[v.first];
		}
	}
	return;
}
void DFS3(int u,int f)
{
	for (pair<int,int> v:graph[u])
	{
		if (v.first==f)
		{
			continue;
		}
		if (v.second)
		{
			t2[v.first]=n-sz[v.first];
		}
		else
		{
			t2[v.first]=t2[u]+t1[u]-(v.second?sz[v.first]:t1[v.first]);
		}
		DFS3(v.first,u);
	}
	return;
}
void solve()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,check(w)});
		graph[v].push_back({u,check(w)});
	}
	DFS1(1,-1);
	DFS2(1,-1);
	DFS3(1,-1);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ans+=(t1[i]+t2[i])*(t1[i]+t2[i]-1);
	}
	cout<<ans<<'\n';
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