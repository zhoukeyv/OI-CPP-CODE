#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,k;
	long long p;
	cin>>N>>k>>p;
	vector<long long> dp(k,0),f(k,0);
	dp[0]=1;
	for (int i=0;i<N;++i)
	{
		long long a;
		cin>>a;
		long long q=a/k;
		int ra=a%k;
		vector<long long> ndp(k,0),nf(k,0);
		for (int r=0;r<k;++r)
		{
			if (dp[r]==0&&f[r]==0)
			{
				continue;
			}
			ndp[r]=(ndp[r]+dp[r])%p;
			nf[r]=(nf[r]+f[r])%p;
			int nr=(r+ra)%k;
			long long carry=(r+ra>=k)?1:0;
			ndp[nr]=(ndp[nr]+dp[r])%p;
			nf[nr]=(nf[nr]+f[r]+dp[r]*((q+carry)%p))%p;
		}
		dp=move(ndp);
		f=move(nf);
	}
	long long ans=0;
	for (int r=0;r<k;++r)
	{
		ans=(ans+f[r])%p;
	}
	cout<<ans<<'\n';
	return 0;
}