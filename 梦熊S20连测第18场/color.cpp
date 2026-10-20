#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=5e5+10,mod=1e9+7;
vector<int> graph[N];
int fac[N],infac[N];
int n,k;
int power(int a,int b,int p)
{
	int res=1;
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
int A(int a,int b)
{
	if (a<0||b<0||a<b)
	{
		return 0;
	}
	return fac[a]*infac[a-b]%mod;
}
void solve()
{
	cin>>n>>k;
	fac[0]=1;
	for (int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	infac[n]=power(fac[n],mod-2,mod);
	for (int i=n-1;i>=0;i--)
	{
		infac[i]=infac[i+1]*(i+1)%mod;
	}
	for (int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int ans=k*A(k-1,(int)graph[1].size())%mod;
	for (int i=2;i<=n;i++)
	{
		ans=ans*A(k-2,(int)graph[i].size()-1)%mod;
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
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