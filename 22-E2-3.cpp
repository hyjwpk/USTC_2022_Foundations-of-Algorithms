/* C语言中需要申请一块连续的内存时需要使用malloc等函数。如果分配成功则返回指向被分配内存的指针(此存储区中的初始值不确定)，
否则返回空指针NULL。现在小明决定实现一个类似malloc的内存分配系统，具体来说，他需要连续处理若干申请内存的请求，
这个请求用一个闭区间[a_i..b_i]来表示。当这个区间和当前已被申请的内存产生重叠时，则返回内存分配失败的信息。否则返回内存分配成功，
并将该区间标记为已被占用。假设初始状态下内存均未被占用，管理的内存地址范围为0~1GB（0~2^{30}）。*/

#include <iostream>
using namespace std;

// Interval Tree
class Node {
public:
    int ileft;
    int iright;
    int max;
    Node *left;
    Node *right;
    Node *parent;
    Node() {
        ileft = iright = max = 0;
        left = right = parent = NULL;
    }
};

Node *tree = NULL;

bool search(Node *root, int left, int right) {
    while (root != NULL && (root->ileft > right || root->iright < left)) {
        if (root->left != NULL && root->left->max >= left) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root == NULL ? false : true;
}

bool insert(Node *root, int left, int right) {
    if (root == NULL) {
        tree = new Node();
        tree->ileft = left;
        tree->iright = right;
        tree->max = right;
        return true;
    }
    if (search(root, left, right)) {
        return false;
    }
    while (root != NULL) {
        if (root->ileft > left) {
            if (root->left == NULL) {
                break;
            }
            root = root->left;
        } else {
            if (root->right == NULL) {
                break;
            }
            root = root->right;
        }
    }
    Node *node = new Node();
    node->ileft = left;
    node->iright = right;
    node->max = right;
    node->parent = root;
    if (root->ileft > left) {
        root->left = node;
    } else {
        root->right = node;
    }
    while (root != NULL) {
        int lmax = root->left == NULL ? 0 : root->left->max;
        int rmax = root->right == NULL ? 0 : root->right->max;
        root->max = max(lmax, rmax);
        root->max = max(root->max, root->iright);
        root = root->parent;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int left, right;
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        if (insert(tree, left, right)) {
            cout << "0" << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}
