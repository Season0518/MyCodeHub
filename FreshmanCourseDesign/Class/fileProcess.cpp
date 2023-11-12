//
// Created by Season on 2021/12/28.
//

#include "fileProcess.h"
#include "../global.h"


bool fileProcess::readUserData(string userid) {
    const string fileName = "User"+userid+".dat";
    isUserExist = tools::readFile(fileName,Userdata);
    return isUserExist;
}

bool fileProcess::checkUserDataVaild() {
    return isUserExist;
}

string fileProcess::getUserAccount() {
    return isUserExist?Userdata[userAccount]:inVaild;
}

string fileProcess::getUserName() {
    return isUserExist?Userdata[userName]:inVaild;
}

string fileProcess::getUserPassword() {
    return isUserExist?Userdata[userPassword]:inVaild;
}
