#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10,V=2e6+10;
unordered_map<int,int> um1[V];
set<pair<int,int>> pq;
int a[N],l[N],r[N],t[N],vis[N],inpl[N];
int n,m;
void erase(int pos)
{
	if (pos<1||pos>n)
	{
		return;
	}
	if (inpl[pos])
	{
		pq.erase({inpl[pos],pos});
		inpl[pos]=0;
	}
	return;
}
void insert(int pos)
{
	if (pos<1||pos>=n)
	{
		return;
	}
	if (r[pos]==-1)
	{
		return;
	}
	int x=a[pos],y=a[r[pos]];
	unordered_map<int,int>::iterator it=um1[x].find(y);
	if (it!=um1[x].end())
	{
		int j=it->second;
		if (inpl[pos])
		{
			pq.erase({inpl[pos],pos});
		}
		pq.insert({j,pos});
		inpl[pos]=j;
	}
	else
	{
		if (inpl[pos])
		{
			pq.erase({inpl[pos],pos});
			inpl[pos]=0;
		}
	}
	return;
}
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if (!um1[x].count(y))
		{
			um1[x][y]=i;
		}
		t[i]=z;
	}
	for (int i=1;i<=n;i++)
	{
		l[i]=i-1;
		r[i]=i+1;
	}
	l[1]=-1;
	r[n]=-1;
	for (int i=1;i<n;i++)
	{
		insert(i);
	}
	while (!pq.empty())
	{
		set<pair<int,int>>::iterator it=pq.begin();
		int j=it->first;
		int cur=it->second;
		pq.erase(it);
		inpl[cur]=0;
		int idx=r[cur];
		if (idx==-1)
		{
			continue;
		}
		erase(idx);
		if (l[cur]!=-1)
		{
			erase(l[cur]);
		}
		r[cur]=r[idx];
		if (r[idx]!=-1)
		{
			l[r[idx]]=cur;
		}
		vis[idx]=1;
		a[cur]=t[j];
		if (l[cur]!=-1)
		{
			insert(l[cur]);
		}
		if (r[cur]!=-1)
		{
			insert(cur);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==0)
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==0)
		{
			cout<<a[i]<<' ';
		}
	}
	cout<<'\n';
	return;
}
signed main()
{
	// freopen("nlp.in","r",stdin);
	// freopen("nlp.out","w",stdout);
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