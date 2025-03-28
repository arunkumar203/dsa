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

void iterativePostorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (!st.empty() || current) {
        if (current) {
            st.push(current);
            current = current->left;
        } else {
            TreeNode* topNode = st.top();
            if (topNode->right && lastVisited != topNode->right) {
                current = topNode->right;
            } else {
                cout << topNode->val << " ";
                lastVisited = topNode;
                st.pop();
            }
        }
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
    cout << endl;

    return 0;
}