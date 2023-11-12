//
// Created by Season on 2021/12/27.
//

#ifndef PROJECT5_USERACCOUNT_H
#define PROJECT5_USERACCOUNT_H
#include <string>
using std::string;

class userAccount {
private:
    bool isLogin{},isAccountExist{};
    string password;
    long integer{},decimal{};

public:
    string account,name;
    explicit userAccount();
    ~userAccount();
    void initUserFromAccount(string account);
    void precisionKeepDeposit(const string& cash);
    bool verifyPassword(const string& inputAccount,const string& inputPassword);
    string getUserBalance(void);
};


#endif //PROJECT5_USERACCOUNT_H
