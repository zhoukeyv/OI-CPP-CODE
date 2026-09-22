#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18;
set<char> st;
string s;
int n;
void solve()
{
	cin>>n>>s;
	s='@'+s;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ans+=st.size();
		st.insert(s[i]);
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
#ifndef LOCAL_cph
	freopen("remove.in","r",stdin);
	freopen("remove.out","w",stdout);
#endif
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