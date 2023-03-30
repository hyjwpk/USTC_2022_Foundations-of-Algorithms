#include <iostream>
using namespace std;
int arr[1000005];
int temp[1000005];
int result;

void merge(int p, int r) {
    int mid = (p + r) / 2;
    int i = p, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            result += (mid + 1 - i);
            result %= 10000007;
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = 0; i < k; i++) {
        arr[p + i] = temp[i];
    }
}

void mergesort(int p, int r) {
    if (p < r) {
        int mid = (p + r) / 2;
        mergesort(p, mid);
        mergesort(mid + 1, r);
        merge(p, r);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergesort(0, n - 1);
    cout << result;
}