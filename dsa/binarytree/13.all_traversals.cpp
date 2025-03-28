#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void allTraversals(TreeNode* root, vector<int>& pre, vector<int>& in, vector<int>& post) {
    if (!root) return;

    stack<pair<TreeNode*, int>> st;  // Stack stores node and state (1:pre, 2:in, 3:post)
    st.push({root, 1});

    while (!st.empty()) {
        TreeNode* node = st.top().first;
        int state = st.top().second;
        st.pop();

        if (state == 1) {  // Preorder: Process root first
            pre.push_back(node->val);
            st.push({node, 2});  // Push back for inorder
            if (node->left) st.push({node->left, 1});
        }
        else if (state == 2) {  // Inorder: Process after left subtree
            in.push_back(node->val);
            st.push({node, 3});  // Push back for postorder
            if (node->right) st.push({node->right, 1});
        }
        else {  // Postorder: Process after both subtrees
            post.push_back(node->val);
        }
    }
}

int main() {
    // Tree structure:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> preorder, inorder, postorder;
    allTraversals(root, preorder, inorder, postorder);

    cout << "Preorder: ";
    for (int val : preorder) cout << val << " ";
    cout << "\nInorder: ";
    for (int val : inorder) cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : postorder) cout << val << " ";
    cout << endl;

    return 0;
}