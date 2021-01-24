#include "../include/lib.hpp"
#include <cstring>
#include <curl/curl.h>
#include <curl/easy.h>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

void Worker::SetDistPath() {};
int Worker::HandleExecute() { return 0; };

size_t Worker::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


void Worker::HandleResponse(CURLcode res)
{
    if (res != 0)
    {
        this->duration ++;
    }
}

Worker::Worker()
{
    string defUrl = this->ReadFile(this->tmpPath);
    if (defUrl != "")
    {
        this->url = defUrl;
    }
    this->duration = 2;
}

string Worker::HandleRequest(string data = _NO_DATA)
{
    string readBuffer;
    int length = data.size();
    CURL *curl = curl_easy_init();
    CURLcode res;
    struct curl_slist *list = NULL;
    list = curl_slist_append(list, "user-agent: curl/7.74.0");
    list = curl_slist_append(list, "Content-Type: application/octet-stream");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, this->WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, length);
    const char* env = getenv("NODE_ENV");
    if (env) {
        const char* dev = "development";
        if (strcmp(env, dev) == 0)
        {
            cout << env << endl;
            char *d;
            curl_easy_setopt(curl, CURLOPT_VERBOSE, d);
        }
    }
    res = curl_easy_perform(curl);
    curl_slist_free_all(list);
    this->HandleResponse(res);
    curl_easy_cleanup(curl);
    return readBuffer;
}

string Worker::GetData()
{
    return this->HandleRequest();
}

int Worker::SendData(string data)
{
    this->HandleRequest(data);
    return 0;
}

string Worker::ReadFile(const char* path)
{
    string data = "";
    string line;
    ifstream f (path);
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