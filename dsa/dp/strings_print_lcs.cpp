#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int m, int n, const string& s1, const string& s2, vector<vector<int>>& dp, string& lcs) {
        if (m < 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        
        if (s1[m] == s2[n]) {
            int len = 1 + find(m-1, n-1, s1, s2, dp, lcs);
            lcs.push_back(s1[m]);
            return dp[m][n] = len;
        }
        return dp[m][n] = max(find(m-1, n, s1, s2, dp, lcs), find(m, n-1, s1, s2, dp, lcs));
    }

    pair<int, string> longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        string lcs;
        int length = find(text1.size()-1, text2.size()-1, text1, text2, dp, lcs);
        return {length, lcs};
    }
    void printLCS(const string& s1, const string& s2, const vector<vector<int>>& dp) {
    int m = s1.size();
    int n = s2.size();
    string lcs;
    int i = m, j = n;
    
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    cout << "LCS: " << lcs << endl;
}

};

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    Solution s;
    auto result = s.longestCommonSubsequence(s1, s2);
    cout << "Length of LCS: " << result.first << endl;
    cout << "LCS: " << result.second << endl;
    return 0;
}
