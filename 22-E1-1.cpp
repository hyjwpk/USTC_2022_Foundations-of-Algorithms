#include <iostream>
using namespace std;
int temp[1000005];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        temp[num] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (temp[i] == 0) {
            cout << i << endl;
        }
    }
}