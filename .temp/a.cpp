#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int n,m;
vector<vector<int>> S[MAXN];// S[i][j]：学生 i 在位置 j 的集合
short cnt[MAXN][MAXN];		// cnt[x][y]：窗口内区分 x,y 的位置数
int unsat;					// 尚未满足（cnt < 2）的对数
bitset<MAXN> mask_gt[MAXN];	// mask_gt[x] 只保留 y > x 的位
// 计算位置 j 上，每个学生与哪些学生不相交（只保留 y > x）
void compute_not_inter(int j,bitset<MAXN> not_inter[])
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
	static bitset<MAXN> inter[MAXN];
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
		not_inter[x]=~inter[x];
		not_inter[x].reset(x);		// 去掉自己
		not_inter[x]&=mask_gt[x];// 只保留 y > x
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
	// 预处理 mask_gt
	for (int x=1;x<=n;x++)
	{
		mask_gt[x].reset();
		for (int y=x+1;y<=n;y++)
		{
			mask_gt[x].set(y);
		}
	}
	// 特判：所有集合大小都是 1 且所有值都不同 → 任意长度 ≥ 2 的区间都合法
	bool all_size_1=true;
	for (int i=1;i<=n&&all_size_1;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (c[i][j]!=1)
			{
				all_size_1=false;
				break;
			}
		}
	}
	if (all_size_1)
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
			long long ans=(long long)m*(m-1)/2;
			cout<<ans<<'\n';
			return;
		}
	}
	memset(cnt,0,sizeof(cnt));
	unsat=n*(n-1)/2;
	long long ans=0;
	int r=0;
	bitset<MAXN> not_inter[MAXN];
	for (int l=1;l<=m;l++)
	{
		while (r<m&&unsat>0)
		{
			r++;
			compute_not_inter(r,not_inter);
			for (int x=1;x<=n;x++)
			{
				for (int y=not_inter[x]._Find_first();y<=n;y=not_inter[x]._Find_next(y))
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
			compute_not_inter(l,not_inter);
			for (int x=1;x<=n;x++)
			{
				for (int y=not_inter[x]._Find_first();y<=n;y=not_inter[x]._Find_next(y))
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
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		solve();
	}
	return 0;
}