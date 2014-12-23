/* 
 * File:   ExpressionNode.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 8:43 AM
 */

#ifndef EXPRESSIONNODE_H
#define	EXPRESSIONNODE_H

#include <string>
#include <iostream>

using namespace std;

const int INT = 0, DOUBLE = 1,   // Values representing two kinds of nodes.
                  STRING = 2, SYMBOL = 3;

class ExpressionNode 
{  // A node in an expression tree.

private:
    int type;        // Which type of node is this?
                     //   (Value is NUMBER or OPERATOR.)
    double theDouble;   // The value in a node of type NUMBER.
    int theInt;
    string str;
    char symbol;         // The operator in a node of type OPERATOR.
    ExpressionNode *left;   // Pointers to subtrees,
    ExpressionNode *right;  //     in a node of type OPERATOR.
public:
    ExpressionNode(string);
    ~ExpressionNode();
    ExpressionNode(int);
    ExpressionNode(double);
    ExpressionNode(char);
    ExpressionNode* getLeft();
    ExpressionNode* getRight();
    
    void setLeft(ExpressionNode*);
    
    void setRight(ExpressionNode*);
    
    double getDouble();
    int getInt();
    string getString();
    char getSymbol();
    int getType();
    bool isBrace();
 }; // end ExpNode

#endif	/* EXPRESSIONNODE_H */

void print(ExpressionNode*);