// 给定某二叉树的前序序列和中序序列，输出该二叉树的后序序列。（输入的前序遍历和中序遍历的结果中都不含重复的数字）

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    class Node *left;
    class Node *right;
    Node() {
        value = 0;
        left = right = NULL;
    }
};

int index = 0;

Node *buildtree(int *preorder, int *inorder, int begin, int end) {
    if (begin >= end) {
        return NULL;
    }
    Node *root = new Node();
    root->value = preorder[index];
    int pos = 0;
    for (int i = begin; i < end; i++) {
        if (inorder[i] == preorder[index]) {
            pos = i;
            break;
        }
    }
    index++;
    root->left = buildtree(preorder, inorder, begin, pos);
    root->right = buildtree(preorder, inorder, pos + 1, end);
    return root;
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        if (index == 0) {
            index = 1;
            cout << root->value;
        } else {
            cout << " " << root->value;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int *preorder = new int[n];
    int *inorder = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    Node *root = buildtree(preorder, inorder, 0, n);
    index = 0;
    postorder(root);
    return 0;
}