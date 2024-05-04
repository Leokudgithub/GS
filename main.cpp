#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "interpreter.h"
using namespace std;
int main() {
    std::string filepath;
    std::cout << "file: " << endl;
    std::getline(std::cin, filepath);

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

    int line_num = 0; // индекс строки для интерпретации
    while (line_num < code.size()) {
        handle(code[line_num], line_num);
        line_num++;
    }

    return 0;
}