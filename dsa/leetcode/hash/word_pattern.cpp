//290
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<string>tokenize(string s) {
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss>>word){ 
            words.push_back(word);
        }
    
        return words;
    }
        bool wordPattern(string pattern, string s) {
            vector<string>words=tokenize(s);
            if(words.size()!=pattern.length()) return false;
            unordered_map<char,string>mp;
            int n=words.size();
            unordered_set<string>st;
            for(int i=0;i<n;i++){
                char temp=pattern[i];
                if(mp.count(temp)==0){
                    if(st.find(words[i])!=st.end()) return false;
                    //new char should not have used word,
                    //a-dog,in next iteration of b-dog,we see b has count of 0,so we
                    //try to insert,but dog is already used
                    else{
                        mp[temp]=words[i];
                        st.insert(words[i]);
                    }
                    
                } 
                else{
                    if(mp[temp]!=words[i]) return false;
                }
            }
            return true;
    
        }
    };
    int main(){
        Solution S;
        string pattern="abba";
        string s="dog cat cat dog";
        cout<<S.wordPattern(pattern,s)<<endl;
    }