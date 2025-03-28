#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1 pre
// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1  level

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* prebuild() {
    int d;
    cin >> d;
    if (d == -1) {
        return NULL;
    }
    node* n = new node(d);
    n->left = prebuild();
    n->right = prebuild();
    return n;
}
node *levelbuild(){
    int d;
    cin>>d;
    node *root=new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
         node *current=q.front();
    q.pop();
    int c1,c2;
    cin>>c1>>c2;
    if(c1!=-1){
        current->left=new node(c1);
        q.push(current->left);
    }
    if(c2!=-1){
        current->right=new node(c2);
        q.push(current->right);
    }
    }
    return root;

}

void preorder(node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelorder(node *root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* current = q.front();
        
       
        cout << current->data << " ";

        if (current->left )
            q.push(current->left);
        if (current->right)
            q.push(current->right);

        q.pop();
      
    }
}
void levelorder2(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* current = q.front();
        if(current==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout << current->data << " ";

        if (current->left )
            q.push(current->left);
        if (current->right)
            q.push(current->right);

        q.pop();
        }
    }
}
int height(node *root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}
int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int d1=height(root->left)+height(root->right);
    int d2=diameter(root->left);
    int d3=diameter(root->right);
    return max({d1,d2,d3});
}

int main() {
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    // node* root = prebuild();
    node *root =levelbuild();

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level-order traversal1: ";
    levelorder(root);
    cout << endl;

    cout << "Level-order traversal2: ";
    cout << endl;
    levelorder2(root);
    cout<<endl;

    cout<<"height is:"<<height(root)<<endl;
    cout<<"diameter is:"<<diameter(root);
    return 0;
}
