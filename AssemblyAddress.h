/* 
 * File:   AssemblyAddress.h
 * Author: danielrigby
 *
 * Created on December 30, 2014, 4:06 PM
 */

#ifndef ASSEMBLYADDRESS_H
#define	ASSEMBLYADDRESS_H

#include <string>
#include <map>

using namespace std;

//Holds data for assembly instructions whether outright address or variable
class AssemblyAddress 
{
public:
    AssemblyAddress();
    ~AssemblyAddress();
    void setAddress(int);
    void setArgument(int);
    void setVariable(int);
    int getArgument();
    int getAddress();
    int getVariable();
    bool isVariable();
    bool isArgument();
    string toString();
    static int getVariable(string);
    static int addVariable(string);
private:
    static map<int, string> variables;
    static int variables_size;
    int address;
    bool variable;
    bool argument;
};

#endif	/* ASSEMBLYADDRESS_H */

