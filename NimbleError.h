/* 
 * File:   NimbleError.h
 * Author: danielrigby
 *
 * Created on March 12, 2015, 11:28 AM
 */

#ifndef NIMBLEERROR_H
#define	NIMBLEERROR_H

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class NimbleError {
public:
    NimbleError();
    NimbleError(string);
    ~NimbleError();
private:
    string message;
    time_t theTime;
    static string log;
};

#endif	/* NIMBLEERROR_H */

