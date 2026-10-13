#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
void solve()
{
	string s;
	cin>>s;
	bool empty_reach=true;
	int min0_even=INF,max0_even=-INF;
	int min0_odd=INF,max0_odd=-INF;
	int min1_even=INF,max1_even=-INF;
	int min1_odd=INF,max1_odd=-INF;
	auto add_interval=[](int& min_val,int& max_val,int lo,int hi)
	{
		if (lo>hi)
		{
			return;
		}
		if (lo<min_val)
		{
			min_val=lo;
		}
		if (hi>max_val)
		{
			max_val=hi;
		}
	};
	for (char ch:s)
	{
		bool new_empty=false;
		int n00e_min=INF,n00e_max=-INF;
		int n00o_min=INF,n00o_max=-INF;
		int n01e_min=INF,n01e_max=-INF;
		int n01o_min=INF,n01o_max=-INF;
		if (ch=='0'||ch=='1')
		{
			int c=ch-'0';
			if (empty_reach)
			{
				if (c==0)
				{
					add_interval(n00o_min,n00o_max,1,1);
				}
				else
				{
					add_interval(n01o_min,n01o_max,1,1);
				}
			}
			if (min1_even!=INF)
			{
				int a=min1_even,b=max1_even;
				if (c==1)
				{
					int lo=a-1,hi=b-1;
					if (a==1)
					{
						new_empty=true;
						lo=2;
					}
					add_interval(n00o_min,n00o_max,lo,hi);
				}
				else
				{
					add_interval(n00o_min,n00o_max,a+1,b+1);
				}
			}
			if (min1_odd!=INF)
			{
				int a=min1_odd,b=max1_odd;
				if (c==1)
				{
					int lo=a-1,hi=b-1;
					if (a==1)
					{
						new_empty=true;
						lo=2;
					}
					add_interval(n00e_min,n00e_max,lo,hi);
				}
				else
				{
					add_interval(n00e_min,n00e_max,a+1,b+1);
				}
			}
			if (min0_even!=INF)
			{
				int a=min0_even,b=max0_even;
				if (c==0)
				{
					int lo=a-1,hi=b-1;
					if (a==1)
					{
						new_empty=true;
						lo=2;
					}
					add_interval(n01o_min,n01o_max,lo,hi);
				}
				else
				{
					add_interval(n01o_min,n01o_max,a+1,b+1);
				}
			}
			if (min0_odd!=INF)
			{
				int a=min0_odd,b=max0_odd;
				if (c==0)
				{
					int lo=a-1,hi=b-1;
					if (a==1)
					{
						new_empty=true;
						lo=2;
					}
					add_interval(n01e_min,n01e_max,lo,hi);
				}
				else
				{
					add_interval(n01e_min,n01e_max,a+1,b+1);
				}
			}
		}
		else
		{
			if (empty_reach)
			{
				add_interval(n00o_min,n00o_max,1,1);
				add_interval(n01o_min,n01o_max,1,1);
			}
			if (min1_even!=INF)
			{
				int a=min1_even,b=max1_even;
				add_interval(n00o_min,n00o_max,a-1,b+1);
			}
			if (min1_odd!=INF)
			{
				int a=min1_odd,b=max1_odd;
				int lo=a-1,hi=b+1;
				if (a==1)
				{
					new_empty=true;
					lo=2;
				}
				add_interval(n00e_min,n00e_max,lo,hi);
			}
			if (min0_even!=INF)
			{
				int a=min0_even,b=max0_even;
				add_interval(n01o_min,n01o_max,a-1,b+1);
			}
			if (min0_odd!=INF)
			{
				int a=min0_odd,b=max0_odd;
				int lo=a-1,hi=b+1;
				if (a==1)
				{
					new_empty=true;
					lo=2;
				}
				add_interval(n01e_min,n01e_max,lo,hi);
			}
		}
		empty_reach=new_empty;
		min0_even=n00e_min;
		max0_even=n00e_max;
		min0_odd=n00o_min;
		max0_odd=n00o_max;
		min1_even=n01e_min;
		max1_even=n01e_max;
		min1_odd=n01o_min;
		max1_odd=n01o_max;
	}
	int ans=INF;
	if (empty_reach)
	{
		ans=0;
	}
	if (min0_even!=INF)
	{
		ans=min(ans,min0_even);
	}
	if (min0_odd!=INF)
	{
		ans=min(ans,min0_odd);
	}
	if (min1_even!=INF)
	{
		ans=min(ans,min1_even);
	}
	if (min1_odd!=INF)
	{
		ans=min(ans,min1_odd);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while (T--)
	{
		solve();
	}
	return 0;
}