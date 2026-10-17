#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000005;
const int MAXM = 1 << 20; // 2^20 = 1048576

int a[MAXN];
int cnt[MAXM + 5];
int touched[MAXN + 5];

int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

void print_u64(unsigned long long x) {
    if (x == 0) {
        putchar('0');
        return;
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
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }

    unsigned long long total = (unsigned long long)n * (n + 1) / 2;
    unsigned long long ans = 0;

    // b <= 20，需要统计 C_b
    for (int b = 0; b <= 20; b++) {
        int M = 1 << b;
        unsigned long long count0 = 0;
        unsigned long long C = 0;
        int start = 0;

        for (int i = 0; i <= n; i++) {
            if (i == n || (a[i] & (1 << b))) {
                int len = i - start;
                count0 += (unsigned long long)len * (len + 1) / 2;

                if (len >= M) {
                    int L = start;
                    int missing = M;
                    int top = 0;

                    for (int R = start; R < i; R++) {
                        int x = a[R];
                        if (x < M) {
                            if (cnt[x] == 0) {
                                missing--;
                                touched[top++] = x;
                            }
                            cnt[x]++;
                        }

                        while (missing == 0) {
                            int y = a[L];
                            if (y < M) {
                                if (cnt[y] == 1) break;
                                cnt[y]--;
                            }
                            L++;
                        }

                        if (missing == 0) {
                            C += (unsigned long long)(L - start + 1);
                        }
                    }

                    // 回滚计数数组
                    for (int j = 0; j < top; j++) {
                        cnt[touched[j]] = 0;
                    }
                }

                start = i + 1;
            }
        }

        ans += (unsigned long long)(1ULL << b) * (total - count0 + C);
    }

    // b > 20，此时 C_b = 0，只需统计 count0
    for (int b = 21; b <= 29; b++) {
        unsigned long long count0 = 0;
        int start = 0;

        for (int i = 0; i <= n; i++) {
            if (i == n || (a[i] & (1 << b))) {
                int len = i - start;
                count0 += (unsigned long long)len * (len + 1) / 2;
                start = i + 1;
            }
        }

        ans += (unsigned long long)(1ULL << b) * (total - count0);
    }

    print_u64(ans);
    putchar('\n');

    return 0;
}