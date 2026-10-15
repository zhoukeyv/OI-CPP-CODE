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
	if (pos==6||max(x,y)>=3)
	{
		if (x>y)
		{
			ans1+=k;
		}
		else
		{
			ans2+=k;
		}
		// cerr<<pos<<' '<<x<<' '<<y<<' '<<k<<'\n';
		return;
	}
	if (s[pos]=='a')
	{
		DFS(pos+1,x+1,y,k,a);
	}
	else if (s[pos]=='b')
	{
		DFS(pos+1,x,y+1,k,1-b);
	}
	else
	{
		DFS(pos+1,x+1,y,k*t,a);
		DFS(pos+1,x,y+1,k*(1-t),1-b);
	}
	return;
}
void solve()
{
	ans1=ans2=0;
	cin>>s>>a>>b;
	a/=100.0;
	b/=100.0;
	s='@'+s;
	DFS(1,0,0,1,0.5);
	// cerr<<a<<' '<<b<<'\n';
	if (fabs(ans1-ans2)<=eps)
	{
		cout<<"?\n";
	}
	else if (ans1>ans2)
	{
		cout<<"a\n";
	}
	else
	{
		cout<<"b\n";
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
	cin>>TestCase;
	for (int Caseid=1;Caseid<=TestCase;Caseid++)
	{
		solve();
	}
	return 0;
}