#include "../include/lib.hpp"
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
using namespace std;
void Worker::SetDistPath() {};
int Worker::HandleExecute() { return 0; };

size_t Worker::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int Worker::HandleResponse(CURLcode res)
{
    switch (res) {
        case 6:
            throw runtime_error("Url not valid: " + this->url);
        case 7:
            throw runtime_error("Server not responsed: " + this->url);
        case 52:
            throw runtime_error("Server error: " + this->url);
        default:
            break;
            throw runtime_error("Script end with exit code: " + to_string(res));
    }
    return 0;
}

string Worker::HandleRequest(string dat = "666")
{
    this->url = "http://localhost:3030/";
    string readBuffer;
    string data = "test\ndasdasdasdas23123213123as\ndasd\ndasd\n";
    int length = data.size();
    CURL *curl = curl_easy_init();
    CURLcode res;
    struct curl_slist *list = NULL;
    list = curl_slist_append(list, "user-agent: curl/7.74.0");
    list = curl_slist_append(list, "Content-Type: octet-stream");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, this->WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    char *d;
    curl_easy_setopt(curl, CURLOPT_VERBOSE, d);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, length);
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