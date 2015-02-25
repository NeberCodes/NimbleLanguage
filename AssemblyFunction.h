/* 
 * File:   AssemblyFunction.h
 * Author: Daniel Rigby
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

//Assembly function storing the basis of an assembly function
//through a list of parameters and instructions.
class AssemblyFunction 
{
public:
    AssemblyFunction();
    AssemblyFunction(string);
    ~AssemblyFunction();
    list<AssemblyInstruction> getInstructions();
    list<AssemblyInstruction> getParams();
    
    void addInstruction(AssemblyInstruction*);
    void addParam(AssemblyInstruction*);
    
    string getName();
    void setName(string);
    void printInstructions();
private:
    string name;
    list<AssemblyInstruction> instructions;
    list<AssemblyInstruction> params;
};


#endif

