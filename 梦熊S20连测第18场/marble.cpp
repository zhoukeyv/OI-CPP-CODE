#include<bits/stdc++.h>
#define ull unsigned long long
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=10005,mod=1e9+7;
ull tbl1[13][256],tbl2[13][256],st1[N],st2[N];
int msk1[101],msk2[101];
int n;
void solve()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int s;
		cin>>s;
		ull l=0,r=0;
		for (int j=0;j<s;j++)
		{
			int c;
			cin>>c;
			if (c<64)
			{
				l|=1ull<<c;
			}
			else
			{
				r|=1ULL<<(c-64);
			}
		}
		st1[i]=l;
		st2[i]=r;
	}
	int ans=0;
	for (int j=1;j<n;j++)
	{
		int present[101]={0};
		ull l=st1[j],r=st2[j];
		for (int c=0;c<=100;c++)
		{
			if (c<64)
			{
				if ((l>>c)&1)
				{
					present[c]=1;
				}
			}
			else
			{
				if ((r>>(c-64))&1)
				{
					present[c]=1;
				}
			}
		}
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
		for (int a=0;a<=100;a++)
		{
			int b=nxt[a];
			msk1[a]=msk2[a]=0;
			if (b!=-1)
			{
				if (b<64)
				{
					msk1[a]=1ULL<<b;
				}
				else
				{
					msk2[a]=1ULL<<(b-64);
				}
			}
		}
		for (int k=0;k<13;k++)
		{
			int s=k*8;
			for (int p=0;p<256;p++)
			{
				ull rl=0,rh=0;
				for (int t=0;t<8;t++)
				{
					if ((p>>t)&1)
					{
						int pos=s+t;
						if (pos<=100)
						{
							rl|=msk1[pos];
							rh|=msk2[pos];
						}
					}
				}
				tbl1[k][p]=rl;
				tbl2[k][p]=rh;
			}
		}
		for (int i=0;i<j;i++)
		{
			ull al=st1[i],ah=st2[i];
			ull rl=0,rh=0;
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
				rl|=tbl1[k][byte];
				rh|=tbl2[k][byte];
			}
			int cnt=__builtin_popcountll(rl)+__builtin_popcountll(rh);
			if (cnt&1)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
	// freopen("marble.in","r",stdin);
	// freopen("marble.out","w",stdout);
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