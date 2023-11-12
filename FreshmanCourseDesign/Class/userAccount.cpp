//
// Created by Season on 2021/12/27.
//

#include "userAccount.h"
#include "fileProcess.h"
#include "../global.h"

#include <iostream>

using std::cout;
using std::endl;

userAccount::userAccount() = default;
userAccount::~userAccount() {
    password = "";
}

void userAccount::precisionKeepDeposit(const string& cash){
    //定义lambda函数：将字符串转换为长整型
    enum index {_integer,_decimal};
    auto convertString = [](vector<string> split,const int _index){
        long result = 0;
        constexpr int safeLength = 10;
        if(split[_index].length()>safeLength){
            return (long)0;
        }

        std::reverse_iterator<std::__wrap_iter<char *>> reverse_it;
        for(reverse_it = split[_index].rbegin(); reverse_it != split[_index].rend(); reverse_it++){
            result += (long)(*reverse_it-'0')*std::pow(10,(reverse_it - split[_index].rbegin()));
        }
        return result;
    };
    //将字符串型的整数分割成小数部分和整数部分以保证精度
    vector<string> splited;

    //确定输入的类型，并将类型存储进变量
    if(cash.find(".") != cash.npos) {
        tools::split(cash, splited, ".");
        integer += convertString(splited,_integer);
        decimal += convertString(splited,_decimal);
    }
    else {
        splited.emplace_back(cash);
        integer += convertString(splited,_integer);
    }
    for(auto x: splited){
        cout << x << endl;
    }
    return;
}

bool userAccount::verifyPassword(const string&inputAccount,const string& inputPassword) {

    if(isAccountExist) {
        if (inputAccount == account && inputPassword == password) {
            return true;
        }
    }
    return false;
}

void userAccount::initUserFromAccount(string userid) {
    //对当前用户进行初始化
    fileProcess userInfo;
    userInfo.readUserData(userid);
    isAccountExist=userInfo.checkUserDataVaild();
    account=userInfo.getUserAccount();
    name=userInfo.getUserName();
    password=userInfo.getUserPassword();
    return;
}

string userAccount::getUserBalance() {
    string balance = std::to_string(integer)+"."+std::to_string(decimal);
    return balance;
}