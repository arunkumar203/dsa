//402
// Given string num representing a non-negative integer num,
//  and an integer k, return the smallest possible integer after 
//  removing k digits from num.
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string removeKdigits(string num, int k) {
            stack<char>st;
            int n=num.size();
            if(n==k) return "0";
            for(char digit:num){
                while(!st.empty() && k>0 && st.top()>digit){
                    st.pop();
                    k--;
                }
                st.push(digit);
            }
            while(k>0 && !st.empty()){
                st.pop();
                k--;
            }
            string ans="";
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            int i=0;
            while(i<ans.size() && ans[i]=='0') i++;
            ans=ans.substr(i);
            return ans.empty()?"0":ans;
        }
    };
int main(){
    Solution s;
    string num="1432219";
    int k=3;
    cout<<s.removeKdigits(num,k)<<endl;
    return 0;
}
    

