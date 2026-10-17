#include <bits/stdc++.h>
#define ull unsigned long long
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MAXN=2000005;
const int MAXM=1<<20;
int a[MAXN];
int cnt[MAXM+5];
int tch[MAXN+5];
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
void print_u64(ull x)
{
	if (x==0)
	{
		putchar('0');
		return;
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
	int n=read();
	for (int i=0;i<n;i++)
	{
		a[i]=read();
	}
	ull sum=(ull)n*(n+1)/2;
	ull ans=0;
	for (int b=0;b<=20;b++)
	{
		int M=1<<b;
		ull cnt0=0;
		ull c=0;
		int st=0;
		for (int i=0;i<=n;i++)
		{
			if (i==n||(a[i]&(1<<b)))
			{
				int len=i-st;
				cnt0+=(ull)len*(len+1)/2;
				if (len>=M)
				{
					int L=st;
					int mss=M;
					int top=0;
					for (int R=st;R<i;R++)
					{
						int x=a[R];
						if (x<M)
						{
							if (cnt[x]==0)
							{
								mss--;
								tch[top++]=x;
							}
							cnt[x]++;
						}
						while (mss==0)
						{
							int y=a[L];
							if (y<M)
							{
								if (cnt[y]==1)
								{
									break;
								}
								cnt[y]--;
							}
							L++;
						}
						if (mss==0)
						{
							c+=(ull)(L-st+1);
						}
					}
					for (int j=0;j<top;j++)
					{
						cnt[tch[j]]=0;
					}
				}
				st=i+1;
			}
		}
		ans+=(ull)(1ULL<<b)*(sum-cnt0+c);
	}
	for (int b=21;b<=29;b++)
	{
		ull cnt0=0;
		int st=0;
		for (int i=0;i<=n;i++)
		{
			if (i==n||(a[i]&(1<<b)))
			{
				int len=i-st;
				cnt0+=(ull)len*(len+1)/2;
				st=i+1;
			}
		}
		ans+=(ull)(1ULL<<b)*(sum-cnt0);
	}
	print_u64(ans);
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