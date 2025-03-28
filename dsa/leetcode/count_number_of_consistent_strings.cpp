// 1684
// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
// Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
#include<bits/stdc++.h>
using namespace std;
int countConsistentStrings1(string allowed, vector<string>& words) {
        unordered_set<char>a;
        for(auto i:allowed){
            a.insert(i);
        }
        int ans=0;
        for(auto i:words){
            bool temp=true;
            for(auto j:i){
                if(a.find(j)==a.end()){
                    temp=false;
                    break;
                }
            }
            if(temp) ans++;
        }
        return ans;
    }
int countConsistentStrings2(string allowed, vector<string>& words) {
        int mask=0;
        for(auto i:allowed){
            mask|=(1<<(i-'a'));
        }
        int ans=0;
        for(auto i:words){
            bool temp=true;
            for(auto j:i){
                if(((mask>>(j-'a'))&1)==0){
                    temp=false;
                    break;
                }
            }
            if(temp) ans++;
        }
        return ans;
    }
int main(){
    string allowed="ab";
    vector<string>words={"ad","bd","aaab","baa","badab"};
    cout<<countConsistentStrings1(allowed,words)<<endl;
    cout<<countConsistentStrings2(allowed,words)<<endl;

    return 0;
}