#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f;
string s;
double a,b,ans1,ans2;
void DFS(int pos,int x,int y,double k,double t)
{
	if (pos==6)
	{
		if (x>y)
		{
			ans1+=k;
		}
		else
		{
			ans2+=k;
		}
		return;
	}
	if (s[pos]=='a')
	{
		x++;
		DFS(pos+1,x,y,k,a);
	}
	else if (s[pos]=='b')
	{
		y++;
		DFS(pos+1,x,y,k,b);
	}
	else
	{
		if (pos==1)
		{
			DFS(pos+1,x,y,k*a,b);
		}
	}
}
void solve()
{
	ans1=ans2=0;
	cin>>s>>a>>b;
	s='@'+s;
	return;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
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