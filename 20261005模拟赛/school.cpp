#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10;
int a[N],b[N],fa[N],sz1[N],sz2[N],dp[N],cnt[N],id[N];
bitset<10010> bit[10010];
bool vis[N];
int n,m,sz;
set<int> s;
int find(int x)
{
	if (fa[x]==x)
	{
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	{
		return;
	}
	if (sz1[x]+sz2[x]>sz1[y]+sz2[y])
	{
		swap(x,y);
	}
	fa[x]=y;
	sz1[y]+=sz1[x];
	sz2[y]+=sz2[x];
	return;
}
void insert(int x)
{
	if (x==0)
	{
		return;
	}
	sz+=x/2;
	for (int j=2*n;j>=x;j--)
	{
		dp[j]+=dp[j-x];
	}
	return;
}
void erase(int x)
{
	if (x==0)
	{
		return;
	}
	sz-=x/2;
	for (int j=x;j<=2*n;j++)
	{
		dp[j]-=dp[j-x];
	}
	return;
}
void solve()
{
	cin>>n>>m;
	dp[0]=1;
	for (int i=1;i<=4*n;i++)
	{
		fa[i]=i;
		if (i<=2*n)
		{
			sz1[i]=1;
		}
		else
		{
			sz2[i]=1;
		}
	}
	for (int i=1;i<=2*n;i++)
	{
		insert(2);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for (int i=m;i>=1;i--)
	{
		if (find(a[i])==find(b[i])||find(a[i])==find(b[i]+2*n))
		{
			continue;
		}
		erase(2*abs(sz1[find(a[i])]-sz2[find(a[i])]));
		erase(2*abs(sz1[find(b[i]+2*n)]-sz2[find(b[i]+2*n)]));
		insert(2*abs(sz1[find(a[i])]-sz2[find(a[i])]+sz1[find(b[i]+2*n)]-sz2[find(b[i]+2*n)]));
		if (dp[sz]>0)
		{
			merge(a[i],b[i]+2*n);
			merge(a[i]+2*n,b[i]);
		}
		else
		{
			erase(2*abs(sz1[find(a[i])]-sz2[find(a[i])]+sz1[find(b[i]+2*n)]-sz2[find(b[i]+2*n)]));
			insert(2*abs(sz1[find(a[i])]-sz2[find(a[i])]+sz1[find(b[i])]-sz2[find(b[i])]));
			merge(a[i]+2*n,b[i]+2*n);
			merge(a[i],b[i]);
		}
	}
	bit[0][0]=1;
	for (int i=1;i<=2*n;i++)
	{
		if ((!s.count(find(i)))&&(!s.count(find(i+2*n))))
		{
			cnt[++cnt[0]]=find(i);
			bit[cnt[0]]=bit[cnt[0]-1]|(bit[cnt[0]-1]<<(abs(sz1[find(i)]-sz2[find(i)])<<1));
			s.insert(find(i));
		}
		if (s.count(find(i)))
		{
			id[i]=find(i);
		}
		else
		{
			id[i]=find(i+2*n);
		}
	}
	int cnt2=sz;
	for (int i=cnt[0];i>=1;i--)
	{
		if (bit[i-1][cnt2])
		{
			continue;
		}
		vis[cnt[i]]=true;
		cnt2-=2*abs(sz1[find(cnt[i])]-sz2[find(cnt[i])]);
	}
	for (int i=1;i<=2*n;i++)
	{
		if ((s.count(find(i))+(vis[find(i)]||vis[find(i+2*n)])+1+(sz1[id[i]]>sz2[id[i]]))%2==1)
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	cout<<'\n';
	return;
}
signed main()
{
//	freopen("school.in","r",stdin);
//	freopen("school.out","w",stdout);
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