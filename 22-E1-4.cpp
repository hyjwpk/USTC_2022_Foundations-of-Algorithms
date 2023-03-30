#include <iostream>
using namespace std;
int temp1[5005];
int temp[5005];

void merge(int arr[], int p, int r) {
    int mid = (p + r) / 2;
    int i = p, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
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

void mergesort(int arr[], int p, int r) {
    if (p < r) {
        int mid = (p + r) / 2;
        mergesort(arr, p, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, p, r);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp1[i];
    }
    mergesort(temp1, 0, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        int h = n - i;
        if (temp1[i] >= h && (i == 0 || temp1[i - 1] <= h)) {
            cout << h;
            break;
        }
    }
}