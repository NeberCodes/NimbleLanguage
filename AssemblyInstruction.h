/* 
 * File:   AssemblyInstruction.h
 * Author: danielrigby
 *
 * Created on December 30, 2014, 4:12 PM
 */

#ifndef ASSEMBLYINSTRUCTION_H
#define	ASSEMBLYINSTRUCTION_H

#include "AssemblyAddress.h"
#include "AssemblyStatement.h"

#include <string>
#include <map>

using namespace std;

const int NOTHING = 0, STATEMENT_INT = 1, STATEMENT_ADDRESS = 2, 
        STATEMENT_STRING = 3, STATEMENT_ALL = 4, STATEMENT_OPTIONAL = 5;

class AssemblyInstruction 
{
public:
    AssemblyInstruction();
    ~AssemblyInstruction();
    void setPrestatement(string);
    void setStatement(int);
    void setStatement(string);
    void setFirstAddress(AssemblyAddress*);
    void setSecondAddress(AssemblyAddress*);
    void setFirstArgument(int);
    void setSecondArgument(int);
    void setFirstSArgument(string);
    void setSecondSArgument(string);
    
    string getPrestatement();
    int getStatement();
    AssemblyAddress* getFirstAddress();
    AssemblyAddress* getSecondAddress();
    int getFirstArgument();
    int getSecondArgument();
    string getFirstSArgument();
    string getSecondSArgument();
    
    static int addStatementType(string, bool, int, int);
    static AssemblyStatement* getStatementType(string);
    static int getStatement(string);
    static AssemblyStatement* getStatementByInt(int);
    static void printStatements();
    void print();
    string toString();
private:
    static map<int, string> statements;
    static map<int, AssemblyStatement*> statementList;
    static int statement_size;
    string prestatement;
    int statement;
    AssemblyAddress* firstAddress, *secondAddress;
    int firstArgument, secondArgument;
    string firstSArgument, secondSArgument;
    
};

#endif	/* ASSEMBLYINSTRUCTION_H */

