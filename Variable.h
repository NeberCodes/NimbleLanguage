/* 
 * File:   Variable.h
 * Author: Daniel Rigby
 *
 * Created on December 26, 2014, 8:33 PM
 */

#ifndef VARIABLE_H
#define	VARIABLE_H

#include <string>
#include <map>
#include <list>

using namespace std;

//Variable store Nimble variables
class Variable 
{
public:
    Variable();
    Variable(string);
    ~Variable();
    void setVariable( string);
    static int addType(string);
    static int getType(string);
    static string getType(int);
    list<int> getTypes();
    string getName();
    void addType(int);
    void setName(string);
private:
    list<int> myTypes;
    string name;
    static int types_size;
    static map<int, string> types;
};

#endif	/* VARIABLE_H */

