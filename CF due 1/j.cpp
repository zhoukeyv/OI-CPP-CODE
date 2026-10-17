#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXV = 2000000;

inline int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

void print128(__int128 x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    for (char c : s) putchar(c);
}

int main() {
    int n = read();
    int m = read();

    vector<int> isCore(MAXV + 2, 0);
    vector<int> pref(MAXV + 2, 0);

    for (int i = 0; i < n; i++) {
        int x = read();
        isCore[x] = 1;
    }

    // pref[x] = 核心档案中 <= x 的数量
    for (int i = 1; i <= MAXV; i++) {
        pref[i] = pref[i - 1] + isCore[i];
    }

    vector<ll> w(m, 0);

    for (int i = 0; i < m; i++) {
        int l = read();
        ll sum = 0;

        for (int j = 0; j < l; j++) {
            int x = read();

            // 核心档案中 > x 的数量
            int cnt = n - pref[x];
            sum += cnt;
        }

        w[i] = sum;
    }

    sort(w.begin(), w.end());

    __int128 ans = 0;

    // 核心档案之间的固定贡献
    ans += (__int128)m * n * (n + 1) / 2;

    // 非核心档案贡献
    // 按权重升序处理，第 i 批（0-index）系数为 m - i
    for (int i = 0; i < m; i++) {
        ans += (__int128)w[i] * (m - i);
    }

    print128(ans);
    putchar('\n');

    return 0;
}