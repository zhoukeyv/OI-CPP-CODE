#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int trie[N][26];
vector<pair<int,int>> tr[N];
int tot=0;
int val[26][26];
int fixed_ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
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
		int cnt_sub[26]={0};
		int cnt_D=0;
		for (auto& p:tr[u])
		{
			int idx=p.first;
			int branch=p.second;
			if (branch==-1)
			{
				fixed_ans+=cnt_D;
			}
			else
			{
				int c=branch;
				for (int y=0;y<26;y++)
				{
					if (y!=c&&cnt_sub[y]>0)
					{
						val[y][c]+=cnt_sub[y];
					}
				}
				cnt_sub[c]++;
				cnt_D++;
			}
		}
	}
	int contrib[26][26];
	for (int c=0;c<26;c++)
	{
		for (int d=0;d<26;d++)
		{
			contrib[c][d]=val[d][c];
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
		int ans=fixed_ans;
		for (int c=0;c<26;c++)
		{
			for (int d=0;d<26;d++)
			{
				if (c!=d&&pos[c]<pos[d])
				{
					ans+=contrib[c][d];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}