//146
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int key;
    int val;
    node*next;
    node*prev;
    node(int key,int val){
        this->key=key;
        this->val=val;
    }
};
class LRUCache {
public:
int capacity;
unordered_map<int,node*>mp;
node *head;
node *tail;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;

    }
     void addNode(node* newNode){
        newNode->next=head->next;
        newNode->prev=head;
        head->next->prev=newNode;
        head->next=newNode;
    }
    // void addNode(node *temp){
    //     temp->next=head->next;
    //     temp->prev=head;
    //     head->next=temp;
    //     temp->next->prev=temp;

    // }

    void deleteNode(node* delNode){
        delNode->prev->next=delNode->next;
        delNode->next->prev=delNode->prev;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        node *temp=mp[key];
        int ans=temp->val;
        mp.erase(key);
        deleteNode(temp);
        addNode(temp);
        mp[key]=head->next;
        return ans;


    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node *temp=new node(key,value);
        addNode(temp);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;
    return 0;
}
