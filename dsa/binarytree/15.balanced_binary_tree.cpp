//110
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    int find(TreeNode*root){
        if(!root) return 0;
        int l=find(root->left);
        int r=find(root->right);
        if(l==-1 || r== -1) return -1;
        if(abs(l-r)>1) return -1;
        return 1+max(find(root->left),find(root->right));
    }
        bool isBalanced(TreeNode* root) {
            return find(root)!=-1;
        }
    };
    int main(){
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
        Solution s;
        cout<<s.isBalanced(root)<<endl;
        return 0;
    }
  