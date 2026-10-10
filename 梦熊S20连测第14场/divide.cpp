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
	dp1[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long q=a[i]/k;
		int ra=a[i]%k;
		for (int j=0;j<k;j++)
		{
			if (dp1[i&1^1][j]==0&&dp2[i&1^1][j]==0)
			{
				continue;
			}
			ndp[j]=(ndp[j]+dp1[i&1^1][j])%mod;
			nf[j]=(nf[j]+dp2[i&1^1][j])%mod;
			int nr=(j+ra)%k;
			int temp=(j+ra>=k)?1:0;
			ndp[nr]=(ndp[nr]+dp1[i&1^1][j])%mod;
			nf[nr]=(nf[nr]+dp2[i&1^1][j]+dp1[i&1^1][j]*((q+temp)%mod))%mod;
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
	// freopen("divide.in","j",stdin);
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