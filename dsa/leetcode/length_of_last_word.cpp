//58
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int n=s.length();
        int i=0;
        for(i=0;i<n;i++){
            if(s[i]==' ') continue;
            else break;
        }
        int ans=0;
        for(int j=i;j<n;j++){
            if(s[j]!=' ') ans++;
            else if(s[j]==' ') break;
        }
        return ans;

    }
};
int main(){
    string s="Hello World";
    Solution ss;
    cout<<ss.lengthOfLastWord(s)<<endl;
}