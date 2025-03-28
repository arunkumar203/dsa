#include<iostream>
#include<vector>
using namespace std;

class stack {
    vector<int> s;

public:
    void push(int data) {
        s.push_back(data);
    }

    int pop() {
        int tmp = s.back();
        s.pop_back();
        return tmp;
    }

    void print() {
        for (auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }

    int top() {
        return s.back();
    }

    bool isempty() {
        return s.empty();
    }

    void insert_at_bottom(stack& s, int data) {
        if (s.isempty()) {
            s.push(data);
            return;
        }
        int tmp = s.pop();
        insert_at_bottom(s, data);
        s.push(tmp);
    }
    void reverse(stack& s){
    	if (s.isempty()) {
            return;
        }
        int tmp=s.pop();
        reverse(s);
        insert_at_bottom(s,tmp);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.insert_at_bottom(s, 5);
    s.print();
    s.reverse(s);
    s.print();

    return 0;
}
