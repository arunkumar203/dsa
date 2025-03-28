//543
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
    //assume diameter passed through curr node
    int find(TreeNode*root,int &ans){
        if(!root) return 0;
        int temp1=find(root->left,ans);
        int temp2=find(root->right,ans);
        ans=max(ans,temp1+temp2);
        return 1+max(temp1,temp2);
    }
        int diameterOfBinaryTree(TreeNode* root) {
            int ans=0;
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
        cout<<s.diameterOfBinaryTree(root)<<endl;
        return 0;
    }