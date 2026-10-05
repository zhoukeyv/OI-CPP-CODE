#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10;
int n,m,a[N],b[N],fa[N],sza[N],szb[N],dp[N]={1},cnt,num[N],id[N];
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
	if (sza[x]+szb[x]>sza[y]+szb[y])
	{
		swap(x,y);
	}
	fa[x]=y;
	sza[y]+=sza[x];
	szb[y]+=szb[x];
	return;
}
void insert(int x)
{
	if (x==0)
	{
		return;
	}
	cnt+=(x>>1);
	for (int j=(n<<1);j>=x;j--)
	{
		dp[j]+=dp[j-x];
		dp[j]%=mod;
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
	for (int j=x;j<=(n<<1);j++)
	{
		dp[j]+=mod-dp[j-x];
		dp[j]%=mod;
	}
	return;
}
void solve()
{
	cin>>n>>m;
	for (int i=1;i<=(n<<1);i++)
	{
		fa[i]=i;
		sza[i]=1;
	}
	for (int i=((n<<1)|1);i<=(n<<2);i++)
	{
		fa[i]=i;
		szb[i]=1;
	}
	for (int i=1;i<=(n<<1);i++)
	{
		insert(2);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for (int i=m;i;i--)
	{
		if (get(a[i])==get(b[i])||get(a[i])==get(b[i]+(n<<1)))
		{
			continue;
		}
		erase(abs(sza[get(a[i])]-szb[get(a[i])])<<1);
		erase(abs(sza[get(b[i]+(n<<1))]-szb[get(b[i]+(n<<1))])<<1);
		insert(abs(sza[get(a[i])]-szb[get(a[i])]+sza[get(b[i]+(n<<1))]-szb[get(b[i]+(n<<1))])<<1);
		if (dp[cnt])
		{
			merge(a[i],b[i]+(n<<1));
			merge(a[i]+(n<<1),b[i]);
		}
		else
		{
			erase(abs(sza[get(a[i])]-szb[get(a[i])]+sza[get(b[i]+(n<<1))]-szb[get(b[i]+(n<<1))])<<1);
			insert(abs(sza[get(a[i])]-szb[get(a[i])]+sza[get(b[i])]-szb[get(b[i])])<<1);
			merge(a[i]+(n<<1),b[i]+(n<<1));
			merge(a[i],b[i]);
		}
	}
	bs[0][0]=1;
	for (int i=1;i<=(n<<1);i++)
	{
		if ((!s.count(get(i)))&&(!s.count(get(i+(n<<1)))))
		{
			num[++num[0]]=get(i);
			bs[num[0]]=bs[num[0]-1]|(bs[num[0]-1]<<(abs(sza[get(i)]-szb[get(i)])<<1));
			s.insert(get(i));
		}
		if (s.count(get(i)))
		{
			id[i]=get(i);
		}
		else
		{
			id[i]=get(i+(n<<1));
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
		cnt2-=abs(sza[get(num[i])]-szb[get(num[i])])<<1;
	}
	for (int i=1;i<=(n<<1);i++)
	{
		if (s.count(get(i))^((bool)(used[get(i)]||used[get(i+(n<<1))]))^1^(sza[id[i]]>szb[id[i]]))
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