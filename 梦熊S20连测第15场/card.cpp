#include <bits/stdc++.h>
#define double long double
#define ll long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=1010;
unordered_map<int,vector<int>> um;
bitset<N> b[N],bit[N],temp[N];
vector<vector<int>> c,s[N];
short cnt[N][N];
int sum;
int n,m;
void insert(int x,bitset<N> bit[])
{
	um.clear();
	for (int i=1;i<=n;i++)
	{
		for (int j:s[i][x])
		{
			um[j].push_back(i);
		}
	}
	for (int i=1;i<=n;i++)
	{
		temp[i].reset();
	}
	for (int i=1;i<=n;i++)
	{
		for (int j:s[i][x])
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
	c.assign(n+1,vector<int>(m+1));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		s[i].assign(m+1);
		for (int j=1;j<=m;j++)
		{
			s[i][j].assign(c[i][j]);
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
		bool fg=true;
		for (int j=1;j<=m&&fg;j++)
		{
			unordered_set<int> us;
			for (int i=1;i<=n;i++)
			{
				if (us.count(s[i][j][0]))
				{
					fg=false;
					break;
				}
				us.insert(s[i][j][0]);
			}
		}
		if (fg)
		{
			cout<<m*(m-1)/2<<'\n';
			return;
		}
	}
	memset(cnt,0,sizeof(cnt));
	sum=n*(n-1)/2;
	ll ans=0;
	int r=0;
	for (int l=1;l<=m;l++)
	{
		while (r<m&&sum>0)
		{
			r++;
			insert(r,bit);
			for (int i=1;i<=n;i++)
			{
				for (int y=bit[i]._Find_first();y<=n;y=bit[i]._Find_next(y))
				{
					if (cnt[i][y]==1)
					{
						sum--;
					}
					cnt[i][y]++;
				}
			}
		}
		if (sum==0)
		{
			ans+=m-r+1;
		}
		if (l<=r)
		{
			insert(l,bit);
			for (int i=1;i<=n;i++)
			{
				for (int j=bit[i]._Find_first();j<=n;j=bit[i]._Find_next(j))
				{
					cnt[i][j]--;
					if (cnt[i][j]==1)
					{
						sum++;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	// freopen("card.in","r",stdin);
	// freopen("card.out","w",stdout);
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