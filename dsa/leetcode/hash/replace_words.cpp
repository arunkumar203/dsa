//648
//replace word with its root if it is present in dictionary
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    string findword(string word,unordered_set<string>&st){
        int n=word.length();
        for(int i=1;i<=n;i++){
            string root=word.substr(0,i);
            if(st.count(root)) return root;
            
        }
        return word;
    }
        string replaceWords(vector<string>& dictionary, string sentence) {
            unordered_set<string>st(dictionary.begin(),dictionary.end());
            stringstream ss(sentence);
            string word;
            string ans;
            while(getline(ss,word,' ')){
                ans+=findword(word,st)+' ';
            }
            ans.pop_back();
            return ans;
        }
    };
    int main(){
        Solution s;
        vector<string>dictionary={"cat","bat","rat"};
        string sentence="the cattle was rattled by the battery";
        cout<<s.replaceWords(dictionary,sentence)<<endl;
    }