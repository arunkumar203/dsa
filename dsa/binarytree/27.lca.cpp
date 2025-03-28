#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* lca(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = lca(root->left, n1, n2);
    Node* rightLCA = lca(root->right, n1, n2);

    if (leftLCA && rightLCA) {
        return root;
    }

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->right = new Node();
    root->left->right->data = 5;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 7;

    int n1 = 4;
    int n2 = 5;
    Node* lcaNode = lca(root, n1, n2);

    if (lcaNode != nullptr) {
        std::cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is " << lcaNode->data << std::endl;
    } else {
        std::cout << "One or both nodes not found in the tree." << std::endl;
    }

    return 0;
}