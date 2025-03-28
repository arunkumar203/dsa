#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to get the left view of the binary tree
vector<int> leftView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (i == 0) result.push_back(node->val); // Add the first node of each level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

// Function to get the right view of the binary tree
vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (i == n - 1) result.push_back(node->val); // Add the last node of each level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> left = leftView(root);
    vector<int> right = rightView(root);

    cout << "Left View: ";
    for (int val : left) cout << val << " ";
    cout << endl;

    cout << "Right View: ";
    for (int val : right) cout << val << " ";
    cout << endl;

    return 0;
}