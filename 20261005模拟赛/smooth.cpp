#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-8;
const int inf=0x3f3f3f3f3f3f3f3f,N=110,M=270;
int dp[N][M];
int a[N];
int D,I,m,n;
void solve()
{
	memset(dp,0,sizeof dp);
	cin>>D>>I>>m>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=255;j++)
		{
			dp[i][j]=inf;
			for (int k=0;k<=255;k++)
			{
				if (j==k)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][k]+D);
				}
				if (abs(j-k)<=m)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(a[i]-j));
				}
				else if (m!=0)
				{
					int temp=ceil(abs(j-k)*1.0/m);
					dp[i][j]=min(dp[i][j],dp[i-1][k]+(temp-1)*I+abs(a[i]-j));
				}
			}
//			cout<<'|'<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	int ans=inf;
	for (int i=0;i<=255;i++)
	{
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
//	freopen("smooth/smooth4.in","r",stdin);
//	freopen("smooth/smooth.out","w",stdout);
	freopen("smooth.in","r",stdin);
	freopen("smooth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TestCase=1;
	cin>>TestCase;
	for (int CaseId=1;CaseId<=TestCase;CaseId++)
	{
		cout<<"Case #"<<CaseId<<": ";
		solve();
	}
	return 0;
}


/*

2
6 6 2 3
1 7 5
100 1 5 3
1 50 7

*/
/*

Case #1: 4
Case #2: 17

*/