//155
#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack<long long> st;
    long long minVal;
public:
    MinStack() {        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        } else {
            if (val >= minVal) {
                st.push(val);
            } else {
                st.push(2LL * val - minVal);
                minVal = val;
            }
        }
    }
    
    void pop() {
        if (st.top() < minVal) {
            minVal = 2 * minVal - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.top() < minVal) {
            return minVal;
        }
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};
int main(){
    MinStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(-1);
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    return 0;
}
