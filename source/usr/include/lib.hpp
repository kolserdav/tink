#include <curl/curl.h>
#include <string>
#ifndef WORKER_H
#define WORKER_H
using namespace std;
/**
        Base class for backend and frontend
*/
class Worker
{   
        public:
                Worker();

                /*
                        Destination file path
                */
                string distPath;

                /*
                        Set destination file path
                */
                virtual void SetDistPath() = 0;

                /*
                        Execute command for some part
                */
                virtual int HandleExecute() = 0;       

        protected:

                /*
                        Prefix of response error
                */
                const string ERROR = "ERROR";

                /*
                        Duration of request
                */
                int duration;

                /*
                        Server url
                */
                string url;

                /*
                        Curl write data handler
                */
                static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

                /*
                        Get data from server
                */
                string GetData();

                /*
                        Send data to server
                */
                int SendData(string data);
                
        private:

                /*
                        Handle response from server
                */
                int HandleResponse(CURLcode res);

                /*
                        Handle request to server
                */
                string HandleRequest(string data);
                
};
#endif // WORKER_H