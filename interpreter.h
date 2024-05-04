//
// Created by Leokud on 29.04.2024.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>
#include <iostream>
#include <map>
inline int line_num = 0;
inline std::map<std::string, int> variables;
inline void var(std::string name, std::string value)
{
    if (variables.find(value) != variables.end())
    {
        variables[name] = variables[value];
    }
    else
    {
        variables[name] = std::stoi(value);
    }
}
inline void print(std::string arg)
{
    if (variables.find(arg)!=variables.end())
    {
        //print a
        std::cout << variables[arg];
    }
    else
    {
        //print 123
        std::cout << arg;
    }
}
inline void get(std::string arg)
{
    std::cin >> variables[arg];
}
inline void add(std::string var, std::string number)
{
    if (variables.find(number) != variables.end())
    {
        variables[var]+=variables[number];
    }
    else
    {
        variables[var]+=std::stoi(number);
    }
}
inline void mult(std::string var, std::string number)
{
    if (variables.find(number) != variables.end())
    {
        variables[var]*=variables[number];
    }
    else
    {
        variables[var]*=std::stoi(number);
    }
}
inline void sub(std::string var, std::string number)
{
    if (variables.find(number) != variables.end())
    {
        variables[var]-=variables[number];
    }
    else
    {
        variables[var]-=std::stoi(number);
    }
}
inline void div(std::string var, std::string number)
{
    if (variables.find(number) != variables.end())
    {
        variables[var]/=variables[number];
    }
    else
    {
        if(std::stoi(number) == 0)
        {
            std::cout << "ZeroDivisionError" << std::endl;
        }
        else
        {
            variables[var]/=std::stoi(number);
        }
    }
}
inline void handle(std::string codeString, int line)
{
    //std::cout << "handle" << std::endl;
    if (codeString.substr(0, 5) == "print" && codeString.substr(5, 2) != "ln")
        // print statement; print x => x
    {
        //std::cout << "printing" << std::endl;
        unsigned long long const len = std::size(codeString);
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
    else if(codeString.substr(0, 7) == "println")
        //println value
    {
        std::string arg = codeString.substr(8);
        print(arg);
        std::cout << "\n";
    }
    else if (codeString.substr(0, 3) == "get")
        //get value
    {
        std::string arg = codeString.substr(4);
        get(arg);

    }
    else if(codeString.substr(0, 3) == "var")
        //var a = 10
    {
        std::string args = codeString.substr(4);
        std::string name, value;
        bool isAfterEqualSign = false;
        for (const char sym: args)
        {
            if (sym=='=')
            {
                isAfterEqualSign = true;
                continue;
            }
            if (sym == ' ')
            {
                continue;
            }
            if (isAfterEqualSign)
            {
                value+=sym;
            }
            else
            {
                name+=sym;
            }
        }
        var(name, value);
    }
    else if(codeString.substr(0, 7) == "newline" || codeString.substr(0, 3) == "nln")
        //newline
    {
        std::cout << "\n";
    }
    else if(codeString.substr(0, 3) == "add")
        //add a+5
    {
        std::string args = codeString.substr(4);
        std::string name, value;
        bool isAfter = false;
        for (const char sym: args)
        {
            if (sym=='+')
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
        add(name, value);
    }
    else if(codeString.substr(0, 4) == "mult")
        //mult value1*value2
    {
        std::string args = codeString.substr(5);
        std::string name, value;
        bool isAfter = false;
        for (const char sym: args)
        {
            if (sym=='*')
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
        mult(name, value);
    }
    else if(codeString.substr(0, 3) == "sub")
        //sub value1-value2
    {
        {
            std::string args = codeString.substr(4);
            std::string name, value;
            bool isAfter = false;
            for (const char sym: args)
            {
                if (sym=='-')
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
            sub(name, value);
        }
    }
    else if(codeString.substr(0, 3) == "div")
        //div value1/value2
    {
        std::string args = codeString.substr(4);
        std::string name, value;
        bool isAfter = false;
        for (const char sym: args)
        {
            if (sym=='/')
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
        div(name, value);
    }
    else if(codeString.substr(0, 2) == "//"){}
    else
    //exception
    {
        std::cerr << line+1 << " line exception" << std::endl;
    }
}

#endif //INTERPRETER_H
