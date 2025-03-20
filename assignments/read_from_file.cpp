#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file;
    file.open("file.csv");

    int val;

    while(file >> val) {
        std::cout << val << std::endl;
    }

    file.close();
    return 0;
}