#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-6;
const int N=10010,M=1e6+10,BUFSIZE=1<<20;
const int mod=998244353;
char buf[BUFSIZE];
int buf_pos=0,buf_len=0;
int a[M],b[M],fa[M],sz1[M],sz2[M],dp[M],cnt[M],id[M];
bitset<N> bit[N],s;
bitset<M> vis;
int n,m,sz;
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
void solve()
{
	n=read();
	m=read();
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
		erase(abs(sz1[x]-sz2[x])<<1);
		erase(abs(sz1[z]-sz2[z])<<1);
		insert(abs(sz1[x]+sz1[z]-sz2[x]-sz2[z])<<1);
		if (dp[sz]>0)
		{
			merge(a[i],b[i]+(n<<1));
			merge(a[i]+(n<<1),b[i]);
		}
		else
		{
			erase(abs(sz1[x]+sz1[z]-sz2[x]-sz2[z])<<1);
			insert(abs(sz1[x]+sz1[y]-sz2[x]-sz2[y])<<1);
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