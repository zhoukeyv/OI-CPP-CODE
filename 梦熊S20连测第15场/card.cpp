#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1010;
vector<vector<int>> S[N];
bitset<N> mask_gt[N];
int cnt[N][N];
int unsat;
int n,m;
void insert(int j,bitset<N> bit[])
{
	static unordered_map<int,vector<int>> elem_to_students;
	elem_to_students.clear();
	for (int x=1;x<=n;x++)
	{
		for (int e:S[x][j])
		{
			elem_to_students[e].push_back(x);
		}
	}
	static bitset<N> inter[N];
	for (int x=1;x<=n;x++)
	{
		inter[x].reset();
	}
	for (int x=1;x<=n;x++)
	{
		for (int e:S[x][j])
		{
			for (int y:elem_to_students[e])
			{
				inter[x].set(y);
			}
		}
	}
	for (int x=1;x<=n;x++)
	{
		bit[x]=~inter[x];
		bit[x].reset(x);
		bit[x]&=mask_gt[x];
	}
}
void solve()
{
	cin>>n>>m;
	vector<vector<int>> c(n+1,vector<int>(m+1));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		S[i].resize(m+1);
		for (int j=1;j<=m;j++)
		{
			S[i][j].resize(c[i][j]);
			for (int k=0;k<c[i][j];k++)
			{
				cin>>S[i][j][k];
			}
		}
	}
	for (int x=1;x<=n;x++)
	{
		mask_gt[x].reset();
		for (int y=x+1;y<=n;y++)
		{
			mask_gt[x].set(y);
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
				if (seen.count(S[i][j][0]))
				{
					all_diff=false;
					break;
				}
				seen.insert(S[i][j][0]);
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
			for (int x=1;x<=n;x++)
			{
				for (int y=bit[x]._Find_first();y<=n;y=bit[x]._Find_next(y))
				{
					if (cnt[x][y]==1)
					{
						unsat--;
					}
					cnt[x][y]++;
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
			for (int x=1;x<=n;x++)
			{
				for (int y=bit[x]._Find_first();y<=n;y=bit[x]._Find_next(y))
				{
					cnt[x][y]--;
					if (cnt[x][y]==1)
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