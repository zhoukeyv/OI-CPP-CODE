#include<bits/stdc++.h>
#define double long double
#define ll long long
using namespace std;
const double eps=1e-6;
const int N=20010,M=1e6+10,BUFSIZE=1<<20;
const ll mod=998244353;
char buf[BUFSIZE];
int buf_pos=0,buf_len=0;
int a[M],b[M],fa[N],sz1[N],sz2[N],cnt[N],id[N];
ll fac[N],infac[N];
int dp[N];
bitset<N> bit[N],vis,s;
int n,m,sz;
ll power(ll a,int b,ll p)
{
	ll res=1;
	while (b)
	{
		if (b&1)
		{
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int C(int a,int b)
{
	if (a<0||b<0||a<b)
	{
		return 0;
	}
	return fac[a]*infac[b]%mod*infac[a-b]%mod;
}
char getChar()
{
	if (buf_pos==buf_len)
	{
		buf_len=fread(buf,1,BUFSIZE,stdin);
		buf_pos=0;
		if (buf_len==0)
		{
			return 0;
		}
	}
	return buf[buf_pos++];
}
int read()
{
	char c=getChar();
	while (c<=' ')
	{
		if (!c)
		{
			return 0;
		}
		c=getChar();
	}
	bool neg=false;
	if (c=='-')
	{
		neg=true;
		c=getChar();
	}
	int x=0;
	while (c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getChar();
	}
	return neg?-x:x;
}
int find(int x)
{
	int res=x;
	while (fa[res]!=res)
	{
		res=fa[res];
	}
	while (fa[x]!=res)
	{
		int t=fa[x];
		fa[x]=res;
		x=t;
	}
	return res;
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
		dp[j]+=dp[j-x];
		if (dp[j]>=mod)
		{
			dp[j]-=mod;
		}
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
		dp[j]-=dp[j-x];
		if (dp[j]<0)
		{
			dp[j]+=mod;
		}
	}
	return;
}
int Abs(int x)
{
	return x<0?-x:x;
}
void solve()
{
	n=read();
	m=read();
	dp[0]=1;
	fac[0]=1;
	for (int i=1;i<=(n<<2);i++)
	{
		fa[i]=i;
		fac[i]=fac[i-1]*i%mod;
		if (i<=(n<<1))
		{
			sz1[i]=1;
		}
		else
		{
			sz2[i]=1;
		}
	}
	infac[n<<2]=power(fac[n<<2],mod-2,mod);
	for (int i=(n<<2)-1;i>=0;i--)
	{
		infac[i]=infac[i+1]*(i+1)%mod;
	}
	for (int i=1;i<=n;i++)
	{
		dp[i<<1]=C(n<<1,i);
		sz++;
	}
	for (int i=1;i<=m;i++)
	{
		a[i]=read();
		b[i]=read();
	}
	for (int i=m;i>=1;i--)
	{
		int x=find(a[i]),y=find(b[i]),z=find(b[i]+(n<<1));
		if (x==y||x==z)
		{
			continue;
		}
		erase(Abs(sz1[x]-sz2[x])<<1);
		erase(Abs(sz1[z]-sz2[z])<<1);
		insert(Abs(sz1[x]+sz1[z]-sz2[x]-sz2[z])<<1);
		if (dp[sz]>0)
		{
			merge(a[i],b[i]+(n<<1));
			merge(a[i]+(n<<1),b[i]);
		}
		else
		{
			erase(Abs(sz1[x]+sz1[z]-sz2[x]-sz2[z])<<1);
			insert(Abs(sz1[x]+sz1[y]-sz2[x]-sz2[y])<<1);
			merge(a[i]+(n<<1),b[i]+(n<<1));
			merge(a[i],b[i]);
		}
	}
	bit[0][0]=1;
	for (int i=1;i<=(n<<1);i++)
	{
		int x=find(i),y=find(i+(n<<1));
		if (!s[x]&&!s[y])
		{
			cnt[++cnt[0]]=x;
			bit[cnt[0]]=bit[cnt[0]-1]|(bit[cnt[0]-1]<<(Abs(sz1[x]-sz2[x])<<1));
			s[x]=true;
		}
		if (s[x])
		{
			id[i]=x;
		}
		else
		{
			id[i]=y;
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
		cnt2-=Abs(sz1[find(cnt[i])]-sz2[find(cnt[i])])<<1;
	}
	for (int i=1;i<=(n<<1);i++)
	{
		putchar('0'+((s[find(i)]^(vis[find(i)]||vis[find(i+(n<<1))])^(sz1[id[i]]>sz2[id[i]]))^1));
	}
	puts("");
	return;
}
signed main()
{
	//	freopen("school.in","r",stdin);
	//	freopen("school.out","w",stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int TestCase=1;
	// cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}