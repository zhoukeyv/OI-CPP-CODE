#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=5e5+10;
vector<int> graph[N];
int fac[N],infac[N];
int n,k;
void solve()
{
	cin>>n>>k;
	fac[0]=1;
	for (int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	return;
}
signed main()
{
	// freopen("color.in","r",stdin);
	// freopen("color.out","w",stdout);
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