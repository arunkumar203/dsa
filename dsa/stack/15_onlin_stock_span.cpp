//901
#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
    public:
    stack<pair<int,int>>st;
    int ind;
        StockSpanner() {
            ind=0;
        }
        
        int next(int price) {
            ind++;
            while(!st.empty() && st.top().first<=price) st.pop();
            int ans=st.empty()?(ind):(ind-st.top().second);
    
            st.push({price,ind});
            return ans;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */
    
int main(){
    StockSpanner* obj = new StockSpanner();
    cout<<obj->next(100)<<endl;
    cout<<obj->next(80)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(70)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(75)<<endl;
    cout<<obj->next(85)<<endl;
    return 0;
}
