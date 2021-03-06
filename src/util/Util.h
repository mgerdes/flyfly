#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

using namespace std;

enum Severity {
    ERROR, WARNING, INFO
};

class Util {
    public:
        static constexpr double EPSILON = 0.00001;

        static std::string readFile(std::string fileName);

        static void log(Severity type, string error);
};

#endif 
