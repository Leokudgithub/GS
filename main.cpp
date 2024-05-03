#include <iostream>
#include <vector>
#include <string>
#include "interpreter.h"
int main() {
    std::vector<std::string> code;
    std::string input;
    while (std::getline(std::cin, input) && !input.empty()) {
        code.push_back(input);
    }
    //for (const auto& str : code) {handle(str);}
    int line = 0; //interpreting line
    while (line < std::size(code))
    {
        handle(code[line], line);
        line++;
    }
    return 0;
}