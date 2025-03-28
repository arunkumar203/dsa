#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void iterativePostorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Iterative Postorder Traversal: ";
    iterativePostorder(root);

    return 0;
}