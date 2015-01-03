/* 
 * File:   NimbleFunction.h
 * Author: danielrigby
 *
 * Created on December 27, 2014, 10:49 AM
 */

#ifndef NIMBLEFUNCTION_H
#define	NIMBLEFUNCTION_H

#include "SyntaxTree.h"
#include "Variable.h"
#include <list>
#include <string>

using namespace std;

class NimbleFunction {
public:
    NimbleFunction();
    ~NimbleFunction();
    list<Variable> getArguments();
    void addArgument(Variable);
    string getName();
    void setName(string);
    SyntaxTree* getSyntaxTree();
private:
    string name;
    list<Variable> arguments;
    SyntaxTree *syntaxTree;
};

#endif	/* NIMBLEFUNCTION_H */

