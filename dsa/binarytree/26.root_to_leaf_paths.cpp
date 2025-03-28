//257
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
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ans;
            if (!root) return ans;
            dfs(root, "", ans);
            return ans;
        }
        void dfs(TreeNode* root, string path, vector<string>& ans) {
            if (!root) return;
            path += to_string(root->val);
            if (!root->left && !root->right) {
                ans.push_back(path);
                return;
            }
            path += "->";
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }
    };
    int main() {
        ios::sync_with_stdio(0); cin.tie(0);
        
        // Create a sample binary tree
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(5);
        
        Solution sol;
        vector<string> ans = sol.binaryTreePaths(root);
        
        for (string s : ans) cout << s << endl;
        
        return 0;
    }