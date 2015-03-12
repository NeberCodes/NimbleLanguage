/* 
 * File:   NimbleFunction.cpp
 * Author: Daniel Rigby
 * 
 * Created on December 27, 2014, 10:49 AM
 */

#include "NimbleFunction.h"

NimbleFunction::NimbleFunction()
{
    syntaxTree = new SyntaxTree();
    name = "";
}

NimbleFunction::NimbleFunction(string newName)
{
    syntaxTree = new SyntaxTree();
    name = newName;
}

NimbleFunction::~NimbleFunction()
{
    delete syntaxTree;
}
list<Variable> NimbleFunction::getArguments()
{
    return arguments;
}
string NimbleFunction::getName()
{
    return name;
}
SyntaxTree* NimbleFunction::getSyntaxTree()
{
    return syntaxTree;
}

void NimbleFunction::addArgument(Variable variable)
{
    arguments.push_back(variable);
}
void NimbleFunction::setName(string newName)
{
    name = newName;
}