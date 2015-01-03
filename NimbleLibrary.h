/* 
 * File:   NimbleLibrary.h
 * Author: Daniel Rigby
 *
 * Created on December 26, 2014, 8:28 PM
 */

#ifndef NIMBLELIBRARY_H
#define	NIMBLELIBRARY_H

#include "NimbleFunction.h"
#include <string>
#include <list>


using namespace std;

class NimbleLibrary 
{
public:
    NimbleLibrary();
    NimbleLibrary(string);
    ~NimbleLibrary();
    void addLibrary(NimbleLibrary*);
    void removeLibrary(string);
    NimbleLibrary* findLibrary(string);
    NimbleLibrary* findRLibrary(string);
    void addFunction(NimbleFunction*);
    void removeFunction(string);
    NimbleFunction* findFunction(string);
    NimbleFunction* findRFunction(string);
    void setName(string);
    string getName();
    
private:
    list<NimbleLibrary> libraryList;
    list<NimbleFunction> functionList;
    string name;
};

#endif	/* LIBRARY_H */

