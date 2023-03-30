/*对一个由正整数组成的数组arr[]进行重新排列，使得排列后的数组从前到后组成一个最大的数（数组内元素不可拆分）。
例如3 92 10 4数组重新排列后可得到最大的数字为924310。
输出结果可能非常大，请以字符串输出。*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string arr[10005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = to_string(num);
    }
    sort(arr, arr + n, [](string a, string b) { return a + b > b + a; });
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
}