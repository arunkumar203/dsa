#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
void find1(TreeNode*root,vector<vector<int>>&ans,vector<int>&temp){
    if(root==NULL) return;
    if(root->left==NULL&&root->right==NULL) {
        temp.push_back(root->val);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.push_back(root->val);
    find1(root->left,ans,temp);
    temp.pop_back();
    temp.push_back(root->val);
    find1(root->right,ans,temp);
    temp.pop_back();
}
void find2(TreeNode* root, vector<vector<int>>& ans, vector<int> temp) {
    if (root == NULL) return;

    temp.push_back(root->val);

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(temp);
        return;
    }

    find2(root->left, ans, temp);
    find2(root->right, ans, temp);
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);
    vector<vector<int>>ans;
    vector<int>temp;
    // find1(root,ans,temp);
    find2(root,ans,temp);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
    //       1
    //     2         3
    //   4  5       6  7
    // 8 9 10 11 12 13 14 15
    
    
  