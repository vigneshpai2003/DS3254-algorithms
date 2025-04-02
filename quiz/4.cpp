#include <fstream>
#include <vector>
#include <iostream>

int main(int argsn, char** args) {
    char* infile = args[1];
    char* outfile = args[2];

    std::ifstream file;

    int var, n;

    file.open(infile);

    file >> n;

    std::vector<int> rx;
    std::vector<int> ry;

    while (file >> var) {
        rx.push_back(var);
        file >> var;
        ry.push_back(var);
    }

    file.close();

    std::ofstream output;

    output.open(outfile);

    output << "Reflexive ";

    bool isReflexive = true;

    for (int i = 1; i <= n; i++) {
        bool found = false;

        for (int index = 0; index < rx.size(); index++) {
            if (rx[index] == ry[index] && rx[index] == i) {
                found = true;
                break;
            }
        }

        if (!found) {
            isReflexive = false;
            break;
        }
    }

    if (isReflexive)
        output << "Yes";
    else
        output << "No";

    output << std::endl << "Symmetric ";

    bool isSymmetric = true;

    for (int i = 0; i < rx.size(); i++) {
        int x = rx[i];
        int y = ry[i];

        if (x != y) {
            bool found = false;

            for (int j = 0; j < rx.size(); j++) {
                if (i != j) {
                    if (rx[j] == y && ry[j] == x) {
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                isSymmetric = false;
                break;
            }
        }
    }

    if (isSymmetric)
        output << "Yes";
    else
        output << "No";

    output << std::endl << "Transitive ";

    bool isTransitive = true;

    for (int i = 0; i < rx.size() && isTransitive; i++) {
        int x = rx[i];
        int y = ry[i];

        for (int j = 0; j < rx.size(); j++) {
            if (rx[j] == y) {
                bool found = false;
                int z = ry[j];

                for (int k = 0; k < rx.size(); k++) {
                    if (rx[k] == x && ry[k] == z) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    isTransitive = false;
                    break;
                }
            }
        }
    }

    if (isTransitive)
        output << "Yes";
    else
        output << "No";

    output.close();

    return 0;
}