//103
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>>ans;
            if(!root) return ans;
            queue<TreeNode*>q;
            q.push(root);
            bool ltor=true;
            while(!q.empty()){
                int tempsize=q.size();
                vector<int>temp(tempsize);
                for(int i=0;i<tempsize;i++){
                    TreeNode*node=q.front();
                    q.pop();
                    int idx=ltor?i:tempsize-i-1;
                    temp[idx]=node->val;
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
    
                }
                ans.push_back(temp);
                ltor=!ltor;
            }
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
    vector<vector<int>>ans=s.zigzagLevelOrder(root);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}