#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=310,V=2e5+10;
struct Node
{
	int a,id;
	bool operator>(const Node& x)const
	{
		return a>x.a;
	}
}a[N];
vector<int> ans;
bool dp[N][V];
int n;
void solve()
{
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].a;
		a[i].id=i;
		sum+=a[i].a;
	}
	sort(a+1,a+n+1,greater<>());
	dp[0][0]=true;
	int lim=ceil(sum/2.0);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=(int)2e5;j++)
		{
			dp[i][j]=dp[i-1][j];
		}
		for (int j=0;j<lim;j++)
		{
			if (dp[i-1][j]==1)
			{
				dp[i][j+a[i].a]=1;
			}
		}
	}
	int idx=0;
	for (int i=(int)2e5;i>=1;i--)
	{
		if (dp[n][i])
		{
			idx=i;
			break;
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		if (idx>=a[i+1].a&&idx<=m&&dp[i][idx-a[i+1].a]==1)
		{
			ans.push_back(a[i+1].id);
			idx-=a[i+1].a;
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for (int i:ans)
	{
		cout<<i<<' ';
	}
	return;
}
signed main()
{
#ifndef LOCAL_cph
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
#endif
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