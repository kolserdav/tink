#include <curl/curl.h>
#include <string>
#include "./lib.hpp"
#ifndef REQUEST_H
#define REQUEST_H
using namespace std;
class Request: public Worker
{
        public:
                Request();

                /*
                        Curcle of requests
                */
                int Circle();
        protected:

                // Abstract methods of base class

                /*
                        Destination file path
                */
                string distPath;

                /*
                        Set destination file path
                */
                void SetDistPath();

                /*
                        Execute command for some part
                */
                int HandleExecute(); 

        private:

                /*
                        Send get task method
                */
                int Send();

                /*
                        Restart request after duration
                */
                int circle();

                /*
                        Source file which as execute
                */
                string srcPath;

                /*
                        Write response in dist file
                */
                void WriteResponse(string readBuffer);
                
                /*
                        Change source file permissions 
                */
                void ChangePerms();

};
#endif // REQUEST_H

