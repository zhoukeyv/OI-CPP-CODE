#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=5010;
int a[N],dp1[2][N],dp2[2][N];
int n,k,mod;
void solve()
{
	cin>>n>>k>>mod;
	dp1[0]=1;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		long long q=a[i]/k;
		int ra=a[i]%k;
		vector<long long> ndp(k,0),nf(k,0);
		for (int r=0;r<k;++r)
		{
			if (dp[r]==0&&f[r]==0)
			{
				continue;
			}
			ndp[r]=(ndp[r]+dp[r])%mod;
			nf[r]=(nf[r]+f[r])%mod;
			int nr=(r+ra)%k;
			long long carry=(r+ra>=k)?1:0;
			ndp[nr]=(ndp[nr]+dp[r])%mod;
			nf[nr]=(nf[nr]+f[r]+dp[r]*((q+carry)%mod))%mod;
		}
		dp1=move(ndp);
		dp2=move(nf);
	}
	long long ans=0;
	for (int i=0;i<k;i++)
	{
		ans=(ans+dp2[i])%mod;
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
	// freopen("divide.in","r",stdin);
	// freopen("divide.out","w",stdout);
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