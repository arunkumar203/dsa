#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
            int n=height.size();
            vector<int>front(n,0);
            front[0]=height[0];
            vector<int>back(n,0);
            back[n-1]=height[n-1];
            int maxi=0;
            for(int i=1;i<n;i++){
                front[i]=max(front[i-1],height[i]);
                // maxi=front[i];
            }
            maxi=0;
            for(int i=n-2;i>=0;i--){
                back[i]=max(back[i+1],height[i]);
                // maxi=back[i];
            }
            int ans=0;
            for(int i=0;i<n;i++){
                ans+=min(front[i],back[i])-height[i];
            }
            return ans;
        }
    };
    
int main(){
    Solution s;
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height)<<endl;
    return 0;
}
