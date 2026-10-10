#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1e6+10;
vector<pair<int,int>> tr[N];
int t[26][26],graph[N][26],b[26][26];
int n,q,sz=0,ans=0;
void solve()
{
	cin>>n>>q;
	memset(graph,-1,sizeof(graph));
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int p=0;
		for (char c:s)
		{
			tr[p].push_back({i,c-'a'});
			if (graph[p][c-'a']==-1)
			{
				graph[p][c-'a']=++sz;
			}
			p=graph[p][c-'a'];
		}
		tr[p].push_back({i,-1});
	}
	for (int i=0;i<=sz;i++)
	{
		int cnt[26]={0};
		int sum=0;
		for (pair<int,int> v:tr[i])
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
	return;
}
signed main()
{
	freopen("master.in","r",stdin);
	freopen("master.out","w",stdout);
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