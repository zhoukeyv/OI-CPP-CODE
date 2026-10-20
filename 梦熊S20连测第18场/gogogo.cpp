#include<bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=5e5+10,mod=1e9+7;
string s;
bool check(string t)
{
	int n=t.size();
	if (n<2)
	{
		return 0;
	}
	for (int d=1;d<=n/2;d++)
	{
		if (n%d)
		{
			continue;
		}
		int k=n/d;
		if (k<2)
		{
			continue;
		}
		int flag=1;
		for (int i=d;i<n;i++)
		{
			if (t[i]!=t[i-d])
			{
				flag=0;
				break;
			}
		}
		if (flag)
		{
			return true;
		}
	}
	return false;
}
void solve()
{
	cin>>s;
	int n=s.size();
	int ans=0;
	for (int k=0;k<(1ll<<n);k++)
	{
		if (__builtin_popcount(k)<=ans)
		{
			continue;
		}
		string t;
		for (int i=0;i<n;i++)
		{
			if (k>>i&1)
			{
				t+=s[i];
			}
		}
		if (check(t))
		{
			ans=t.size();
			if (ans==n)
			{
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main()
{
	freopen("gogogo.in","r",stdin);
	freopen("gogogo.out","w",stdout);
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