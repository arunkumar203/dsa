//1423
//In one step, you can take one card from the beginning or from 
//the end of the row. You have to take exactly k cards.
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int ans=0;
            for(int i=0;i<k;i++){
                ans+=cardPoints[i];
            }
            int temp=ans;
            int j=cardPoints.size()-1;
            for(int i=k-1;i>=0;i--){
                temp-=cardPoints[i];
                temp+=cardPoints[j--];
                if(temp>ans){
                    ans=temp;
                }
    
            }
            return ans;
    
        }
    };
    int main(){
        Solution s;
        vector<int>cardPoints={1,2,3,4,5,6,1};
        int k=3;
        cout<<s.maxScore(cardPoints,k)<<endl;
    }