//735
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int>st;
            int n=asteroids.size();
            for(auto i:asteroids){
                bool detro=false;
                //all ele in curr will be in same dir
                //collision occurs only if curr is moving left,top is moving right
                //curr moves till it can destroy all it prev small
                while(!st.empty() && i<0 && st.top()>0){
                    int top=st.top();
                    if(abs(i)>abs(top)) st.pop();
                    else if(abs(i)==abs(top)){
                        st.pop();
                        detro=true;
                        break;
                    }
                    else{
                        detro=true;
                        break;
    
                    }
                }
                if(!detro){
                    st.push(i);
                }
            }
            vector<int>ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };
    
int main(){
    Solution s;
    vector<int>arr={10,2,-5};
    vector<int>ans=s.asteroidCollision(arr);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}
