#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int main(int argsn, char** args) {
    char* infile = args[1];
    char* outfile = args[2];

    std::ifstream file;

    file.open(infile);

    int n;

    file >> n;

    std::string source_str, dest_str;

    std::vector<int> A, B, C;
    std::vector<int> src, dest;

    for (int i = n; i > 0; i--) {
        A.push_back(i);
    }

    std::ofstream out;
    out.open(outfile);

    while (file >> source_str) {
        file >> dest_str;

        src = source_str == "A" ? A : (source_str == "B" ? B : C);
        dest = dest_str == "A" ? A : (dest_str == "B" ? B : C);

        int move = src[src.size() - 1];

        if (move > dest[dest.size() - 1]) {
            out << "invalid" << std::endl;
        }

        src.pop_back();
        dest.push_back(move);

        if (source_str == "A") {
            A = src;
        } else if (source_str == "B") {
            B = src;
        } else {
            C = src;
        }

        if (dest_str == "A") {
            A = dest;
        } else if (dest_str == "B") {
            B = dest;
        } else {
            C = dest;
        }
    }

    out.close();

    return 0;
}