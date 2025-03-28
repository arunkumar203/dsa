//987

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; // col -> (row -> {values})
    queue<pair<TreeNode*, pair<int, int>>> q; // {node, {col, row}}

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto [node, pos] = q.front();
        q.pop();
        int col = pos.first, row = pos.second;

        nodes[col][row].insert(node->val);

        if (node->left) 
            q.push({node->left, {col - 1, row + 1}});
        if (node->right) 
            q.push({node->right, {col + 1, row + 1}});
    }

    vector<vector<int>> result;
    for (auto& [col, rows] : nodes) {
        vector<int> colNodes;
        for (auto& [row, vals] : rows) 
            colNodes.insert(colNodes.end(), vals.begin(), vals.end());
        result.push_back(colNodes);
    }
    return result;
}






class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            map<int,map<int,vector<int>>>nodes;
            queue<pair<TreeNode*,pair<int,int>>>q;
            q.push({root,{0,0}});
            while(!q.empty()){
                auto [node,pos]=q.front();
                q.pop();
                int r=pos.first;
                int c=pos.second;
                nodes[r][c].push_back(node->val);
                if(node->left) q.push({node->left,{r+1,c-1}});
                if(node->right) q.push({node->right,{r+1,c+1}});
    
            }
            map<int,vector<int>>colval;
            for(auto row:nodes){
                for(auto col:row.second){
                    sort(col.second.begin(),col.second.end());
                    colval[col.first].insert(colval[col.first].end(),col.second.begin(),col.second.end());
    
                }
            }
            vector<vector<int>>ans;
            for(auto col:colval){
                ans.push_back(col.second);
            }
            return ans;
        }
    };
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        TreeNode* root=new TreeNode(1);
        root->left=new TreeNode(2);
        root->right=new TreeNode(3);
        root->left->left=new TreeNode(4);
        root->left->right=new TreeNode(5);
        root->right->left=new TreeNode(6);
        root->right->right=new TreeNode(7);
        Solution obj;
        vector<vector<int>>res=obj.verticalTraversal(root);
        for(auto x:res){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }
    // Time Complexity: O(NlogN)
    // Space Complexity: O(N)
         