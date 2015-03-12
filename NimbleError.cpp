/* 
 * File:   NimbleError.cpp
 * Author: danielrigby
 * 
 * Created on March 12, 2015, 11:28 AM
 */

#include "NimbleError.h"

string NimbleError::log = "";
NimbleError::NimbleError() 
{
}

NimbleError::NimbleError(string newMessage)
{
    message = newMessage;
    time(&theTime);
    
    char buffer[80];
    struct tm* timeinfo;
    timeinfo = localtime(&theTime);
    
    strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
    std::string str(buffer);
    
    if(NimbleError::log != "")
    {
        NimbleError::log += string(1, '\n') + str;
    }
    else
    {
        NimbleError::log = str;
    }
    cerr<<"Nimble Error: " << message << "\n";
}

NimbleError::~NimbleError() 
{
}

