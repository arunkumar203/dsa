#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file1("hello1.txt");
    ofstream file3("hello2.txt", ios::app);

    // if (!file1) {
    //     std::cout << "Error opening file1." << std::endl;
    //     return 1;
    // }

    // if (!file3) {
    //     std::cout << "Error opening file3." << std::endl;
    //     return 1;
    // }

    std::string line;
    while (std::getline(file1, line)) {
        file3 << line << std::endl;
    }
    

    file1.close();
    file3.close();

    std::cout << "Data appended successfully." << std::endl;
    return 0;
}
