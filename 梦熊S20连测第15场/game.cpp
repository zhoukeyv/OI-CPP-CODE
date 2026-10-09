#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f;
int a,b;
void solve()
{
	cin>>a>>b;
	int t=max(a,b);
	double ans=(2*t*t-2)*1.0/(4*t*t-2*t);
	cout<<fixed<<setprecision(5)<<ans<<'\n';
	return;
}
signed main()
{
	// freopen("game.in","r",stdin);
	// freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TestCase=1;
	cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}