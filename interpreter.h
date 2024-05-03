//
// Created by Leokud on 29.04.2024.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>
#include <iostream>
#include <map>
std::map<std::string, int> variables;
inline void var(std::string name, int value)
{
    variables[name] = value;
}
inline void print(std::string arg)
{
    if (variables.find(arg)!=variables.end())
    {
        std::cout << variables[arg];
    }
    else
    {
        std::cout << arg;
    }
}
inline void handle(std::string codeString)
{
    //std::cout << "handle" << std::endl;
    if (codeString.substr(0, 5) == "print")
    // print statement; print x => x
    {
        //std::cout << "printing" << std::endl;
        int len = std::size(codeString);
        std::string arg;
        if(codeString[len-1] == ')')
        {
            arg = codeString.substr(6, len - 7);
            //std::cout << ')' << std::endl;
        }
        else
        {
            arg = codeString.substr(6);
            //std::cout << 'space' << std::endl;
        }
        print(arg);
    }
    else if(codeString.substr(0, 3) == "var")
    {
        std::string args = codeString.substr(4);
        std::string name, value;
        bool isAfter = false;
        for (const char sym: args)
        {
            if (sym=='=')
            {
                isAfter = true;
                continue;
            }
            if (sym == ' ')
            {
                continue;
            }
            if (isAfter)
            {
                value+=sym;
            }
            else
            {
                name+=sym;
            }
        }
        int intval = std::stoi(value);
        var(name, intval);
    }
    else if(codeString.substr(0, 7) == "newline")
    {
        std::cout << "\n";
    }
}

#endif //INTERPRETER_H
