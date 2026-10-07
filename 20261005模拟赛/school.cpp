#include <bits/stdc++.h>
#define double long double
#define ll long long
using namespace std;
const double eps=1e-6;
const int N=10010,M=1e6+10;
const ll mod=998244353;
int a[M],b[M],fa[M],sz1[M],sz2[M],cnt[M],id[M];
ll dp[M];
bitset<N> bit[N],s;
bitset<M> vis;
int n,m,sz;
int find(int x)
{
	if (fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
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
	sz+=x>>1;
	for (int j=(n<<1);j>=x;j--)
	{
		dp[j]=(dp[j]+dp[j-x])%mod;
	}
	return;
}
void erase(int x)
{
	if (x==0)
	{
		return;
	}
	sz-=x>>1;
	for (int j=x;j<=(n<<1);j++)
	{
		dp[j]=(dp[j]-dp[j-x]+mod)%mod;
	}
	return;
}
void solve()
{
	cin>>n>>m;
	dp[0]=1;
	for (int i=1;i<=(n<<2);i++)
	{
		fa[i]=i;
		if (i<=(n<<1))
		{
			sz1[i]=1;
			insert(2);
		}
		else
		{
			sz2[i]=1;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for (int i=m;i>=1;i--)
	{
		if (find(a[i])==find(b[i])||find(a[i])==find(b[i]+(n<<1)))
		{
			continue;
		}
		erase(abs(sz1[find(a[i])]-sz2[find(a[i])])<<1);
		erase(abs(sz1[find(b[i]+(n<<1))]-sz2[find(b[i]+(n<<1))])<<1);
		insert(abs(sz1[find(a[i])]+sz1[find(b[i]+(n<<1))]-sz2[find(a[i])]-sz2[find(b[i]+(n<<1))])<<1);
		if (dp[sz]>0)
		{
			merge(a[i],b[i]+(n<<1));
			merge(a[i]+(n<<1),b[i]);
		}
		else
		{
			erase(abs(sz1[find(a[i])]+sz1[find(b[i]+(n<<1))]-sz2[find(a[i])]-sz2[find(b[i]+(n<<1))])<<1);
			insert(abs(sz1[find(a[i])]+sz1[find(b[i])]-sz2[find(a[i])]-sz2[find(b[i])])<<1);
			merge(a[i]+(n<<1),b[i]+(n<<1));
			merge(a[i],b[i]);
		}
	}
	bit[0][0]=1;
	for (int i=1;i<=(n<<1);i++)
	{
		if (!s[find(i)]&&!s[find(i+(n<<1))])
		{
			cnt[++cnt[0]]=find(i);
			bit[cnt[0]]=bit[cnt[0]-1]|(bit[cnt[0]-1]<<(abs(sz1[find(i)]-sz2[find(i)])<<1));
			s[find(i)]=true;
		}
		if (s[find(i)])
		{
			id[i]=find(i);
		}
		else
		{
			id[i]=find(i+(n<<1));
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
		cnt2-=abs(sz1[find(cnt[i])]-sz2[find(cnt[i])])<<1;
	}
	for (int i=1;i<=(n<<1);i++)
	{
		cout<<((s.count(find(i))^(vis[find(i)]||vis[find(i+(n<<1))])^(sz1[id[i]]>sz2[id[i]]))^1);
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