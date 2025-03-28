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
    void find1(TreeNode*node,vector<int>&ans){
        if(!node) return;
        ans.push_back(node->val);
        find1(node->left,ans);
        find1(node->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
            vector<int>ans;
            find1(root,ans);
            return ans;
    }

    void find2(TreeNode*node,vector<int>&ans){
        if(!node) return;
        find2(node->left,ans);
        ans.push_back(node->val);
        find2(node->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int>ans;
            find2(root,ans);
            return ans;
    }


    void find3(TreeNode*node,vector<int>&ans){
        if(!node) return;
        find3(node->left,ans);
        find3(node->right,ans);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
            vector<int>ans;
            find3(root,ans);
            return ans;
    }

    vector<int>levelorder(TreeNode*root){
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int tempsize=q.size();
            vector<int>temp;
            for(int i=0;i<tempsize;i++){
                TreeNode* tempnode=q.front();
                q.pop();
                temp.push_back(tempnode->val);
                if(tempnode->left) q.push(tempnode->left);
                if(tempnode->right) q.push(tempnode->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    

};
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
    Solution s;
    vector<int>ans;
    // ans=s.preorderTraversal(root);
    // ans=s.inorderTraversal(root);
    // ans=s.postorderTraversal(root);
    // ans=s.levelorder(root);
    

    // for(auto i:ans){
    //     cout<<i<<" ";
    // }

    vector<vector<int>>ans2;
    ans2=s.levelOrder2(root);
    for(auto i:ans2){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}