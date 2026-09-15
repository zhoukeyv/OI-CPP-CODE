#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=1e18,N=3e5+10;
int a[N],b[N];
int n,k;
bool check(int mid)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=mid)
		{
			cnt++;
		}
	}
	if (k<=cnt)
	{
		return true;
	}
	int maxx=-inf,idx=0;
	for (int i=1;i<=n;i++)
	{
		int temp=(b[i]>=mid?1:0)-(a[i]>=mid?1:0);
	}
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) cnt++;
    }
    int need = k - cnt;
    if (need <= 0) return true;
    int max_sum = -1e9, cur = 0;
    for (int i = 1; i <= n; ++i) {
        int delta = (b[i] >= x ? 1 : 0) - (a[i] >= x ? 1 : 0);
        cur = max(delta, cur + delta);
        max_sum = max(max_sum, cur);
    }
    return max_sum >= need;
}
void solve()
{
	cin>>n;
	k=(n+1)/2;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=1e9,res=1;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (check(mid))
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<res<<'\n';
	return;
}
signed main()
{
#ifndef LOCAL_cph
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
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