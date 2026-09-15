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
            int max11=-inf,max12=-inf,max21=-inf,max22=-inf,idx11=-1,idx12=-1,idx21=-1,idx22=-1;
            for (int k=1;k<=n;k++)
            {
                int X=i*a[k]-j*b[k]-labs(a[k]-b[k]);
                int Y=j*a[k]-i*b[k]-labs(a[k]-b[k]);
                if (X>max11)
                {
                    max12=max11;
                    idx12=idx11;
                    max11=X;
                    idx11=k;
                } else if (X>max12)
                {
                    max12=X;
                    idx12=k;
                }
                if (Y>max21)
                {
                    max22=max21;
                    idx22=idx21;
                    max21=Y;
                    idx21=k;
                } else if (Y>max22)
                {
                    max22=Y;
                    idx22=k;
                }
            }

            int temp=-inf;
            if (idx11!=idx21)
            {
                temp=max11+max21;
            } else {
                if (max12!=-inf) temp = max(temp, max11 + max22);
                if (max22!=-inf) temp = max(temp, max12 + max21);
            }

            res = max(res, temp);
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