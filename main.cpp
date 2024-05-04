#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "interpreter.h"
using namespace std;
int main() {
    std::string input;
    std::getline(std::cin, input);
    if(input.substr(0, 6) == "gs run")
    {
        std::string filepath = input.substr(7);
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

}