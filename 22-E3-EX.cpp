/*现有一个n×m的矩形区域，其中每个单位区域可能有损坏,要求找到地面上所有不包含损坏区域的正方形的个数。*/

#include <algorithm>
#include <iostream>

using namespace std;

int map[2005][2005];
int result[2005][2005];
int continue_num[2005][2005][2];
int dp[2005][2005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    result[0][0] = continue_num[0][0][0] = continue_num[0][0][1] = dp[0][0] = map[0][0] == 0 ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (map[i][0] == 0) {
            result[i][0] = result[i - 1][0] + 1;
            continue_num[i][0][0] = 1;
            continue_num[i][0][1] = continue_num[i - 1][0][1] + 1;
            dp[i][0] = 1;
        } else {
            result[i][0] = result[i - 1][0];
            continue_num[i][0][0] = continue_num[i][0][1] = 0;
            dp[i][0] = 0;
        }
    }
    for (int i = 1; i < m; i++) {
        if (map[0][i] == 0) {
            result[0][i] = result[0][i - 1] + 1;
            continue_num[0][i][0] = continue_num[0][i - 1][0] + 1;
            continue_num[0][i][1] = 1;
            dp[0][i] = 1;
        } else {
            result[0][i] = result[0][i - 1];
            continue_num[0][i][0] = continue_num[0][i][1] = 0;
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (map[i][j] == 0) {
                continue_num[i][j][0] = continue_num[i][j - 1][0] + 1;
                continue_num[i][j][1] = continue_num[i - 1][j][1] + 1;
                dp[i][j] = min(min(continue_num[i - 1][j][1], continue_num[i][j - 1][0]), dp[i - 1][j - 1]) + 1;
                result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1] + dp[i][j];
            } else {
                continue_num[i][j][0] = continue_num[i][j][1] = 0;
                dp[i][j] = 0;
                result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1];
            }
        }
    }

    cout << result[n - 1][m - 1];
}