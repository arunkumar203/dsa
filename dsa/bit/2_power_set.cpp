#include <iostream>
#include <vector>
using namespace std;
///for mask=3(011)
///     011  011  011
///     001  010  100
///     >0    >0   =0
//0,1 are included  which are 1,2
 
void generateSubsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = (1 << n);  // 2^n subsets
    
    for (int mask = 0; mask < totalSubsets; mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // Check if bit i is set
                cout << nums[i] << " ";
            }
        }
        cout << "}\n";
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    generateSubsets(nums);
    return 0;
}




// #include <iostream>
// #include <vector>
// using namespace std;

// void generateSubsets(vector<int>& nums) {
//     int n = nums.size();
//     int totalSubsets = (1 << n); // 2^n subsets

//     for (int mask = 0; mask < totalSubsets; mask++) { // Loop over all subset masks
//         vector<int> subset;

//         for (int i = 0; i < n; i++) { // Traverse from left (MSB) to right (LSB)
//             if (mask & (1 << (n - 1 - i))) {  // Checking bits from leftmost to rightmost
//                 subset.push_back(nums[i]);  // Add element if bit is set
//             }
//         }

//         // Print the subset
//         cout << "{ ";
//         for (int num : subset) {
//             cout << num << " ";
//         }
//         cout << "}\n";
//     }
// }

// int main() {
//     vector<int> nums = {1, 2, 3};  // Input array
//     generateSubsets(nums);
//     return 0;
// }

