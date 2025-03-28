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
        vector<int> bottomView(TreeNode* root) {
            vector<int> ans;
            if (!root) return ans;
    
            // Map to store column -> last node value
            map<int, int> nodes;  // col -> val
            
            // Queue for BFS: {node, column}
            queue<pair<TreeNode*, int>> q;
            q.push({root, 0});  // Root at column 0
            
            while (!q.empty()) {
                auto [node, col] = q.front();
                q.pop();
                
                // Update column with current node’s value (last one wins)
                nodes[col] = node->val;
                
                // Enqueue children with updated columns
                if (node->left) q.push({node->left, col - 1});
                if (node->right) q.push({node->right, col + 1});
            }
            
            // Extract values from map in column order
            for (auto& [col, val] : nodes) {
                ans.push_back(val);
            }
            
            return ans;
        }
    };
    int main() {
        ios::sync_with_stdio(0); cin.tie(0);
        
        // Create a sample binary tree
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        
        Solution sol;
        vector<int> ans = sol.bottomView(root);
        
        for (int x : ans) cout << x << " ";
        
        return 0;
    }