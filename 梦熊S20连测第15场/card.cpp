#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1010;
vector<vector<int>> c,s[N];
bitset<N> b[N];
int cnt[N][N];
int unsat;
int n,m;
void insert(int j,bitset<N> bit[])
{
	static unordered_map<int,vector<int>> um;
	um.clear();
	for (int i=1;i<=n;i++)
	{
		for (int j:s[i][j])
		{
			um[j].push_back(i);
		}
	}
	static bitset<N> temp[N];
	for (int i=1;i<=n;i++)
	{
		temp[i].reset();
	}
	for (int i=1;i<=n;i++)
	{
		for (int j:s[i][j])
		{
			for (int y:um[j])
			{
				temp[i].set(y);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		bit[i]=~temp[i];
		bit[i].reset(i);
		bit[i]&=b[i];
	}
	return;
}
void solve()
{
	cin>>n>>m;
	c.resize(n+1,vector<int>(m+1));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		s[i].resize(m+1);
		for (int j=1;j<=m;j++)
		{
			s[i][j].resize(c[i][j]);
			for (int k=0;k<c[i][j];k++)
			{
				cin>>s[i][j][k];
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		b[i].reset();
		for (int y=i+1;y<=n;y++)
		{
			b[i].set(y);
		}
	}
	bool flag=true;
	for (int i=1;i<=n&&flag;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (c[i][j]!=1)
			{
				flag=false;
				break;
			}
		}
	}
	if (flag)
	{
		bool all_diff=true;
		for (int j=1;j<=m&&all_diff;j++)
		{
			unordered_set<int> seen;
			for (int i=1;i<=n;i++)
			{
				if (seen.count(s[i][j][0]))
				{
					all_diff=false;
					break;
				}
				seen.insert(s[i][j][0]);
			}
		}
		if (all_diff)
		{
			int ans=(int)m*(m-1)/2;
			cout<<ans<<'\n';
			return;
		}
	}
	memset(cnt,0,sizeof(cnt));
	unsat=n*(n-1)/2;
	int ans=0;
	int r=0;
	bitset<N> bit[N];
	for (int l=1;l<=m;l++)
	{
		while (r<m&&unsat>0)
		{
			r++;
			insert(r,bit);
			for (int i=1;i<=n;i++)
			{
				for (int y=bit[i]._Find_first();y<=n;y=bit[i]._Find_next(y))
				{
					if (cnt[i][y]==1)
					{
						unsat--;
					}
					cnt[i][y]++;
				}
			}
		}
		if (unsat==0)
		{
			ans+=m-r+1;
		}
		if (l<=r)
		{
			insert(l,bit);
			for (int i=1;i<=n;i++)
			{
				for (int y=bit[i]._Find_first();y<=n;y=bit[i]._Find_next(y))
				{
					cnt[i][y]--;
					if (cnt[i][y]==1)
					{
						unsat++;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
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