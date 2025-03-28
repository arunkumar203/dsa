//101
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    public:
    bool find(TreeNode*m,TreeNode*n){
        if(m==NULL && n==NULL) return true;
        if(m==NULL || n==NULL) return false;
        if(m->val==n->val) return find(m->left,n->right) && find(m->right,n->left);
        return false;
    }
        bool isSymmetric(TreeNode* root) {
            return find(root->left,root->right);
        }
    };
    int main() {
        ios::sync_with_stdio(0); cin.tie(0);
        
        // Create a sample binary tree
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(3);
        
        Solution sol;
        cout << sol.isSymmetric(root) << endl;
        
        return 0;
    }