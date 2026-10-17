#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=2e6+10;
int s[N],vis[N],w[N];
int n,m;
int read()
{
	int x=0;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void print128(__int128 x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	string s;
	while (x>0)
	{
		s.push_back(char('0'+x%10));
		x/=10;
	}
	reverse(s.begin(),s.end());
	for (char c:s)
	{
		putchar(c);
	}
}
void solve()
{
	n=read();
	m=read();
	for (int i=0;i<n;i++)
	{
		int x=read();
		vis[x]=1;
	}
	for (int i=1;i<=2e6;i++)
	{
		s[i]=s[i-1]+vis[i];
	}
	for (int i=0;i<m;i++)
	{
		int l=read();
		int sum=0;
		for (int j=0;j<l;j++)
		{
			int x=read();
			int cnt=n-s[x];
			sum+=cnt;
		}
		w[i]=sum;
	}
	sort(w,w+m);
	__int128 ans=0;
	ans+=(__int128)m*n*(n+1)/2;
	for (int i=0;i<m;i++)
	{
		ans+=(__int128)w[i]*(m-i);
	}
	print128(ans);
	putchar('\n');
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