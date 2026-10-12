#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1010;
pair<int,int> way[N][N];
int a[N],dp[N][N];
int n;
void update(pair<int,int> i,pair<int,int> j,int v)
{
	if (dp[i.first][i.second]>dp[j.first][j.second]+v)
	{
		dp[i.first][i.second]=dp[j.first][j.second]+v;
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
				update({i+2,j},{i,j},max(a[i],a[i+1]));
				update({i+2,i},{i,j},max(a[i+1],a[j]));
				// dp[i+2][j]=min(dp[i+2][j],dp[i][j]+max(a[i],a[i+1]));
				// dp[i+2][i]=min(dp[i+2][i],dp[i][j]+max(a[i+1],a[j]));
			}
			update({i+1,i+1},{i,j},max(a[i],a[j]));
			// dp[i+1][i+1]=min(dp[i+1][i+1],dp[i][j]+max(a[i],a[j]));
			cerr<<i<<' '<<j<<':'<<dp[i][j]<<'\n';
		}
		if (i+3<=n+1)
		{
			update({i+3,i},{i,i},max(a[i+1],a[i+2]));
			update({i+3,i+1},{i,i},max(a[i],a[i+2]));
			// dp[i+3][i]=min(dp[i+3][i],dp[i][i]+max(a[i+1],a[i+2]));
			// dp[i+3][i+1]=min(dp[i+3][i+1],dp[i][i]+max(a[i],a[i+2]));
		}
		if (i+2<=n+1)
		{
			update({i+2,i+2},{i,i},max(a[i],a[i+1]));
			// dp[i+2][i+2]=min(dp[i+2][i+2],dp[i][i]+max(a[i],a[i+1]));
		}
		cerr<<i<<' '<<i<<':'<<dp[i][i]<<'\n';
	}
	int ans=inf;
	int endi=-1,endj=-1;
	if (n%2==0)
	{
		ans=dp[n+1][n+1];
		endi=n+1;
		endj=n+1;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (dp[n+1][i]<inf)
			{
				int val=dp[n+1][i]+a[i];
				if (val<ans)
				{
					ans=val;
					endi=n+1;
					endj=i;
				}
			}
		}
		if (dp[n][n]<inf)
		{
			int val=dp[n][n]+a[n];
			if (val<ans)
			{
				ans=val;
				endi=n;
				endj=n;
			}
		}
	}
	cout<<ans<<'\n';
	vector<pair<int,int>> ops;
	int ci=endi,cj=endj;
	while (ci!=1||cj!=1)
	{
		ops.push_back(op[ci][cj]);
		auto p=way[ci][cj];
		ci=p.first;
		cj=p.second;
	}
	reverse(ops.begin(),ops.end());
	for (auto p:ops)
	{
		if (p.first>p.second)
		{
			swap(p.first,p.second);
		}
		cout<<p.first<<' '<<p.second<<'\n';
	}
	if (n%2==1)
	{
		int last=(endi==n&&endj==n)?n:endj;
		cout<<last<<'\n';
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