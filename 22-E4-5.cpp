/*你需要求出模式串P在原串S中出现的次数, 模式串和原串中的字母均为小写, 数据有多组, 每组输出一个答案*/

#include <cstring>
#include <iostream>

using namespace std;

char p[10005], s[1000005];
int pi[10005];

int main() {
    int T;
    cin >> T;
    for (int j = 1; j <= T; j++) {
        int count = 0;
        cin >> p + 1 >> s + 1;
        int m = strlen(p + 1), n = strlen(s + 1);
        for (int q = 2, k = 0; q <= m; q++) {
            while (k && p[k + 1] != p[q]) {
                k = pi[k];
            }
            if (p[k + 1] == p[q]) {
                k++;
            }
            pi[q] = k;
        }
        for (int i = 1, q = 0; i <= n; i++) {
            while (q && p[q + 1] != s[i]) {
                q = pi[q];
            }
            if (p[q + 1] == s[i]) {
                q++;
            }
            if (q == m) {
                count++;
                q = pi[q];
            }
        }
        cout << count << endl;
    }
    return 0;
}