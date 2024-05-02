//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream file("data.txt");

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {

            for (size_t i = 0; i < line.length(); ++i) {
                std::string token = "";
                if (line[i] == '#') {
                    i++;
                    while (i < line.length() && line[i] != '$' && line[i] != '#') {
                        token += line[i];
                        i++;
                    }
                    std::cout << std::right << std::setw(15) << token<<'\t';
                    i--;
                }
                else if (line[i] == '$') {
                    i++;
                    while (i < line.length() && line[i] != '$' && line[i] != '#') {
                        token += line[i];
                        i++;
                    }
                    std::cout << std::left << std::setw(15) << token<<'\t';
                    i--;
                }
            }
            std::cout << std::endl;
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file." << std::endl;
    }

    return 0;
}
