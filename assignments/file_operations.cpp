#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// std::stoi converts string to integer
// std::stof converts string to float
// std::stod converts string to double
// std::to_string converts integer to string
// std::stringstream is like a file stream but for strings

int read() {
    std::ifstream file;
    file.open("file.txt");

    std::string val;

    while(file >> val) {
        std::cout << std::stoi(val) << std::endl;
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