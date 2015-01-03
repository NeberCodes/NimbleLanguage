/* 
 * File:   ParseTree.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 11:19 AM
 */

#ifndef PARSETREE_H
#define	PARSETREE_H

#include "ParseNode.h"

class ParseTree 
{
public:
    ParseTree();
    ParseTree(ParseNode*);
    ~ParseTree();
    void deleteNode(ParseNode*);
    ParseNode* search(ParseNode*, int);
    ParseNode* search(ParseNode*, double);
    ParseNode* search(ParseNode*, string);
    ParseNode* search(ParseNode*, char);
    void insertLeft(ParseNode*, ParseNode*);
    void insertRight(ParseNode*, ParseNode*);
    void setRoot(ParseNode*);
    ParseNode* getRoot();
    void printPostfix(ParseNode*);
    void printPrefix(ParseNode*);
    void printPostfix();
    void printInOrder(ParseNode*);
    void printInOrder();
private:
    ParseNode* root;
};

#endif	/* PARSETREE_H */

