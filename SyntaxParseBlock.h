/* 
 * File:   SyntaxParseBlock.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 5:38 PM
 */

#ifndef SYNTAXPARSEBLOCK_H
#define	SYNTAXPARSEBLOCK_H

#include <string>
#include "SyntaxTree.h"
#include "Parser.h"

using namespace std;

//Parse Block class that handles basic creation of new parsing elements to
//improve efficiency of code
class SyntaxParseBlock 
{
public:
    SyntaxParseBlock();
    ~SyntaxParseBlock();
    void addToTree(ParseNode*);
    void addToCountTree(ParseNode*);
    SyntaxTree* getTree();
    SyntaxTree* getCountTree();
    void addToTreeLeft(NimbleSyntax*, ParseNode*);
    void addToTreeRight(NimbleSyntax*, ParseNode*);
    void addToCountTreeLeft(NimbleSyntax*, ParseNode*);
    void addToCountTreeRight(NimbleSyntax*, ParseNode*);
    NimbleSyntax* newSyntax(int, ParseNode*);
    int getType(ParseNode*);
private:
    ParseBlock* parseBlock;
    SyntaxTree* syntaxTree, *syntaxCountTree;
};

#endif	/* PARSEBLOCK_H */

