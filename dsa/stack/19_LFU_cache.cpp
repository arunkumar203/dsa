//460
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int key,val,freq;
    node *next,*prev;
    node(int k,int v){
        key=k;
        val=v;
        freq=1;
        next=prev=nullptr;
    }

};



class LFUCache {
public:
int capacity,minfreq;
        unordered_map<int,node*>mp;
        unordered_map<int,list<node*>>mp1;

        
        LFUCache(int capacity){
            this->capacity=capacity;
            this->minfreq=0;

        }
        

    void update(node *temp){
        int old=temp->freq;
        mp1[old].remove(temp);
        if(old==minfreq && mp1[old].empty()) minfreq++;
        temp->freq++;
        mp1[temp->freq].push_back(temp);
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        node *temp=mp[key];
        update(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *temp=mp[key];
            temp->val=value;
            update(temp);
            return ;

        }
        if(mp.size()==capacity){
            node *temp=mp1[minfreq].front();
            mp.erase(temp->key);
            mp1[minfreq].pop_front();
            delete temp;
        }
        node *temp=new node(key,value);
        minfreq=1;
        mp1[1].push_back(temp);
        mp[key]=temp;

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LFUCache* obj = new LFUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    cout<<obj->get(3)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;
    return 0;
}

