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
    // name1: t = name2 s:{+, -, /, *, %} name3
    static void arithmetic_operators(const char t, char s, const string &name1, const string &name2, const string &name3) {

            if(s == '+') {
                switch (t) {
                    case 'i':
                        if(define_check(name2) && define_check(name3)) {
                            ints[name1] = ints[name2] + ints[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            ints[name1] = ints[name2] + stoi(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            ints[name1] = stoi(name2) + ints[name3];
                        }
                        else {
                            ints[name1] = stoi(name2) + stoi(name3);
                        }
                    break;
                    case 'c':
                        cerr << "char sum is not supported" << endl;
                    break;
                    case 'f':
                        if(define_check(name2) && define_check(name3)) {
                            floats[name1] = floats[name2] + floats[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            floats[name1] = floats[name2] + stof(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            floats[name1] = stof(name2) + floats[name3];
                        }
                        else {
                            floats[name1] = stof(name2) + stof(name3);
                        }
                    break;
                    case 'd':
                        if(define_check(name2) && define_check(name3)) {
                            doubles[name1] = doubles[name2] + doubles[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            doubles[name1] = doubles[name2] + stod(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            doubles[name1] = stod(name2) + doubles[name3];
                        }
                        else {
                            doubles[name1] = stod(name2) + stod(name3);
                        }
                    break;
                    case 'l':
                        if(define_check(name2) && define_check(name3)) {
                            long_longs[name1] = long_longs[name2] + long_longs[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            long_longs[name1] = long_longs[name2] + stoll(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            long_longs[name1] = stoll(name2) + long_longs[name3];
                        }
                        else {
                            long_longs[name1] = stoll(name2) + stoll(name3);
                        }
                    break;
                    default:
                        cerr << "sum of " << name2 << " and " << name3 << " is not supported" << endl;
                }
            }


            else if(s == '-') {
                switch (t) {
                    case 'i':
                        if(define_check(name2) && define_check(name3)) {
                            ints[name1] = ints[name2] - ints[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            ints[name1] = ints[name2] - stoi(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            ints[name1] = stoi(name2) - ints[name3];
                        }
                        else {
                            ints[name1] = stoi(name2) - stoi(name3);
                        }
                    break;
                    case 'c':
                        cerr << "char sub is not supported" << endl;
                    break;
                    case 'f':
                        if(define_check(name2) && define_check(name3)) {
                            floats[name1] = floats[name2] - floats[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            floats[name1] = floats[name2] - stof(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            floats[name1] = stof(name2) - floats[name3];
                        }
                        else {
                            floats[name1] = stof(name2) - stof(name3);
                        }
                    break;
                    case 'd':
                        if(define_check(name2) && define_check(name3)) {
                            doubles[name1] = doubles[name2] - doubles[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            doubles[name1] = doubles[name2] - stod(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            doubles[name1] = stod(name2) - doubles[name3];
                        }
                        else {
                            doubles[name1] = stod(name2) - stod(name3);
                        }
                    break;
                    case 'l':
                        if(define_check(name2) && define_check(name3)) {
                            long_longs[name1] = long_longs[name2] - long_longs[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            long_longs[name1] = long_longs[name2] - stoll(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            long_longs[name1] = stoll(name2) - long_longs[name3];
                        }
                        else {
                            long_longs[name1] = stoll(name2) - stoll(name3);
                        }
                    break;
                    default:
                        cerr << "subtraction of " << name2 << " and " << name3 << " is not supported" << endl;
                }
            }

            else if(s == '*') {
                switch (t) {
                    case 'i':
                        if(define_check(name2) && define_check(name3)) {
                            ints[name1] = ints[name2] * ints[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            ints[name1] = ints[name2] * stoi(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            ints[name1] = stoi(name2) * ints[name3];
                        }
                        else {
                            ints[name1] = stoi(name2) * stoi(name3);
                        }
                    break;
                    case 'c':
                        cerr << "char multiplication is not supported" << endl;
                    break;
                    case 'f':
                        if(define_check(name2) && define_check(name3)) {
                            floats[name1] = floats[name2] * floats[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            floats[name1] = floats[name2] * stof(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            floats[name1] = stof(name2) * floats[name3];
                        }
                        else {
                            floats[name1] = stof(name2) * stof(name3);
                        }
                    break;
                    case 'd':
                        if(define_check(name2) && define_check(name3)) {
                            doubles[name1] = doubles[name2] * doubles[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            doubles[name1] = doubles[name2] * stod(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            doubles[name1] = stod(name2) * doubles[name3];
                        }
                        else {
                            doubles[name1] = stod(name2) * stod(name3);
                        }
                    break;
                    case 'l':
                        if(define_check(name2) && define_check(name3)) {
                            long_longs[name1] = long_longs[name2] * long_longs[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            long_longs[name1] = long_longs[name2] + stoll(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            long_longs[name1] = stoll(name2) + long_longs[name3];
                        }
                        else {
                            long_longs[name1] = stoll(name2) + stoll(name3);
                        }
                    break;
                    default:
                        cerr << "sum of " << name2 << " and " << name3 << " is not supported" << endl;
                }
            }
            else if(s == '/') {
                switch (t) {
                    case 'i':
                        if(define_check(name2) && define_check(name3)) {
                            ints[name1] = ints[name2] / ints[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            ints[name1] = ints[name2] / stoi(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            ints[name1] = stoi(name2) / ints[name3];
                        }
                        else {
                            ints[name1] = stoi(name2) / stoi(name3);
                        }
                    break;
                    case 'c':
                        cerr << "char division is not supported" << endl;
                    break;
                    case 'f':
                        if(define_check(name2) && define_check(name3)) {
                            floats[name1] = floats[name2] / floats[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            floats[name1] = floats[name2] / stof(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            floats[name1] = stof(name2) / floats[name3];
                        }
                        else {
                            floats[name1] = stof(name2) / stof(name3);
                        }
                    break;
                    case 'd':
                        if(define_check(name2) && define_check(name3)) {
                            doubles[name1] = doubles[name2] / doubles[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            doubles[name1] = doubles[name2] / stod(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            doubles[name1] = stod(name2) / doubles[name3];
                        }
                        else {
                            doubles[name1] = stod(name2) / stod(name3);
                        }
                    break;
                    case 'l':
                        if(define_check(name2) && define_check(name3)) {
                            long_longs[name1] = long_longs[name2] / long_longs[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            long_longs[name1] = long_longs[name2] / stoll(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            long_longs[name1] = stoll(name2) / long_longs[name3];
                        }
                        else {
                            long_longs[name1] = stoll(name2) / stoll(name3);
                        }
                    break;
                    default:
                        cerr << "division of " << name2 << " and " << name3 << " is not supported" << endl;
                }
            }
            else if(s == '%') {
                switch (t) {
                    case 'i':
                        if(define_check(name2) && define_check(name3)) {
                            ints[name1] = ints[name2] % ints[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            ints[name1] = ints[name2] % stoi(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            ints[name1] = stoi(name2) % ints[name3];
                        }
                        else {
                            ints[name1] = stoi(name2) % stoi(name3);
                        }
                    break;
                    case 'c':
                        cerr << "char % is not supported" << endl;
                    break;
                    case 'f':
                        cerr << "float % is not supported" << endl;
                    break;
                    case 'd':
                        cerr << "double % is not supported" << endl;
                    break;
                    case 'l':
                        if(define_check(name2) && define_check(name3)) {
                            long_longs[name1] = long_longs[name2] % long_longs[name3];
                        }
                        else if(define_check(name2) && !define_check(name3)) {
                            long_longs[name1] = long_longs[name2] % stoll(name3);
                        }
                        else if(!define_check(name2) && define_check(name3)) {
                            long_longs[name1] = stoll(name2) % long_longs[name3];
                        }
                        else {
                            long_longs[name1] = stoll(name2) % stoll(name3);
                        }
                    break;
                    default:
                        cerr << "sum of " << name2 << " and " << name3 << " is not supported" << endl;
                }
            }
            else {
                cerr << s << "unknown sign" << endl;
            }
        }
public:
    static char find_type(const string &s) {
        if(ints.find(s) != ints.end()) {
            return 'i';
        }
         if(chars.find(s) != chars.end()) {
            return 'c';
        }
        if(floats.find(s) != floats.end()) {
            return 'f';
        }
        if(doubles.find(s) != doubles.end()) {
            return 'd';
        }
         if(long_longs.find(s) != long_longs.end()) {
            return 'l';
        }
        return 'n';

    }
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
                    //special symbols
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
                    case '.':
                    case ',':
                    case ':':
                    case ';':
                    case '!':
                    case '?':
                    case '|':
                    case '&':
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
        else if((tokens[0] == "longlong" || tokens[0] == "i64" || tokens[0] =="ll") && tokens[1] != "[") {
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
                switch(find_type(tokens[1])) {
                    case 'i':
                        cin >> ints[tokens[1]];
                    break;
                    case 'c':
                        cin >> chars[tokens[1]];
                    break;
                    case 'f':
                        cin >> floats[tokens[1]];
                    break;
                    case 'd':
                        cin >> doubles[tokens[1]];
                    break;
                    case 'l':
                        cin >> long_longs[tokens[1]];
                    break;
                    default:
                        cerr << "cannot fin type of " << tokens[1]  << ". Use type before declaring variable"<<endl;
                }
            }
        }
        //assignment
        else if(tokens[1] == "=") {
            if(tokens.size() == 3) {
                switch(find_type(tokens[0])) {
                    case 'i':
                        ints[tokens[0]] = ints[tokens[2]];
                        break;
                    case 'c':
                        chars[tokens[0]] = chars[tokens[2]];
                        break;
                    case 'f':
                        floats[tokens[0]] = floats[tokens[2]];
                        break;
                    case 'd':
                        doubles[tokens[0]] = doubles[tokens[2]];
                    case 'l':
                        long_longs[tokens[0]] = long_longs[tokens[2]];
                    default:
                        cerr << "cannot fin type of " << tokens[0] << " to put it in " << tokens[2] << ". Use type before declaring variable"<<endl;
                }

            }
            else if(tokens.size() == 5) {
                arithmetic_operators(find_type(tokens[0]), tokens[3][0], tokens[0], tokens[2], tokens[4]);

            }

        }
        //for comment
        else if(codeString.substr(0, 2) == "//") {}
            //
        else{
            cerr << "Error in string: " << codeString << " number "<< line_num++ << endl;
            exit(1);
        }
        if(tokens[0] == "nln" || tokens[tokens.size()-1] == "nln") {
            cout << endl;
        }

    }
};


#endif //INTERPRETER_H
