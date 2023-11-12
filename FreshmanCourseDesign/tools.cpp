//
// Created by Season on 2021/12/28.
//

#include "global.h"
#include <fstream>
#include <iostream>


void tools::split(const std::string &s, std::vector<std::string> &tokens, const std::string &delimiters) {
    //初始化快慢指针pos,lastPos
    std::string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    std::string::size_type pos = s.find_first_of(delimiters, lastPos);
    //对数组执行分离操作
    while (std::string::npos != pos || std::string::npos != lastPos) {
        tokens.emplace_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
    return;
}

bool tools::readFile(const std::string fileName, std::vector<std::string> &fileContents) {
    //打开指定的文件流
    std::ifstream filePtr(fileName,std::ios::in);
    //判断文件是否正常打开
    if(!filePtr.is_open()){
        return false;
    }
    //从文件流读取数据
    std::string currentContent;
    while(!filePtr.eof()){
        getline(filePtr,currentContent);
        fileContents.emplace_back(currentContent);
    }
    //关闭文件流
    filePtr.close();
    return true;
}

bool tools::writeFile(const std::string fileName, std::vector<std::string> &fileContents) {
    //打开指定的文件流
    std::ofstream filePtr(fileName,std::ios::out);
    //判断文件文件是否正常打开
    if(!filePtr.is_open()){
        return false;
    }
    //向文件流写入数据
    for(auto const&currentContent:fileContents){
        filePtr << currentContent << std::endl;
    }

    filePtr.close();
    return true;
}

void tools::convertInteger(const std::string &integerString) {


}