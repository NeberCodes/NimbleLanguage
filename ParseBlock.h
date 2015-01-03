/* 
 * File:   ParseBlock.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 5:38 PM
 */

#ifndef PARSEBLOCK_H
#define	PARSEBLOCK_H

#include <string>
#include "ParseTree.h"

using namespace std;

//Parse Block class that handles basic creation of new parsing elements to
//improve efficiency of code
class ParseBlock 
{
public:
    ParseBlock();
    ~ParseBlock();
    
    ParseNode* getNode();
    ParseNode* getCountNode();
    ParseNode* getNewNode();
    ParseNode* getTempNode();
    ParseNode* getTempNodeTwo();
    ParseNode* getCurCountNode();
    ParseTree* getParseTree();
    ParseTree* getCountTree();
    
    void setNode(ParseNode*);
    void setCountNode(ParseNode*);
    void setNewNode(ParseNode*);
    void setTempNode(ParseNode*);
    void setTempNodeTwo(ParseNode*);
    void setCurCountNode(ParseNode*);
    
    bool handleElement(char, string**, int, bool, int&);
private:
    ParseNode* node, *countNode, *newNode, *tempNode, *tempNodeTwo, 
            *curCountNode, *lastNode, *lastCountNode, *signedNode, 
            *signedCountNode, *bottomNode, *bottomCountNode;
    ParseTree* parseTree, *countTree;
    bool isFirst, isNil;
};

bool isNumber(const std::string);
#endif	/* PARSEBLOCK_H */

