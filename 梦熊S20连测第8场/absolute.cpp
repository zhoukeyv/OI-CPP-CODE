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
    int res=0;
    for (int i=-1;i<=1;i+=2)
    {
        for (int j=-1;j<=1;j+=2)
        {
            int maxX1 =-inf, maxX2 = -inf;
            int posX1 = -1, posX2 = -1;
            int maxY1 =-inf, maxY2 =-inf;
            int posY1 = -1, posY2 = -1;

            for (int i = 0; i < n; ++i) {
                int c = intabs(a[i] - b[i]);
                int X = s * a[i] - t * b[i] - c;
                int Y = t * a[i] - s * b[i] - c;
                if (X > maxX1) {
                    maxX2 = maxX1; posX2 = posX1;
                    maxX1 = X; posX1 = i;
                } else if (X > maxX2) {
                    maxX2 = X; posX2 = i;
                }
                if (Y > maxY1) {
                    maxY2 = maxY1; posY2 = posY1;
                    maxY1 = Y; posY1 = i;
                } else if (Y > maxY2) {
                    maxY2 = Y; posY2 = i;
                }
            }

            int cand = intONG_MIN;
            if (posX1 != posY1) {
                cand = maxX1 + maxY1;
            } else {
                if (posX2 != -1) cand = max(cand, maxX1 + maxY2);
                if (posY2 != -1) cand = max(cand, maxX2 + maxY1);
            }

            res = max(res, cand);
        }
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