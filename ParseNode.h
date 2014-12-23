/* 
 * File:   ParseNode.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 11:29 AM
 */

#ifndef PARSENODE_H
#define	PARSENODE_H

#include <string>
#include <iostream>
#include "ParsingConstants.h"

using namespace std;



class ParseNode 
{  // A node in an expression tree.

private:
    int type;        // Which type of node is this?
                     //   (Value is NUMBER or OPERATOR.)
    double theDouble;   // The value in a node of type NUMBER.
    int theInt;
    string str;
    char symbol;         // The operator in a node of type OPERATOR.
    ParseNode *left;   // Pointers to subtrees,
    ParseNode *right;  //     in a node of type OPERATOR.
public:
    ParseNode(string);
    ~ParseNode();
    ParseNode(int);
    ParseNode(double);
    ParseNode(char);
    ParseNode* getLeft();
    ParseNode* getRight();
    
    void setLeft(ParseNode*);
    
    void setRight(ParseNode*);
    
    double getDouble();
    int getInt();
    string getString();
    char getSymbol();
    int getType();
    bool isBrace();
 }; // end ExpNode

void print(ParseNode*);

#endif	/* PARSENODE_H */

