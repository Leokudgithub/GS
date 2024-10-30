#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include "interpreter.h"
using namespace std;
Interpreter interpreter;
map<string, int> Interpreter::ints;
map<string, char> Interpreter::chars;
map<string, float> Interpreter::floats;
map<string, double> Interpreter::doubles;
map<string, long long> Interpreter::long_longs;
vector<string> Interpreter::variables;
int main(int argc, char* argv[]) {
    if(argc == 3 && strcmp(argv[1], "run") == 0)
    {
        string filepath =  argv[2];
        ifstream file(filepath);
        if (!file.is_open()) {
            cerr << "file opening error" << std::endl;
            return 1;
        }
        vector<std::string> code;
        string line;
        while (getline(file, line)) {
            code.push_back(line);
        }
        file.close();
        while (interpreter.current_line_number < code.size()) {
            //Interpreter::interpret(code[interpreter.current_line_number], interpreter.current_line_number);
            interpreter.current_line_number++;
        }
    }
    else {
        cout << "testing mode \n";
        vector<string> test2 = Interpreter::tokenize("a + = b");
        Interpreter::interpret("print \"Calculator\"nln", 1);
        Interpreter::interpret("print \"enter 2 numbers:\" ", 1);
        Interpreter::interpret("float a", 1);
        Interpreter::interpret("float b", 2);
        Interpreter::interpret("get a", 3);
        Interpreter::interpret("get b", 4);
        Interpreter::interpret("float sum", 5);
        Interpreter::interpret("float sub", 5);
        Interpreter::interpret("float mult", 5);
        Interpreter::interpret("float div", 5);
        Interpreter::interpret("sum = a + b", 5);
        Interpreter::interpret("sub = a - b", 5);
        Interpreter::interpret("mult = a * b", 5);
        Interpreter::interpret("div = a / b", 5);
        Interpreter::interpret("print sum nln", 5);
        Interpreter::interpret("print sub nln", 5);
        Interpreter::interpret("print mult nln", 5);
        Interpreter::interpret("print div nln", 5);

    }
    system("pause");
    return 0;
}