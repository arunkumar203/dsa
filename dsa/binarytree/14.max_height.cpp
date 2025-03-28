//104
#include <bits/stdc++.h>
using namespace std;


  struct TreeNode {
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
        return 1+max(find(root->left),find(root->right));
    }
        int maxDepth(TreeNode* root) {
            return find(root);
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
        cout<<s.maxDepth(root)<<endl;
        return 0;
    }