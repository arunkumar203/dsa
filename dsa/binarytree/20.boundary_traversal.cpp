#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* node) {
    return !node->left && !node->right;
}

void addLeftBoundary(Node* node, vector<int>& res) {
    while (node) {
        if (!isLeaf(node)) res.push_back(node->val);
        if (node->left) node = node->left;
        else node = node->right;
    }
}

void addRightBoundary(Node* node, vector<int>& res) {
    vector<int> temp;
    while (node) {
        if (!isLeaf(node)) temp.push_back(node->val);
        if (node->right) node = node->right;
        else node = node->left;
    }
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

void addLeaves(Node* node, vector<int>& res) {
    if (!node) return;
    if (isLeaf(node)) {
        res.push_back(node->val);
        return;
    }
    addLeaves(node->left, res);
    addLeaves(node->right, res);
}

vector<int> boundaryTraversal(Node* root) {
    if (!root) return {};
    
    vector<int> res;
    if (!isLeaf(root)) res.push_back(root->val);
    
    if (root->left) addLeftBoundary(root->left, res);
    addLeaves(root, res);
    if (root->right) addRightBoundary(root->right, res);
    
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    /* Example Tree:
            1
           / \
          2   3
         / \  / \
        4   5 6  7
    Expected Output: 1 2 4 5 6 7 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> boundary = boundaryTraversal(root);
    
    for (int x : boundary) cout << x << " ";
    cout << "\n";
    
    return 0;
}
