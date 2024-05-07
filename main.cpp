#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include "interpreter.h"
using namespace std;
int main(int argc, char* argv[]) {
    if(argc == 3 && strcmp(argv[1], "run") == 0)
    {
        std::string filepath =  argv[2];
        std::ifstream file(filepath); // открываем файл для чтения
        if (!file.is_open()) {
            std::cerr << "file opening error" << std::endl;
            return 1;
        }
        std::vector<std::string> code;
        std::string line;
        while (std::getline(file, line)) {
            code.push_back(line);
        }
        file.close(); // закрываем файл
        while (line_num < code.size()) {
            handle(code[line_num], line_num);
            line_num++;
        }
    }
    return 0;
}