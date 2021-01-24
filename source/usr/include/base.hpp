#include "./lib.hpp"

#ifndef RESPONSE_H
#define RESPONSE_H

class Response: protected Worker
{
    public:
        Response();

        /*
            Execute file logic
        */
        void Listen();
    protected:
        // Abstract methods of base class call Worker

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

};

#endif