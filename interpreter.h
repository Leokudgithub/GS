//
// Created by Leokud on 29.04.2024.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>
#include <iostream>
#include <map>
inline std::map<std::string, int> intVar;
inline void print(std::string arg)
{
    if (intVar.find(arg) != intVar.end())
    {
        std::cout << intVar[arg] << " <- var" << std::endl;
    }
    std::cout << std::stoi(arg) << " <- num" << std::endl;
}
inline void create(std::string key, std::string value)
{
    intVar[key] == std::stoi(value);
}
inline void handle(std::string line)
{
    if(line.substr(0, 5) == "print")
    {
        std::string printArg;
        if(line[std::size(line)-1] == ')')
        {
            //print(123)
            printArg = line.substr(6, std::size(line)-3);
        }
        else
        {
            //print 123
            printArg = line.substr(6, std::size(line)-1);
        }
        print(printArg);
    }
    else if(line.substr(0, 6) == "create")
    {
        std::string createArg;
        if(line[std::size(line)-2 == ')'])
        {
            //create(key=123)
            createArg = line.substr(7, std::size(line)-2);
        }
        else
        {
            //create
            createArg = line.substr(7, std::size(line)-1);
        }
        std::string delimiter = "=";

        size_t pos = createArg.find(delimiter);
        std::string key = createArg.substr(0, pos);
        std::string value = createArg.substr(pos + 1);
        std::cout << key << " " << value << std::endl;
        create(key, value);
    }
    else{
        //exception
        std::cout << line << " <- exception" << std::endl;
    }
}

#endif //INTERPRETER_H
