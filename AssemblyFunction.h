/* 
 * File:   NimbleFunction.h
 * Author: danielrigby
 *
 * Created on December 27, 2014, 10:49 AM
 */

#ifndef ASSEMBLYFUNCTION_H
#define	ASSEMBLYFUNCTION_H

#include "AssemblyInstruction.h"

#include <list>
#include <string>
#include <iostream>

using namespace std;

class AssemblyFunction 
{
public:
    AssemblyFunction();
    ~AssemblyFunction();
    list<AssemblyInstruction> getInstructions();
    void addInstruction(AssemblyInstruction*);
    string getName();
    void setName(string);
    void printInstructions();
private:
    string name;
    list<AssemblyInstruction> instructions;
};

#endif

