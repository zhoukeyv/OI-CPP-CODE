#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int s[N],vis[N];
int n,m;
inline int read()
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
int main()
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
	vector<ll> w(m,0);
	for (int i=0;i<m;i++)
	{
		int l=read();
		ll sum=0;
		for (int j=0;j<l;j++)
		{
			int x=read();
			int cnt=n-s[x];
			sum+=cnt;
		}
		w[i]=sum;
	}
	sort(w.begin(),w.end());
	__int128 ans=0;
	ans+=(__int128)m*n*(n+1)/2;
	for (int i=0;i<m;i++)
	{
		ans+=(__int128)w[i]*(m-i);
	}
	print128(ans);
	putchar('\n');
	return 0;
}