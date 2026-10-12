#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1010;
pair<int,int> way[N][N],p[N][N];
int a[N],dp[N][N];
int n;
void update(pair<int,int> i,pair<int,int> j,int v,int x,int y)
{
	if (dp[i.first][i.second]>dp[j.first][j.second]+v)
	{
		dp[i.first][i.second]=dp[j.first][j.second]+v;
		p[i.first][i.second]={x,y};
		way[i.first][i.second]=j;
	}
	return;
}
void solve()
{
	memset(dp,0x3f,sizeof dp);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1][1]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			if (i+2<=n+1)
			{
				update({i+2,j},{i,j},max(a[i],a[i+1]),i,i+1);
				update({i+2,i},{i,j},max(a[i+1],a[j]),i+1,j);
				// dp[i+2][j]=min(dp[i+2][j],dp[i][j]+max(a[i],a[i+1]));
				// dp[i+2][i]=min(dp[i+2][i],dp[i][j]+max(a[i+1],a[j]));
			}
			update({i+1,i+1},{i,j},max(a[i],a[j]),i,j);
			// dp[i+1][i+1]=min(dp[i+1][i+1],dp[i][j]+max(a[i],a[j]));
			cerr<<i<<' '<<j<<':'<<dp[i][j]<<'\n';
		}
		if (i+3<=n+1)
		{
			update({i+3,i},{i,i},max(a[i+1],a[i+2]),i+1,i+2);
			update({i+3,i+1},{i,i},max(a[i],a[i+2]),i,i+2);
			// dp[i+3][i]=min(dp[i+3][i],dp[i][i]+max(a[i+1],a[i+2]));
			// dp[i+3][i+1]=min(dp[i+3][i+1],dp[i][i]+max(a[i],a[i+2]));
		}
		if (i+2<=n+1)
		{
			update({i+2,i+2},{i,i},max(a[i],a[i+1]),i,i+1);
			// dp[i+2][i+2]=min(dp[i+2][i+2],dp[i][i]+max(a[i],a[i+1]));
		}
		cerr<<i<<' '<<i<<':'<<dp[i][i]<<'\n';
	}
	vector<pair<int,int>> t;
	int idx1,idx2;
	if (n%2==0)
	{
		cout<<dp[n+1][n+1]<<'\n';
		idx1=idx2=n+1;
	}
	else
	{
		int ans=inf;
		for (int i=1;i<n;i++)
		{
			if (ans>dp[n+1][i]+a[i])
			{
				t.clear();
				t.push_back({i,0});
				idx1=n+1;
				idx2=i;
				ans=dp[n+1][i]+a[i];
			}
		}
		if (ans>dp[n][n]+a[n])
		{
			t.clear();
			t.push_back({n,0});
			idx1=idx2=n;
			ans=dp[n][n]+a[n];
		}
		cout<<ans<<'\n';
	}
	while (idx1!=1||idx2!=1)
	{
		t.push_back(p[idx1][idx2]);
		pair<int,int> temp=way[idx1][idx2];
		idx1=temp.first;
		idx2=temp.second;
	}
	reverse(t.begin(),t.end());
	for (pair<int,int> i:t)
	{
		cout<<i.first<<' '<<i.second<<'\n';
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