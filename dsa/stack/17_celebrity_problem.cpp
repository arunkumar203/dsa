#include <bits/stdc++.h>
using namespace std;

// Simulated knows function (for testing purposes)
// In a real CP environment, this would be provided by the problem
vector<vector<int>> M = {
    {0, 1,1, 0},
    {0, 0, 0,0},
    {0, 1, 0,0},
    {1, 1,0, 0}
};
bool knows(int a, int b) {
    return M[a][b];
}

// Function to find the celebrity
int findCelebrity(int n) {
    // Step 1: Find a candidate using two pointers
    int left = 0, right = n - 1;
    while (left < right) {
        if (knows(left, right)) {
            left++; // left can't be celebrity, move forward
        } else {
            right--; // right can't be celebrity, move backward
        }
    }
    int candidate = left; // or right, since they converge

    // Step 2: Verify the candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // Candidate must not know i, and i must know candidate
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1; // No celebrity exists
            }
        }
    }
    return candidate;
}

int main() {
    int n = 4; // Example with 4 people
    int result = findCelebrity(n);
    if (result == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is person " << result << endl;
    }
    return 0;
}