#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void iterativePreorder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        cout << curr->val << " ";
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}

int main() {
    // Example tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    iterativePreorder(root);
    cout << endl;
    return 0;
}