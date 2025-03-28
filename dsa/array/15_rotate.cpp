//48
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            for(int i=0;i<m;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
    
            for(int i=0;i<m;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }
    };
    int main(){
        Solution s;
        vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
        s.rotate(matrix);
        for(auto i:matrix){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }