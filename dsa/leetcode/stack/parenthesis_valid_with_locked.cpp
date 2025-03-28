//2116
//locked[i]=1 means ith parenthesis is locked
//if it is not locked,push that index to openclose
//if locked and s[i]=='(' push to open
//if locked and s[i]==')' pop from open,or openclose .if not both return false
//closed should appear after open,so if open.top()<openclose.top() pop from both
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool canBeValid(string s, string locked) {
            if(s.length()%2==1) return false;
            stack<int>open;
            stack<int>openclose;
            int n=s.length();
            for(int i=0;i<n;i++){
                if(locked[i]=='0'){
                    openclose.push(i);
                }
                else if(s[i]=='('){
                    open.push(i);
                }
                else if(s[i]==')'){
                    if(!open.empty()){
                        open.pop();
                    }
                    else if(!openclose.empty()){
                        openclose.pop();
                    }
                    else return false;
                }
            }
            while(!open.empty() && !openclose.empty() && open.top()<openclose.top()){
                open.pop();
                openclose.pop();
            }
            return open.empty() && openclose.size()%2==0;
            //openclose.size()%2==0; is not required as the end it will always have
            //even number in it(as odd will be eleminated in earlier stage itself)
    
        }
    };
    int main(){
        Solution s;
        cout << s.canBeValid("))()))","010100") << endl;


        return 0;
    }  