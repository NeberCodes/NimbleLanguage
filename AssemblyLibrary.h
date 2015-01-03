/* 
 * File:   AssemblyLibrary.h
 * Author: Daniel Rigby
 *
 * Created on December 26, 2014, 8:28 PM
 */

#ifndef ASSEMBLYLIBRARY_H
#define	ASSEMBLYLIBRARY_H

#include "AssemblyFunction.h"
#include <string>
#include <list>


using namespace std;

class AssemblyLibrary
{
public:
    AssemblyLibrary();
    AssemblyLibrary(string);
    ~AssemblyLibrary();
    void addFunction(AssemblyFunction*);
    void removeFunction(string);
    AssemblyFunction* findFunction(string);
    string getName();
    void setName(string);
    
private:
    list<AssemblyFunction> functionList;
    string name;
};

#endif	

