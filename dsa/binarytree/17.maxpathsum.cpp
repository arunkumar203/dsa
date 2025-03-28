//124
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
    int find(TreeNode*node,int &ans){
        if(!node) return 0;
        int l=max(0,find(node->left,ans));
        int r=max(0,find(node->right,ans));
        ans=max(ans,node->val+l+r);
        return node->val+max(l,r);
    }
        int maxPathSum(TreeNode* root) {
            int ans=INT_MIN;
            find(root,ans);
            return ans;
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
        cout<<s.maxPathSum(root)<<endl;
        return 0;
    }