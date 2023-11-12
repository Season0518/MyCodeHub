//
// Created by Season on 2021/12/28.
//

#ifndef PROJECT5_FILEPROCESS_H
#define PROJECT5_FILEPROCESS_H
#include <string>
#include <vector>
using std::string;
using std::vector;


class fileProcess {
private:
    bool isUserExist;
    vector<string> Userdata;
    const string inVaild = "inVaild";
    enum key {userAccount,userName,userPassword,userContent};
public:
    bool readUserData(string userid);
    bool checkUserDataVaild();
    bool createUserData();
    string getUserAccount();
    string getUserName();
    string getUserPassword();
};


#endif //PROJECT5_FILEPROCESS_H
