#include<bits/stdc++.h>
using namespace std;
int ninjaTraining2(int n, vector<vector<int>> &points);
int find(int n,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(n==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last) maxi=max(maxi,points[0][task]);
        }
        return maxi;
    }
    if(dp[n][last]!=-1) return dp[n][last];
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last) {
            int point=points[n][task]+find(n-1,task,points,dp);
            maxi=max(maxi,point);
            // cout<<n<<" "<<last<<" "<<task<<" "<<maxi<<endl;
        
        }

    }
    return dp[n][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(3, -1));
    int result = 0;
    for (int startTask = 0; startTask < 3; startTask++) {
        result = max(result, find(n - 1, startTask, points, dp));
    }
    //this will also work 
    return result;
}
int main(){
    int n=3;
    vector<vector<int>>points={{1,2,3},{4,5,6},{7,8,9}};
    cout<<ninjaTraining(n,points)<<endl;
    return 0;
}




//tabulation
int ninjaTraining2(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int task = 0; task < 3; task++) {
        dp[0][task] = points[0][task];
    }
    for (int day = 1; day < n; day++) {
        for (int task = 0; task < 3; task++) {
            int maxi = 0;
            for (int prevTask = 0; prevTask < 3; prevTask++) {
                if (prevTask != task) {
                    int point = points[day][task] + dp[day-1][prevTask];
                    maxi = max(maxi, point);
                }
            }
            dp[day][task] = maxi;
        }
    }


    return *max_element(dp[n-1].begin(), dp[n-1].end());
}
