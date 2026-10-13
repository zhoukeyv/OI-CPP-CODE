#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=2e5+10;
string s;
void get(int& x,int& y,int l,int r)
{
	if (l>r)
	{
		return;
	}
	if (l<x)
	{
		x=l;
	}
	if (r>y)
	{
		y=r;
	}
}
void solve()
{
	cin>>s;
	bool flag=true;
	int t1=inf,t2=-inf,t3=inf,t4=-inf,t5=inf,t6=-inf,t7=inf,t8=-inf;
	for (char ch:s)
	{
		bool fg=0;
		int temp1=inf,temp2=-inf,temp3=inf,temp4=-inf,temp5=inf,temp6=-inf,temp7=inf,temp8=-inf;
		if (ch=='0'||ch=='1')
		{
			int x=ch-'0';
			if (flag)
			{
				if (x==0)
				{
					get(temp3,temp4,1,1);
				}
				else
				{
					get(temp7,temp8,1,1);
				}
			}
			if (t5!=inf)
			{
				if (x==1)
				{
					int l=t5-1,r=t6-1;
					if (t5==1)
					{
						fg=1;
						l=2;
					}
					get(temp3,temp4,l,r);
				}
				else
				{
					get(temp3,temp4,t5+1,t6+1);
				}
			}
			if (t7!=inf)
			{
				if (x==1)
				{
					int l=t7-1,r=t8-1;
					if (t7==1)
					{
						fg=1;
						l=2;
					}
					get(temp1,temp2,l,r);
				}
				else
				{
					get(temp1,temp2,t7+1,t8+1);
				}
			}
			if (t1!=inf)
			{
				if (x==0)
				{
					int l=t1-1,r=t2-1;
					if (t1==1)
					{
						fg=1;
						l=2;
					}
					get(temp7,temp8,l,r);
				}
				else
				{
					get(temp7,temp8,t1+1,t2+1);
				}
			}
			if (t3!=inf)
			{
				if (x==0)
				{
					int l=t3-1,r=t4-1;
					if (t3==1)
					{
						fg=1;
						l=2;
					}
					get(temp5,temp6,l,r);
				}
				else
				{
					get(temp5,temp6,t3+1,t4+1);
				}
			}
		}
		else
		{
			if (flag)
			{
				get(temp3,temp4,1,1);
				get(temp7,temp8,1,1);
			}
			if (t5!=inf)
			{
				get(temp3,temp4,t5-1,t6+1);
			}
			if (t7!=inf)
			{
				int l=t7-1,r=t8+1;
				if (t7==1)
				{
					fg=1;
					l=2;
				}
				get(temp1,temp2,l,r);
			}
			if (t1!=inf)
			{
				get(temp7,temp8,t1-1,t2+1);
			}
			if (t3!=inf)
			{
				int l=t3-1,r=t4+1;
				if (t3==1)
				{
					fg=1;
					l=2;
				}
				get(temp5,temp6,l,r);
			}
		}
		flag=fg;
		t1=temp1;
		t2=temp2;
		t3=temp3;
		t4=temp4;
		t5=temp5;
		t6=temp6;
		t7=temp7;
		t8=temp8;
	}
	int ans=inf;
	if (flag)
	{
		ans=0;
	}
	ans=min(ans,t1);
	ans=min(ans,t3);
	ans=min(ans,t5);
	ans=min(ans,t7);
	cout<<ans<<'\n';
}
signed main()
{
	// freopen("Gift.in","r",stdin);
	// freopen("Gift.out","w",stdout);
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