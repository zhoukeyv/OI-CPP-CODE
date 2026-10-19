#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10;
int dp[2][7][7],a[N],cnt[N];
int n,m,ans=0;
void solve()
{
    memset(dp,-0x3f,sizeof dp);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    dp[0][0][0]=0;
    for (int i=1;i<=m;i++)
    {
		memset(dp[i&1],-0x3f,sizeof dp[i&1]);
        for (int j=0;j<=6;j++)
        {
            if (j>cnt[i-1])
            {
                continue;
            }
            for (int k=0;k<=6;k++)
            {
                if (k>cnt[i])
                {
                    continue;
                }
                for (int l=0;l<=6;l++)
                {
                    for (int t=j;t<=6;t++)
                    {
                        dp[i&1][j][k]=max(dp[i&1][j][k],dp[i&1^1][l][t]+min({l,t-j,(cnt[i]-k)%3})+(cnt[i]-k)/3);
                        // cerr<<i<<' '<<j<<' '<<k<<"<-"<<l<<' '<<t<<'\n';
                    }
                }
                // if (dp[i][j][k]>=0)
                // cerr<<i<<' '<<j<<' '<<k<<':'<<dp[i][j][k]<<'\n';
            }
        }
    }
    for (int i=0;i<=3;i++)
    {
        for (int j=0;j<=3;j++)
        {
            ans=max(ans,dp[m&1][i][j]);
        }
    }
    cout<<ans<<'\n';
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TestCase=1;
    cin>>TestCase;
    for (int CaseId=1;CaseId<=TestCase;CaseId++)
    {
        solve();
    }
    return 0;
}