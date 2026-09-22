#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 2, 0) {}
    void add(int i, int v) {
        while (i <= n) {
            tree[i] += v;
            i += i & -i;
        }
    }
    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i -= i & -i;
        }
        return res;
    }
};
int n, m, q;
int main()
{
    
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    cin>>n>>m>>q;
    vector<int> vis(n + 1);
    vector<pair<int, int>> s(m);
    vector<vector<pair<int, int>>> b(n + 2);
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin>>l>.r;
        s[i] = {l, r};
    }
    sort(s.begin(), s.end(),greater<>());
    for (int d = 1; d <= n; ++d) {
        for (int k = 0; k * d <= n; ++k) {
            int l = k * d + 1;
            int R = (k + 1) * d - 1;
            if (R > n) R = n;
            if (l <= R) {
                b[l].push_back({R, d});
            }
        }
    }
    
    BIT bit(n);
    int ptr = 0;
    
    for (int l = n; l >= 1;l--)
    {
        while (ptr < m && s[ptr].first >= l)
        {
            bit.add(s[ptr].second, 1);
            ++ptr;
        }
        for (pair<int,int> p:b[l])
        {
            int R = p.first;
            int d = p.second;
            vis[d] += bit.sum(R);
        }
    }
    
    for (int i = 0; i < q;i++)
    {
        int d;
        cin>>d;
        cout<< m - vis[d]<<'\n';
    }
    return 0;
}