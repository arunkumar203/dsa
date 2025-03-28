#include<bits/stdc++.h>
using namespace std;
//balanced binary tree will have hight diff bten left and right subtree atmost 1 
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
void inorder(TreeNode*root,vector<int>&tr){
    if(!root) return;
    inorder(root->left,tr);
    tr.push_back(root->val);
    inorder(root->right,tr);
}
TreeNode*find(int l,int r,vector<int>&tr){
    if(l>r) return NULL;
    int mid=(l+r)/2;
    TreeNode*root= new TreeNode(tr[mid]);
    root->left=find(l,mid-1,tr);
    root->right=find(mid+1,r,tr);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>tr;
        inorder(root,tr);
        int l=0,r=tr.size()-1;
        return find(l,r,tr);
    }
};
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Balance the binary tree
    TreeNode* balancedRoot = solution.balanceBST(root);
    
    // Print the values of the balanced binary tree in inorder traversal
    vector<int> inorderTraversal;
    solution.inorder(balancedRoot, inorderTraversal);
    for (int val : inorderTraversal) {
        cout << val << " ";
    }
    
    return 0;
}