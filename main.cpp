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
map<string, int> Interpreter::goto_points;
int Interpreter::current_line_number;
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
        while (Interpreter::current_line_number < code.size()) {
            Interpreter::interpret(code[Interpreter::current_line_number], Interpreter::current_line_number);
            Interpreter::current_line_number++;
        }
    }
    else {
        cout << "testing mode \n";
        vector<string> code = {
            "*p",
            "i64 a",
            "i64 b",
            "get a",
            "get b",
            "i64 c",
            "c = a + b",
            "out c nln",
            "~p"
        };
        while (Interpreter::current_line_number < code.size()) {
            Interpreter::interpret(code[Interpreter::current_line_number], Interpreter::current_line_number);
            Interpreter::current_line_number++;
        }

    }
    system("pause");
    return 0;
}