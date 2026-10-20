#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // 控制规模，方便暴力枚举
    int n = rng() % 7 + 2;          // 2..8
    int k = rng() % n + 2;          // 2..n+1
    if (k > n) k = n;               // 保证 2<=k<=n

    cout << n << " " << k << "\n";

    // 随机生成一棵树：节点 i 随机连一个更小的节点
    // 但为了更"刁钻"，我们随机选择父节点为 rand(1, i-1)
    for (int i = 2; i <= n; i++) {
        int p = rng() % (i - 1) + 1;
        if (rng() & 1) cout << p << " " << i << "\n";
        else           cout << i << " " << p << "\n";
    }
    return 0;
}