/* 
 * File:   AssemblyManager.h
 * Author: danielrigby
 *
 * Created on February 19, 2015, 1:39 PM
 */

#ifndef ASSEMBLYMANAGER_H
#define	ASSEMBLYMANAGER_H

#include "AssemblyLibrary.h"

#include <list>
#include <map>
#include <string>

using namespace std;

//Assembly Manager class handling all assembly libraries and data
class AssemblyManager
{
public:
    AssemblyManager();
    
    list<AssemblyLibrary> getLibraries();
    map<unsigned int, unsigned int> getDataMap();

    void addLibrary(AssemblyLibrary*);
    void addData(unsigned int, unsigned int);


    AssemblyLibrary* findLibrary(string);
    AssemblyFunction* findFunction(string, string);
    AssemblyFunction* findFunction(string);
    unsigned int findData(unsigned int);

private:
    list<AssemblyLibrary> libraries;
    map<unsigned int, unsigned int> dataMap;
};

#endif	/* ASSEMBLYMANAGER_H */

