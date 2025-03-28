//stack using queue
#include <bits/stdc++.h>
using namespace std;
class MyStack {
    queue<int>a;
   queue<int>b;
public:
   MyStack(){
      

   }
   
   void push(int x){
       b.push(x);
       while(!a.empty()){
           b.push(a.front());
           a.pop();
       }
       swap(a,b);
   }
   
   int pop(){
       if(a.empty())return-1;
       int top=a.front();
       a.pop();
       return top;
   }
   
   int top(){
       return a.empty()?-1:a.front();
   }
   
   bool empty(){
       return a.empty();
   }
};

//queue using stack
class MyQueue {
    stack<int> a,b;

public:
    MyQueue() {}

    void push(int x) {
        b.push(x);
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        swap(a,b);
    }   
    int pop(){
        if (a.empty()) return -1;
        int top = a.top();
        a.pop();
        return top;
    }   
    int peek(){
        return a.empty()?-1:a.top();
    }   
    bool empty(){
        return a.empty();
    }
};

//stack using ll

class node{
    public:
    int val;
    node*next;
    node(int val){
        this->val=val;
        this->next=nullptr;
    }
};
class Stack{
    node *head;
    public:
    Stack(){
        head=nullptr;
    }
    
    public:
    void push(int val){
        node *temp=new node(val);
        temp->next=head;
        head=temp;
        
    }
    int pop(){
        if(head==nullptr) -1;
        node*temp=head;
        int ans=head->val;
        head=head->next;
        delete temp;
        return ans;
        
        
    }
};

//queue using ll
class Node {
    public:
        int val;
        Node* next;
        
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };
    
    class Queue {
    private:
        Node* front;  // Points to the first element
        Node* rear;   // Points to the last element
    
    public:
        Queue() {
            front = rear = nullptr;
        }
    
        void push(int val) {
            Node* newNode = new Node(val);
            if (rear == nullptr) {
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }
    
        int pop() {
            if (front == nullptr) {
                cout << "Queue underflow!" << endl;
                return -1;
            }
            int poppedVal = front->val;
            Node* temp = front;
            front = front->next;
            if (front == nullptr) rear = nullptr; // If queue is empty
            delete temp;
            return poppedVal;
        }
    
        int peek() {
            return (front == nullptr) ? -1 : front->val;
        }
    
        bool empty() {
            return front == nullptr;
        }
    };

    
int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.empty() << endl;
    
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.peek() << endl;
    cout << q.empty() << endl;
    
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    
    Queue qll;
    qll.push(1);
    qll.push(2);
    qll.push(3);
    cout << qll.peek() << endl;
    cout << qll.pop() << endl;
    cout << qll.peek() << endl;
    cout << qll.empty() << endl;
    return 0;
}
