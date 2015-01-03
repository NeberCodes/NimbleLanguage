/* 
 * File:   NimbleTest.h
 * Author: danielrigby
 *
 * Created on December 27, 2014, 11:50 AM
 */

#ifndef NIMBLETEST_H
#define	NIMBLETEST_H

#include "NimbleFunction.h"
#include "AssemblyLibrary.h"
#include "SyntaxParser.h"
#include "AssemblyInstruction.h"
#include "Debug.h"

class NimbleTest 
{
public:
    NimbleTest();
    ~NimbleTest();
    void test();
    void testAssembler();
    void testFunction();
    void testSyntaxTree();
    void testAssemblyInstruction();
private:
    NimbleFunction* nimbleFunction;
    SyntaxTree* syntaxTree;
    SyntaxParser* syntaxParser;
};

#endif	/* NIMBLETEST_H */

