#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
void u(int& a,int& b,int l,int r)
{
	if (l>r)
	{
		return;
	}
	if (l<a)
	{
		a=l;
	}
	if (r>b)
	{
		b=r;
	}
}
void s()
{
	string s;
	cin>>s;
	bool e=1,ne=0;
	int a=inf,b=-inf,c=inf,d=-inf,f=inf,g=-inf,h=inf,i=-inf;
	for (char ch:s)
	{
		ne=0;
		int na=inf,nb=-inf,nc=inf,nd=-inf,nf=inf,ng=-inf,nh=inf,ni=-inf;
		if (ch=='0'||ch=='1')
		{
			int x=ch-'0';
			if (e)
			{
				if (x==0)
				{
					u(nc,nd,1,1);
				}
				else
				{
					u(nh,ni,1,1);
				}
			}
			if (f!=inf)
			{
				if (x==1)
				{
					int l=f-1,r=g-1;
					if (f==1)
					{
						ne=1;
						l=2;
					}
					u(nc,nd,l,r);
				}
				else
				{
					u(nc,nd,f+1,g+1);
				}
			}
			if (h!=inf)
			{
				if (x==1)
				{
					int l=h-1,r=i-1;
					if (h==1)
					{
						ne=1;
						l=2;
					}
					u(na,nb,l,r);
				}
				else
				{
					u(na,nb,h+1,i+1);
				}
			}
			if (a!=inf)
			{
				if (x==0)
				{
					int l=a-1,r=b-1;
					if (a==1)
					{
						ne=1;
						l=2;
					}
					u(nh,ni,l,r);
				}
				else
				{
					u(nh,ni,a+1,b+1);
				}
			}
			if (c!=inf)
			{
				if (x==0)
				{
					int l=c-1,r=d-1;
					if (c==1)
					{
						ne=1;
						l=2;
					}
					u(nf,ng,l,r);
				}
				else
				{
					u(nf,ng,c+1,d+1);
				}
			}
		}
		else
		{
			if (e)
			{
				u(nc,nd,1,1);
				u(nh,ni,1,1);
			}
			if (f!=inf)
			{
				u(nc,nd,f-1,g+1);
			}
			if (h!=inf)
			{
				int l=h-1,r=i+1;
				if (h==1)
				{
					ne=1;
					l=2;
				}
				u(na,nb,l,r);
			}
			if (a!=inf)
			{
				u(nh,ni,a-1,b+1);
			}
			if (c!=inf)
			{
				int l=c-1,r=d+1;
				if (c==1)
				{
					ne=1;
					l=2;
				}
				u(nf,ng,l,r);
			}
		}
		e=ne;
		a=na;
		b=nb;
		c=nc;
		d=nd;
		f=nf;
		g=ng;
		h=nh;
		i=ni;
	}
	int ans=inf;
	if (e)
	{
		ans=0;
	}
	if (a!=inf)
	{
		ans=min(ans,a);
	}
	if (c!=inf)
	{
		ans=min(ans,c);
	}
	if (f!=inf)
	{
		ans=min(ans,f);
	}
	if (h!=inf)
	{
		ans=min(ans,h);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		s();
	}
	return 0;
}