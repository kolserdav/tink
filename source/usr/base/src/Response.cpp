#include <iostream>
#include <cstdio>
#include <fstream>
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
    string data = this->ReadResult();
    remove(this->distPath.c_str());
    this->SendData(data);
}

string Response::ReadResult()
{
    string data = "";
    string line;
    ifstream f (this->distPath.c_str());
    if (f.is_open())
    {
        while ( getline (f, line) )
        {
          data += line + "\n";
        }
        f.close();
    }
    return data;
}