//
// Created by Leokud on 29.04.2024.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using
std::map,
std::string,
std::vector,
std::cout,
std::cin,
std::pair,
std::stoi,
std::find,
std::cerr,
std::endl;
class Interpreter {
private:
    //hashmaps of variables
    static map<string, int> ints;
    static map<string, char> chars;
    static map<string, float> floats;
    static map<string, double> doubles;
    static map<string, long long> long_longs;
    //vector of variable names
    static vector<string> variables;
    //returns a pair of name and value split by '='

    static bool define_check(const string &s) {
        return std::find(variables.begin(), variables.end(), s) != variables.end();
    }

public:
    static vector<string> tokenize(const string &s) {
        vector<string> tokens;
        string curr;
        bool insideQuotes = false;

        for(char c : s) {
            if (c == '\"') {
                insideQuotes = !insideQuotes;
                if (!insideQuotes) {
                    tokens.emplace_back(curr);
                    curr.clear();
                }
                continue;
            }

            if (insideQuotes) {
                curr += c;
            } else {
                switch(c) {
                    case ' ':
                        if (!curr.empty()) {
                            tokens.emplace_back(curr);
                            curr.clear();
                        }
                    break;
                    case '=':
                    case '{':
                    case '}':
                    case '[':
                    case ']':
                    case '>':
                    case '<':
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '%':
                    case '\'':
                        if (!curr.empty()) {
                            tokens.emplace_back(curr);
                            curr.clear();
                        }
                    tokens.emplace_back(1, c);
                    break;
                    default:
                        curr += c;
                    break;
                }
            }
        }

        if (!curr.empty()) {
            tokens.emplace_back(curr);
        }

        return tokens;
    }




    int current_line_number = 0;


    //function to interpret code, first string is string to interpret, second int is number of string
    static void interpret(
        const std::string &codeString,
        int line_num)
        {
        vector<string> tokens = tokenize(codeString);
        //int variable creating
        if((tokens[0] == "int" || tokens[0] == "i32") && tokens[1] != "[") {
            if (tokens.size() > 2) {
                pair<string, string> pair_define = {tokens[1], tokens[3]};
                if(define_check(pair_define.first)) {
                    cerr << "Variable " << pair_define.first << " already defined" << endl;
                    exit(1);
                }
                variables.push_back(pair_define.first);
                if(define_check(pair_define.second)) {
                    ints[pair_define.first] = ints[pair_define.second];
                }
                else {
                    ints[pair_define.first] = stoi(pair_define.second);
                }
            }
            else {
                variables.push_back(tokens[1]);
                ints[tokens[1]] = 0;
            }

        }
        //char variable creating
        else if((tokens[0] == "char" || tokens[0] == "byte") && tokens[1] != "[" && tokens[2] == "\'"  && tokens[4] == "\'") {
            if (tokens.size() > 2) {
                pair<string, string> pair_define = {tokens[1], tokens[4]};
                if(define_check(pair_define.first)) {
                    cerr << "Variable " << pair_define.first << " already defined" << endl;
                    exit(1);
                }
                variables.push_back(pair_define.first);
                if(define_check(pair_define.second)) {
                    chars[pair_define.first] = chars[pair_define.second];
                }
                else {
                    chars[pair_define.first] = pair_define.second[0];
                }
            }
            else {
                variables.push_back(tokens[1]);
                chars[tokens[1]] = 0;
            }
        }
        //float variable creating
        else if((tokens[0] == "float" || tokens[0] == "f32") && tokens[1] != "[") {
            if (tokens.size() > 2) {
                pair<string, string> pi = {tokens[1], tokens[3]};
                if(define_check(pi.first)) {
                    cerr << "Variable " << pi.first << " already defined" << endl;
                    exit(1);
                }
                variables.push_back(pi.first);
                if(define_check(pi.second)) {
                    floats[pi.first] = floats[pi.second];
                }
                else {
                    floats[pi.first] = stof(pi.second);
                }
            }
            else {
                variables.push_back(tokens[1]);
                floats[tokens[1]] = 0;
            }
        }
        //double variable creating
        else if((tokens[0] == "double" || tokens[0] == "f64") && tokens[1] != "[") {
            if(tokens.size() > 2) {
                pair<string, string> pi = {tokens[1], tokens[3]};
                if(define_check(pi.first)) {
                    cerr << "Variable " << pi.first << " already defined" << endl;
                    exit(1);
                }
                variables.push_back(pi.first);
                if(define_check(pi.second)) {
                    doubles[pi.first] = doubles[pi.second];
                }
                else {
                    doubles[pi.first] = stod(pi.second);
                }
            }
            else {
                variables.push_back(tokens[1]);
                doubles[tokens[1]] = 0;
            }
        }
        //long long variable creating
        else if((tokens[0] == "longlong" || tokens[0] == "i64") && tokens[1] != "[") {
            if(tokens.size() > 2) {
                pair<string, string> pi = {tokens[1], tokens[3]};
                if(define_check(pi.first)) {
                    cerr << "Variable " << pi.first << " already defined" << endl;
                    exit(1);
                }
                variables.push_back(pi.first);
                if(define_check(pi.second)) {
                    long_longs[pi.first] = long_longs[pi.second];
                }
                else {
                    long_longs[pi.first] = stoll(pi.second);
                }
            }
            else {
                variables.push_back(tokens[1]);
                long_longs[tokens[1]] = 0;
            }

        }
        //printing value or any argument
        else if (tokens[0] == "print") {
            const auto& name = tokens[1];
            if(ints.find(name) != ints.end()) {
                cout << ints[name];
            }
            else if(chars.find(name) != chars.end()) {
                cout << chars[name];
            }
            else if(floats.find(name) != floats.end()) {
                cout << floats[name];
            }
            else if(doubles.find(name) != doubles.end()) {
                cout << doubles[name];
            }
            else if(long_longs.find(name) != long_longs.end()) {
                cout << long_longs[name];
            }
            else {
                cout << name;
            }
        }
        //input
        else if(tokens[0] == "get") {
            if(!define_check(tokens[1])) {
                cerr << "Variable " << tokens[1] << " is not defined" << endl;
            }
            else {
                if(ints.find(tokens[1]) != ints.end()) {
                    cin >> ints[tokens[1]];
                }
                else if(chars.find(tokens[1]) != chars.end()) {
                    cin >> chars[tokens[1]];
                }
                else if(floats.find(tokens[1]) != floats.end()) {
                    cin >> floats[tokens[1]];
                }
                else if(doubles.find(tokens[1]) != doubles.end()) {
                    cin >> doubles[tokens[1]];
                }
                else if(long_longs.find(tokens[1]) != long_longs.end()) {
                    cin >> long_longs[tokens[1]];
                }
                else{
                    cerr << "Variable " << tokens[1] << " is not defined but in variables list" << endl;
                }
            }
        }
        //for comment
        else if(codeString.substr(0, 2) == "//") {}
            //
        else{
            cerr << "Error in string" << codeString << line_num++ << std::endl;
            exit(1);
        }
        if(tokens[0] == "nln" || tokens[tokens.size()-1] == "nln") {
            cout << endl;
        }

    }
};


#endif //INTERPRETER_H
