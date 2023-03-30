/*对于一个元素均为正整数，大小为n*m的网格，Alice从左上角(1,1)出发，每次只能选择向右或向下走一格，最终到达网格右下角停止。
到达网格右下角存在若干路径，请你找出路径上各点的数字总和最小的路径，输出其数字总和。*/

#include <algorithm>
#include <iostream>

using namespace std;

int map[205][205];
int dp[205][205];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    dp[0][0] = map[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + map[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + map[i][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
            }
        }
    }
    cout << dp[n-1][m-1];
}