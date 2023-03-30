/*现有一个背包可以容纳总重量为W的物品，有n种物品可以放入背包，其中每种物品单个重量为w_i，价值为v_i，可选数量为num_i
输出可以放入背包的物品的最大总价值。*/
#include <algorithm>
#include <iostream>
using namespace std;

int w[205];
int v[205];
int num[205];
int dp[205][10005];

int main() {
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i] >> num[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= num[i] && k * w[i] <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][W];
}