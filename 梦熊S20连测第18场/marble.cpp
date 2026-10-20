#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=10005,mod=1e9+7;
int n;
unsigned long long setsL[N],setsH[N];
int maskL[101],maskH[101];
unsigned long long tblL[13][256],tblH[13][256];
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
void solve()
{
	n=read();
	for (int i=0;i<n;i++)
	{
		int s=read();
		unsigned long long lo=0,hi=0;
		for (int j=0;j<s;j++)
		{
			int c=read();
			if (c<64)
			{
				lo|=1ULL<<c;
			}
			else
			{
				hi|=1ULL<<(c-64);
			}
		}
		setsL[i]=lo;
		setsH[i]=hi;
	}
	long long ans=0;
	for (int j=1;j<n;j++)
	{
		// 提取 B = C_j
		int present[101]={0};
		unsigned long long lo=setsL[j],hi=setsH[j];
		for (int c=0;c<=100;c++)
		{
			if (c<64)
			{
				if ((lo>>c)&1)
				{
					present[c]=1;
				}
			}
			else
			{
				if ((hi>>(c-64))&1)
				{
					present[c]=1;
				}
			}
		}
		// nxt[a] = B 中 >= a 的最小坑位置，不存在则为 -1
		int nxt[101];
		int last=-1;
		for (int a=100;a>=0;a--)
		{
			if (present[a])
			{
				last=a;
			}
			nxt[a]=last;
		}
		// mask[a] 表示球在 a 时会落入哪个坑
		for (int a=0;a<=100;a++)
		{
			int b=nxt[a];
			maskL[a]=maskH[a]=0;
			if (b!=-1)
			{
				if (b<64)
				{
					maskL[a]=1ULL<<b;
				}
				else
				{
					maskH[a]=1ULL<<(b-64);
				}
			}
		}
		// 对当前 B 建 8 位分块表
		for (int k=0;k<13;k++)
		{
			int s=k*8;
			for (int p=0;p<256;p++)
			{
				unsigned long long rl=0,rh=0;
				for (int t=0;t<8;t++)
				{
					if ((p>>t)&1)
					{
						int pos=s+t;
						if (pos<=100)
						{
							rl|=maskL[pos];
							rh|=maskH[pos];
						}
					}
				}
				tblL[k][p]=rl;
				tblH[k][p]=rh;
			}
		}
		// 枚举所有 i < j
		for (int i=0;i<j;i++)
		{
			unsigned long long al=setsL[i],ah=setsH[i];
			unsigned long long rl=0,rh=0;
			for (int k=0;k<13;k++)
			{
				int byte;
				if (k<8)
				{
					byte=(al>>(8*k))&0xFF;
				}
				else
				{
					byte=(ah>>(8*(k-8)))&0xFF;
				}
				rl|=tblL[k][byte];
				rh|=tblH[k][byte];
			}
			int cnt=__builtin_popcountll(rl)+__builtin_popcountll(rh);
			if (cnt&1)
			{
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
signed main()
{
	// freopen("color.in", "r", stdin);
	// freopen("color.out", "w", stdout);
	int TestCase=1;
	// cin >> TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}