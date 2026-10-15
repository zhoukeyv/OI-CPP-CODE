#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[500005],a[500005],sum[5005];
bool flag[5005];
int len,k;
void sol(int x)
{
	if (flag[x])
	{
		return;
	}
	flag[x]=true;
	sum[x]=0;
	for (int i=(x-1)*len+1;i<=x*len;i++)
	{
		a[i]=sqrt(a[i]),sum[x]+=a[i];
		if (a[i]>1)
		{
			flag[x]=false;
		}
	}
	return;
}
void add(int l,int r)
{
	for (int i=l;i<=(b[l]*len<r?b[l]*len:r);i++)
	{
		sum[b[l]]-=a[i];
		a[i]=sqrt(a[i]);
		sum[b[l]]+=a[i];
	}
	if (b[l]!=b[r])
	{
		for (int i=r;b[i]==b[r];i--)
		{
			sum[b[r]]-=a[i];
			a[i]=sqrt(a[i]);
			sum[b[r]]+=a[i];
		}
	}
	for (int i=b[l]+1;i<=b[r]-1;i++)
	{
		sol(i);
	}
	return;
}
int query(int l,int r)
{
	int ans=0;
	for (int i=l;i<=(b[l]*len<r?b[l]*len:r);i++)
	{
		ans+=a[i];
	}
	if (b[l]!=b[r])
	{
		for (int i=r;b[i]==b[r];i--)
		{
			ans+=a[i];
		}
	}
	for (int i=b[l]+1;i<=b[r]-1;i++)
	{
		ans+=sum[i];
	}
	return ans;
}
signed main()
{
	int n;
	cin>>n;
	len=sqrt(n);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		b[i]=(i-1)/len+1;
		sum[b[i]]+=a[i];
	}
	cin>>k;
	for (int i=1;i<=k;i++)
	{
		bool opt;
		int l,r;
		cin>>opt>>l>>r;
		if (l>r)
		{
			swap(l,r);
		}
		if (opt==1)
		{
			cout<<query(l,r)<<'\n';
		}
		else
		{
			add(l,r);
		}
	}
	return 0;
}