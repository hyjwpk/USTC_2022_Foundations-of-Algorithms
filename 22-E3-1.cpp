/*对于一个长度为n的整数数组，请你找出一个具有最大和的连续子数组，输出其最大和。*/

#include <algorithm>
#include <iostream>
using namespace std;

long long a[100005];
long long dp[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0];
    long long result = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        if (dp[i] > result) {
            result = dp[i];
        }
    }
    cout << result;
}