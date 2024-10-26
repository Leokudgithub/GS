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
    static pair<string, string> split(
        const string &s)
        {
        pair<string, string> result;
        bool is_after = false;
        for(const auto &c : s) {
            if(c == '=') {
                is_after = true;
            }
            else {
                if(is_after and c!=' ') {
                    result.second = result.second + c;
                }
                else if(!is_after and c!=' ') {
                    result.first = result.first + c;
                }
            }
        }
        return result;
    }
    static bool define_check(const string &s) {
        return std::find(variables.begin(), variables.end(), s) != variables.end();
    }
public:
    int current_line_number = 0;
    //function to interpret code, first string is string to interpret, second int is number of string
    static void interpret(
        const std::string &codeString,
        int line_num)
        {
        //int variable creating
        if(codeString.substr(0, 3) == "int" || codeString.substr(0, 3) == "i32") {
            string name_and_value = codeString.substr(4);
            pair<string, string> pi = split(name_and_value);
            if(define_check(pi.first)) {
                cerr << "Variable " << pi.first << " already defined" << endl;
                exit(1);
            }
            variables.push_back(pi.first);
            ints[pi.first] = stoi(pi.second);

        }
        //char variable creating
        else if(codeString.substr(0, 4) == "char") {
            string name_and_value = codeString.substr(5);
            pair<string, string> pc = split(name_and_value);
            if(define_check(pc.first)) {
                cerr << "Variable " << pc.first << " already defined" << endl;
                exit(1);
            }
            else {
                chars[pc.first] = pc.second[0];
                variables.push_back(pc.first);
            }
        }
        //float variable creating
        else if (codeString.substr(0, 3) == "f32") {
            string name_and_value = codeString.substr(4);
            pair<string, string> pf = split(name_and_value);
            if(define_check(pf.first)) {
                cerr << "Variable " << pf.first << " already defined" << endl;
                exit(1);
            }
            else {
                floats[pf.first] = stof(pf.second);
                variables.push_back(pf.first);
            }
        }
        //double variable creating
        else if (codeString.substr(0, 3) == "f64") {
            string name_and_value = codeString.substr(4);
            pair<string, string> pd = split(name_and_value);
            for(const auto& el: variables) {
                if(pd.first == el) {
                    cerr << "Variable " << el << " already defined" << endl;
                    exit(1);
                }
            }
            if(define_check(pd.first)) {
                cerr << "Variable " << pd.first << " already defined" << endl;
                exit(1);
            }
            else {
                doubles[pd.first] = stod(pd.second);
                variables.push_back(pd.first);
            }
        }
        //long long variable creating
        else if (codeString.substr(0, 3) == "i64") {
            string name_and_value = codeString.substr(4);
            pair<string, string> pi64 = split(name_and_value);
            for(const auto& el: variables) {
                if(pi64.first == el) {
                    cerr << "Variable " << el << " already defined" << endl;
                    exit(1);
                }
            }
            if(define_check(pi64.first)) {
                cerr << "Variable " << pi64.first << " already defined" << endl;
                exit(1);
            }
            else {
                long_longs[pi64.first] = stoll(pi64.second);
                variables.push_back(pi64.first);
            }
        }

        //printing value or any argument
        else if (codeString.substr(0, 5) == "print") {
            const auto name = codeString.substr(6);
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
                cout << "name";
            }

        }
        else if(codeString.substr(0, 3) == "nln"){
            cout << endl;
        }
        else if(codeString.substr(0, 2) == "//") {
            //
        }
        else{
            cerr << "Error in string" << codeString << line_num++ << std::endl;
    }

    };
};

#endif //INTERPRETER_H
