#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         queue<pair<string, int>> q;
         q.push({beginWord, 1});
         unordered_set<string> st(wordList.begin(), wordList.end());
         st.erase(beginWord);
         while (!q.empty()){
            string word = q.front().first;
            cout<<word<<" ";
            int ans = q.front().second;
            q.pop();
            if (word == endWord) return ans;
            for (int i = 0; i < word.size(); i++){
                char temp = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, ans + 1});

                    }
                }
                word[i] = temp;
            }
         }
         return 0;
    }
};
int main() {
    Solution solution;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result = solution.ladderLength(beginWord, endWord, wordList);
    cout << "Minimum ladder length: " << result << endl;
    return 0;
}