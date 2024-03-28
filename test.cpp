#include <bits/stdc++.h>
using namespace std;
#define For(n) for(int i = 0; i < n; i++)

typedef struct BTNode {
    int val;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

int n;

void InsertTree(BTNode *root, int val) {
    if (val < root->val) {
        if (root->left == NULL) {
            BTNode *node = new BTNode;
            node->val = val;
            root->left = node;
        } else {
            InsertTree(root->left, val);
        }
    } else {
        if (root->right == NULL) {
            BTNode *node = new BTNode;
            node->val = val;
            root->right = node;
        } else {
            InsertTree(root->right, val);
        }
    }
    
}

vector<int> inOrder;
void InOrder(BTNode *root) {
    if (root == NULL) return;
    InOrder(root->left);
    inOrder.push_back(root->val);
    InOrder(root->right);
}

int main() {
    cin >> n;
    // 1. 构建二叉搜索树
    BTNode *root = new BTNode;
    cin >> root->val;
    n--;
    while (n--) {
        int x;
        cin >> x;
        InsertTree(root, x);
    }

    // 2. 中序遍历
    InOrder(root);

    // 3. 判断是否为二叉搜索树
    bool flag = true;
    for (int i = 0; i < inOrder.size() - 1; i++) {
        if (inOrder[i] > inOrder[i + 1]) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}