#include <iostream>
using namespace std;
int temp1[1000005];
int temp2[1000005];
int temp[1000005];

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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> temp2[i];
    }
    mergesort(temp1, 0, n - 1);
    mergesort(temp2, 0, m - 1);
    int i = 0, j = 0, flag = 0;
    while (i < n && j < m) {
        if (temp1[i] > temp2[j]) {
            j++;
        } else if (temp1[i] < temp2[j]) {
            i++;
        } else if (temp1[i] == temp2[j]) {
            if (flag != 0) {
                cout << ' ';
            } else {
                flag = 1;
            }
            cout << temp1[i];
            i++;
            j++;
            while (i < n && temp1[i] == temp1[i - 1]) {
                i++;
            }
            while (j < m && temp2[j] == temp2[j - 1]) {
                j++;
            }
        }
    }
    if (flag == 0) {
        cout << -1;
    }
}