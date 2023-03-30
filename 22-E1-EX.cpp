#include <cstdlib>
#include <iostream>
using namespace std;
int temp1[1000005];
int temp2[1000005];
int temp3[1000005];
int temp4[1000005];

class Node {
public:
    int key;
    int value;
    class Node *next;
    Node() {
        key = value = 0;
        next = NULL;
    }
};

class HashTable {
public:
    Node **array;
    int size;
    HashTable(int size) {
        array = (Node **)malloc(size * sizeof(Node *));
        for (int i = 0; i < size; i++) {
            array[i] = NULL;
        }
        this->size = size;
    }
    int Hashfunc(int key) {
        return abs(key) % size;
    }
    Node *Search(int key) {
        for (Node *p = array[Hashfunc(key)]; p != NULL; p = p->next) {
            if (key == p->key) {
                return p;
            }
        }
        return NULL;
    }
    void Insert(int key, int value) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->key = key;
        p->value = value;
        p->next = array[Hashfunc(key)];
        array[Hashfunc(key)] = p;
    }
};

int cmp(int a, int b) {
    return (temp2[a] == temp2[b]) ? temp1[a] < temp1[b] : temp2[a] < temp2[b];
}

void merge(int p, int r) {
    int mid = (p + r) / 2;
    int i = p, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (cmp(i, j)) {
            temp3[k] = temp1[i];
            temp4[k] = temp2[i];
            i++;
            k++;
        } else {
            temp3[k] = temp1[j];
            temp4[k] = temp2[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        temp3[k] = temp1[i];
        temp4[k] = temp2[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp3[k] = temp1[j];
        temp4[k] = temp2[j];
        j++;
        k++;
    }
    for (i = 0; i < k; i++) {
        temp1[p + i] = temp3[i];
        temp2[p + i] = temp4[i];
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
    HashTable h(1000005);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        Node *p = h.Search(temp);
        if (p == NULL) {
            h.Insert(temp, 1);
        } else {
            p->value++;
        }
    }
    int j = 0;
    for (int i = 0; i < h.size; i++) {
        for (Node *p = h.array[i]; p != NULL; p = p->next) {
            temp1[j] = p->key;
            temp2[j] = p->value;
            j++;
        }
    }
    mergesort(0, j - 1);
    for (int i = 0; i < j; i++) {
        for (int k = 0; k < temp2[i]; k++)
            cout << temp1[i] << ' ';
    }
}