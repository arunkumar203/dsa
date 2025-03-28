//20
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char>st;
            for(auto i:s){
                if(i=='('||i=='{'||i=='[') st.push(i);
                else if(st.empty()||//still elements are left
                    (i==')'&&st.top()!='(')||
                    (i=='}'&&st.top()!='{')||
                    (i==']'&&st.top()!='[')
                    ) return false;
                else st.pop();
            }
            return st.empty();
        }
    };
    
int main(){
    Solution s;
    string str="()[]{}";
    cout<<s.isValid(str)<<endl;
    str="([)]";
    cout<<s.isValid(str)<<endl;
    str="{[]}";
    cout<<s.isValid(str)<<endl;
    return 0;
}

