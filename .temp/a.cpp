#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<pair<int,int>> t[N];
int t[26][26],tr[N][26],b[26][26];
int n,q,sz=0,ans=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	memset(tr,-1,sizeof(tr));
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int p=0;
		for (char c:s)
		{
			t[p].push_back({i,c-'a'});
			if (tr[p][c-'a']==-1)
			{
				tr[p][c-'a']=++sz;
			}
			p=tr[p][c-'a'];
		}
		t[p].push_back({i,-1});
	}
	for (int i=0;i<=sz;i++)
	{
		int cnt[26]={0};
		int sum=0;
		for (pair<int,int> v:t[i])
		{
			if (v.second==-1)
			{
				ans+=sum;
			}
			else
			{
				for (int j=0;j<26;j++)
				{
					if (j!=v.second&&cnt[j]>0)
					{
						t[j][v.second]+=cnt[j];
					}
				}
				cnt[v.second]++;
				sum++;
			}
		}
	}
	for (int i=0;i<26;i++)
	{
		for (int j=0;j<26;j++)
		{
			b[i][j]=t[j][i];
		}
	}
	while (q--)
	{
		string s;
		cin>>s;
		int temp[26];
		for (int i=0;i<26;i++)
		{
			temp[s[i]-'a']=i;
		}
		int res=ans;
		for (int i=0;i<26;i++)
		{
			for (int j=0;j<26;j++)
			{
				if (i!=j&&temp[i]<temp[j])
				{
					res+=b[i][j];
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}