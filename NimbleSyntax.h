/* 
 * File:   NimbleSyntax.h
 * Author: Daniel Rigby
 *
 * Created on December 27, 2014, 11:02 AM
 */

#ifndef NIMBLESYNTAX_H
#define	NIMBLESYNTAX_H

#include <string>
#include <map>

using namespace std;

extern int DOUBLE_TYPE, FLOAT_TYPE, INT_TYPE, SYMBOL_TYPE;

class NimbleSyntax 
{
public:
    NimbleSyntax();
    NimbleSyntax(string, int);
    NimbleSyntax(double, int);
    NimbleSyntax(float, int);
    NimbleSyntax(int, int);
    NimbleSyntax(char, int);
    ~NimbleSyntax();
    
    NimbleSyntax* getLeft();
    NimbleSyntax* getRight();
    NimbleSyntax* getBranch();
    string getName();
    static int getType(string);
    static string getType(int);
    int getType();
    static void addType(string);
    void setLeft(NimbleSyntax*);
    void setRight(NimbleSyntax*);
    void setBranch(NimbleSyntax*);
    void setName(string);
    void setSymbol(char);
    char getSymbol();
    void setType(int);
    int getNumber();
    float getFloat();
    double getDouble();
    static int types_size;
private:
    char symbol;
    string name;
    float f;
    double d;
    int type, number;//types such as operation, loop, if, class, function declaration
    static map<int, string> types;
    NimbleSyntax* left;
    NimbleSyntax* right;
    NimbleSyntax* branch;
};

void print(NimbleSyntax*);

#endif	/* NIMBLESYNTAX_H */

