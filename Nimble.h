/* 
 * File:   Nimble.h
 * Author: Daniel Rigby
 *
 * Created on December 26, 2014, 8:53 PM
 */

#ifndef NIMBLE_H
#define	NIMBLE_H

#include "Parser.h"
#include "Variable.h"
#include "NimbleLibrary.h"
#include "NimbleTest.h"
#include "SyntaxTree.h"

//List of Variable types
const string VARIABLE_TYPES[] = {"void", "int", "float", "double", "char"};
const int VARIABLE_TYPES_SIZE = sizeof(VARIABLE_TYPES) / sizeof(*VARIABLE_TYPES);
//Nimble Compiler class
class Nimble 
{
public:
    Nimble();
    ~Nimble();
    //Initialize Variable types for nimble
    void compile(int, char**);
    void initializeVariables();
    void initializeLibraries();
    void initializeSyntax();
    void initializeAssembler();
    void testLibraries();
    void testVariables();
    void test();
    Parser* getParser();
    
private:
    Parser* parser;
    NimbleLibrary* library;
    NimbleTest* nimbleTest;
    
};

#endif	/* NIMBLE_H */

