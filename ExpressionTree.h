/* 
 * File:   ExpressionTree.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 9:12 AM
 */

#ifndef EXPRESSIONTREE_H
#define	EXPRESSIONTREE_H

#include "ExpressionNode.h"

class ExpressionTree {
public:
    ExpressionTree();
    ExpressionTree(ExpressionNode*);
    ~ExpressionTree();
    ExpressionNode* search(ExpressionNode*, int);
    ExpressionNode* search(ExpressionNode*, double);
    ExpressionNode* search(ExpressionNode*, string);
    ExpressionNode* search(ExpressionNode*, char);
    void insertLeft(ExpressionNode*, ExpressionNode*);
    void insertRight(ExpressionNode*, ExpressionNode*);
    void setRoot(ExpressionNode*);
    ExpressionNode* getRoot();
    void printPostfix(ExpressionNode*);
    void printPrefix(ExpressionNode*);
    void printPostfix();
    void printInOrder(ExpressionNode*);
    void printInOrder();
private:
    ExpressionNode* root;

};

#endif	/* EXPRESSIONTREE_H */

