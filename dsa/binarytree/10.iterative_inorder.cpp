#include <iostream>
#include <stack>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* current = root;
    while (current || !st.empty()) {
        while (current) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    iterativeInorder(root);
    return 0;
}