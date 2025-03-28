#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int req;
    string ans;

    void find(int ind, string &s, int k, vector<int> &freq) {
        if (ind == s.length()) {
            req++;
            if (req == k) {
                ans = s;
            }
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (!freq[i]) {
                s[ind] = i + '1'; 
                freq[i] = 1;
                find(ind + 1, s, k, freq);
                freq[i] = 0;
            }
        }
    }

    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; i++) {
            s += to_string(i);
        }

        vector<int> freq(s.length(), 0);
        find(0, s, k, freq);
        return ans;
    }
};
int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution obj;
    string result = obj.getPermutation(n, k);
    cout << "The kth permutation is: " << result << endl;

    return 0;
}