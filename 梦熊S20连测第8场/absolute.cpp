#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=2e5+10;
int a[N],b[N];
int n;
void solve()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        sum+=labs(a[i]-b[i]);
    }
    return;
}
signed main()
{
#ifndef LOCAL_cph
    freopen("absolute.in","r",stdin);
    freopen("absolute.out","w",stdout);
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