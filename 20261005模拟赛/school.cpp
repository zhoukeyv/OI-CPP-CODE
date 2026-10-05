#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10;
int n,m,a[N],b[N],fa[N],sz1[N],sz2[N],dp[N]={1},cnt,num[N],id[N];
bool used[N];
bitset<10010> bs[10010];
set<int> s;
int get(int x)
{
	if (fa[x]==x)
	{
		return x;
	}
	fa[x]=get(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	x=get(x);
	y=get(y);
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
	cnt+=(x>>1);
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
	cnt-=(x>>1);
	for (int j=x;j<=2*n;j++)
	{
		dp[j]-=dp[j-x];
	}
	return;
}
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=2*n;i++)
	{
		fa[i]=i;
		sz1[i]=1;
	}
	for (int i=(2*n|1);i<=(n<<2);i++)
	{
		fa[i]=i;
		sz2[i]=1;
	}
	for (int i=1;i<=2*n;i++)
	{
		insert(2);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for (int i=m;i;i--)
	{
		if (get(a[i])==get(b[i])||get(a[i])==get(b[i]+2*n))
		{
			continue;
		}
		erase(2*abs(sz1[get(a[i])]-sz2[get(a[i])]));
		erase(2*abs(sz1[get(b[i]+2*n)]-sz2[get(b[i]+2*n)]));
		insert(2*abs(sz1[get(a[i])]-sz2[get(a[i])]+sz1[get(b[i]+2*n)]-sz2[get(b[i]+2*n)]));
		if (dp[cnt])
		{
			merge(a[i],b[i]+2*n);
			merge(a[i]+2*n,b[i]);
		}
		else
		{
			erase(2*abs(sz1[get(a[i])]-sz2[get(a[i])]+sz1[get(b[i]+2*n)]-sz2[get(b[i]+2*n)]));
			insert(2*abs(sz1[get(a[i])]-sz2[get(a[i])]+sz1[get(b[i])]-sz2[get(b[i])]));
			merge(a[i]+2*n,b[i]+2*n);
			merge(a[i],b[i]);
		}
	}
	bs[0][0]=1;
	for (int i=1;i<=2*n;i++)
	{
		if ((!s.count(get(i)))&&(!s.count(get(i+2*n))))
		{
			num[++num[0]]=get(i);
			bs[num[0]]=bs[num[0]-1]|(bs[num[0]-1]<<(abs(sz1[get(i)]-sz2[get(i)])<<1));
			s.insert(get(i));
		}
		if (s.count(get(i)))
		{
			id[i]=get(i);
		}
		else
		{
			id[i]=get(i+2*n);
		}
	}
	int cnt2=cnt;
	for (int i=num[0];i;i--)
	{
		if (bs[i-1][cnt2])
		{
			continue;
		}
		used[num[i]]=true;
		cnt2-=abs(sz1[get(num[i])]-sz2[get(num[i])])<<1;
	}
	for (int i=1;i<=2*n;i++)
	{
		if (s.count(get(i))^((bool)(used[get(i)]||used[get(i+2*n)]))^1^(sz1[id[i]]>sz2[id[i]]))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
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