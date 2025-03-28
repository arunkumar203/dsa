#include<bits/stdc++.h>
using namespace std;
int main(){
    // ofstream file1;
    // file1.open("hello2.txt");
    // file1<<"sam hello";
    // file1.close();

    ifstream file2;
    string s;
    file2.open("hello2.txt");
    // file2>>s;
    // cout<<s<<endl;
    while(file2.eof()==0){
        getline(file2, s);
        cout<<s<<endl;
    }
    file2.close();
    return 0;
}




// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int main() {
//     ifstream file2;
//     string s;
//     file2.open("hello2.txt");

//     // Check if the file was successfully opened
//     if (!file2) {
//         cout << "Error opening the file." <<endl;
//         return 1;
//     }

//     // Read and display the file contents line by line
//     while (getline(file2, s)) {
//         cout << s << endl;
//     }

//     file2.close();
//     return 0;
// }
