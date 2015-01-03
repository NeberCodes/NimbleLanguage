/* 
 * File:   SyntaxTree.h
 * Author: danielrigby
 *
 * Created on December 27, 2014, 11:18 AM
 */

#ifndef SYNTAXTREE_H
#define	SYNTAXTREE_H

#include "NimbleSyntax.h"

class SyntaxTree 
{
public:
    SyntaxTree();
    SyntaxTree(NimbleSyntax*);
    ~SyntaxTree();
    void deleteNode(NimbleSyntax*);
    //NimbleSyntax* search(NimbleSyntax*, int);
    //NimbleSyntax* search(NimbleSyntax*, double);
    void insertLeft(NimbleSyntax*, NimbleSyntax*);
    void insertRight(NimbleSyntax*, NimbleSyntax*);
    void setRoot(NimbleSyntax*);
    NimbleSyntax* getRoot();
    void printPostfix(NimbleSyntax*);
    void printPrefix(NimbleSyntax*);
    void printPostfix();
    void printInOrder(NimbleSyntax*);
    void printInOrder();
private:
    NimbleSyntax* root;
};

#endif	/* SYNTAXTREE_H */

