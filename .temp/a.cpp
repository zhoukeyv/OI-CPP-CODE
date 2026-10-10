#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<pair<int,int>> tr[N];
int val[26][26],trie[N][26],b[26][26];
int n,q,tot=0,ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	memset(trie,-1,sizeof(trie));
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int u=0;
		for (char ch:s)
		{
			int c=ch-'a';
			tr[u].push_back({i,c});
			if (trie[u][c]==-1)
			{
				trie[u][c]=++tot;
			}
			u=trie[u][c];
		}
		tr[u].push_back({i,-1});
	}
	for (int u=0;u<=tot;u++)
	{
		int cnt[26]={0};
		int sum=0;
		for (pair<int,int> p:tr[u])
		{
			if (p.second==-1)
			{
				ans+=sum;
			}
			else
			{
				int c=p.second;
				for (int y=0;y<26;y++)
				{
					if (y!=c&&cnt[y]>0)
					{
						val[y][c]+=cnt[y];
					}
				}
				cnt[c]++;
				sum++;
			}
		}
	}
	for (int c=0;c<26;c++)
	{
		for (int d=0;d<26;d++)
		{
			b[c][d]=val[d][c];
		}
	}
	while (q--)
	{
		string alpha;
		cin>>alpha;
		int pos[26];
		for (int i=0;i<26;i++)
		{
			pos[alpha[i]-'a']=i;
		}
		int ans=ans;
		for (int c=0;c<26;c++)
		{
			for (int d=0;d<26;d++)
			{
				if (c!=d&&pos[c]<pos[d])
				{
					ans+=b[c][d];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}