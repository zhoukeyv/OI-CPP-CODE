#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10;
int a[N],b[N];
int n;
void solve()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	return;
}
signed main()
{
	// freopen("mex.in","r",stdin);
	// freopen("mex.out","w",stdout);
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