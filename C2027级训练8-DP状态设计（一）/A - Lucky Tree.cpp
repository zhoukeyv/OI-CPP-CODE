#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e5+10;
vector<pair<int,bool>> graph[N];
int n;
bool check(int x)
{
	while (x>0)
	{
		if (x%10!=4&&x%10!=7)
		{
			return false;
		}
		x/=10;
	}
	return true;
}
void solve()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	}
	return;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
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