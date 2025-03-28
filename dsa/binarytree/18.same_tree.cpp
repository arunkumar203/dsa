//100
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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(!p&&!q) return true;
            if(!p||!q) return false;
            if(p->val!=q->val) return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };
int main(){
    // Tree structure:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

    Solution s;
    cout<<s.isSameTree(root1,root2)<<endl;
    return 0;
}