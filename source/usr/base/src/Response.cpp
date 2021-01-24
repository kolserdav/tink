#include <iostream>
#include "../../include/base.hpp"
using namespace std;
Response::Response()
{
    this->SetDistPath();
}

void Response::SetDistPath() {
    this->distPath =  "/tmp/res_rsp";
}

int Response::HandleExecute() {
    string parCom = " > ";
    string exComStr = "cat /etc/resolv.conf" + parCom + this->distPath;
    system(exComStr.c_str());
    return 0;
}

void Response::Listen() {
    this->HandleExecute();
    string data = this->ReadFile(this->distPath.c_str());
    remove(this->distPath.c_str());
    this->SendData(data);
}

