//
// Created by Season on 2021/12/27.
//

#ifndef UNTITLED_GLOBAL_H
#define UNTITLED_GLOBAL_H

#endif //UNTITLED_GLOBAL_H

#ifdef UNTITLED_GLOBAL_H
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>
#endif

using std::vector;

namespace tools{
    void split(const std::string& s, std::vector<std::string>& tokens, const std::string& delimiters);
    bool readFile(const std::string fileName,std::vector<std::string>& fileContents);
    bool writeFile(const std::string fileName,std::vector<std::string>& fileContents);
    void convertInteger(const std::string& integerString);
    void convertDecimal(const std::string& fullString);
};