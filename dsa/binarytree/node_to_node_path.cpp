
#include<bits/stdc++.h>
using namespace std;
//given 2 nodes,find path from node1 to node2 wit shortest path
//find lca of node1 and node2
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
    TreeNode* find(TreeNode* root,int p,int q) {
        if(root==NULL) return root;
        if(p==root->val||q==root->val) return root;
        TreeNode* leftn=find(root->left,p,q);
        TreeNode* rightn=find(root->right,p,q);
        if(leftn!=NULL&&rightn!=NULL) return root;
        if(leftn!=NULL) return leftn;
        return rightn; 
    }
    bool findpath(TreeNode*root,int src,string&path){
        if(root==NULL) return false;
        if(root->val==src) return true;
        path.push_back('L');
        if(findpath(root->left,src,path)==true) return true;
        path.pop_back();
        path.push_back('R');
        if(findpath(root->right,src,path)==true) return true;
        path.pop_back();
        return false;
    }
    string getDirections1(TreeNode* root, int startValue, int destValue) {
        TreeNode*lca=find(root,startValue,destValue);
        string lcatostart="";
        string lcatodest="";
        findpath(lca,startValue,lcatostart);
        findpath(lca,destValue,lcatodest);
        string ans="";
        for(int i=0;i<lcatostart.size();i++){
            ans.push_back('U');
        }
        ans+=lcatodest;
        return ans;
    }
     string getDirections2(TreeNode* root, int startValue, int destValue){
        string path1="";
        string path2="";
        findpath(root,startValue,path1);
        findpath(root,destValue,path2);
        string ans="";
        int i=0;
        for(i=0;i<path1.size();i++){
            if(path1[i]!=path2[i]){
                for(int j=i;j<path1.size();j++){
                    ans.push_back('U');
                }
                break;
                
            }
        }
        ans+=path2.substr(i,path2.size()-i);
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
    Solution s;
    // cout<<s.getDirections1(root,4,7)<<endl;
    cout<<s.getDirections2(root,4,7)<<endl;
    return 0;
}