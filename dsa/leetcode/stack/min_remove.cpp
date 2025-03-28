//1249
//remove min ( or ) to make the string valid
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string minRemoveToMakeValid(string s) {
            int n=s.length();
            stack<int>st;
            unordered_set<int>se;
            for(int i=0;i<n;i++){
                if(s[i]=='(') st.push(i);
                else if(s[i]==')'){
                    if(!st.empty()) st.pop();
                    else se.insert(i);
                }
            }
            while(!st.empty()){
                se.insert(st.top());
                st.pop();
            }
            string ans="";
            for(int i=0;i<n;i++){
                if(se.find(i)==se.end()) ans.push_back(s[i]);
            }
            return ans;
        }
    };
    int main(){
        Solution s;
        cout<<s.minRemoveToMakeValid("lee(t(c)o)de)")<<endl;
        cout<<s.minRemoveToMakeValid("a)b(c)d")<<endl;
        cout<<s.minRemoveToMakeValid("))((")<<endl;
        cout<<s.minRemoveToMakeValid("(a(b(c)d)")<<endl;
        return 0;
    }