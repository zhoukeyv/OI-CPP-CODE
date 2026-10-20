#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=200005,mod=1e9+7;
int a[N],fac[N],infac[N];
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
int C(int a,int b)
{
	if (a<0||b<0||a<b)
	{
		return 0;
	}
	return fac[a]*infac[b]%mod*infac[a-b]%mod;
}
void solve()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=mod;
	}
	int maxN=n+k+5;
	fac[0]=1;
	for (int i=1;i<=maxN;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	infac[maxN]=power(fac[maxN],mod-2,mod);
	for (int i=maxN-1;i>=0;i--)
	{
		infac[i]=infac[i+1]*(i+1)%mod;
	}
	for (int r=1;r<=n;r++)
	{
		int ans=0;
		for (int i=1;i<=r;i++)
		{
			int coef=C(i+k-2,k-1)*C(r-i+k-1,k-1)%mod;
			ans=(ans+a[i]*coef)%mod;
		}
		cout<<ans<<" ";
	}
	cout<<'\n';
	return;
}
signed main()
{
	// freopen("rangesum.in","r",stdin);
	// freopen("rangesum.out","w",stdout);
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