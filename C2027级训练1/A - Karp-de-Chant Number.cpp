#include <bits/stdc++.h>
#define double long double
// #define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f,N=310;
struct Node
{
	int bl,br,bsz;
	bool operator<(const Node& x)const
	{
		return br<x.br;
	}
}b[N],c[N];
string a[N];
int l[N],r[N],s[N*N*5],dp[N*N*5];
int n;
void solve()
{
	memset(s,-0x3f,sizeof s);
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		for (char c:a[i])
		{
			if (c=='(')
			{
				l[i]++;
			}
			else
			{
				if (l[i]>0)
				{
					l[i]--;
				}
				else
				{
					r[i]++;
				}
			}
		}
		sum+=l[i];
	}
	int m=0,cnt=0,m1=0;
	for (int i=1;i<=n;i++)
	{
		if (r[i]==0)
		{
			b[++m]={l[i],r[i],(int)a[i].size()};
		}
	}
	if (m==0)
	{
		cout<<"0\n";
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (l[i]!=0&&r[i]!=0&&r[i]>=l[i])
		{
			// cerr<<i<<' ';
			c[++m1]={l[i],r[i],(int)a[i].size()};
		}
	}
	cnt=m1;
	for (int i=1;i<=n;i++)
	{
		if (l[i]!=0&&r[i]!=0&&r[i]<l[i])
		{
			// cerr<<i<<' ';
			c[++cnt]={l[i],r[i],(int)a[i].size()};
		}
	}
	sort(c+1,c+m1+1);
	sort(c+m1+1,c+cnt+1);
	for (int i=1;i<=cnt;i++)
	{
		b[++m]=c[i];
	}
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (l[i]==0&&r[i]!=0)
		{
			b[++m]={l[i],r[i],(int)a[i].size()};
			// cerr<<i<<'\n';
			cnt++;
		}
	}
	if (cnt==0)
	{
		cout<<"0\n";
		return;
	}
	s[0]=0;
	for (int i=1;i<=n;i++)
	{
		memset(dp,-0x3f,sizeof dp);
		for (int j=b[i].br;j<=2*sum;j++)
		{
			dp[j+b[i].bl-b[i].br]=s[j]+b[i].bsz;
		}
		for (int j=0;j<=2*sum;j++)
		{
			if (dp[j]>0)
			{
				// cerr<<i<<' '<<j<<' '<<dp[j]<<'\n';
			}
			s[j]=max(s[j],dp[j]);
		}
	}
	cout<<s[0]<<'\n';
	return;
}
signed main()
{
#ifndef LOCAL_cph
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
#endif
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