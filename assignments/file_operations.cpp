#include <string>
#include <iostream>
#include <fstream>

int read() {
    std::ifstream file;
    file.open("file.txt");

    int val;

    while(file >> val) {
        std::cout << val << std::endl;
    }

    file.close();
    return 0;
}

int write() {
    std::ofstream file;
    file.open("file.txt");

    file << 1 << std::endl;

    file.close();
    return 0;
}

int main() {
    read();
    return 0;
}