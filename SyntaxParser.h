/* 
 * File:   SyntaxParser.h
 * Author: Daniel Rigby
 *
 * Created on December 23, 2014, 10:23 AM
 */

#ifndef SYNTAXPARSER_H
#define	SYNTAXPARSER_H

#include <string>
#include "SyntaxTree.h"
#include "ParsingConstants.h"
#include "SyntaxParseBlock.h"

using namespace std;

//Parser class handles parsing of a string of code and storing them into a Parse Tree
class SyntaxParser 
{
public:
    SyntaxParser();
    SyntaxParser(string);
    ~SyntaxParser();
    void loadData(string);
    SyntaxParseBlock* parse();
    SyntaxParseBlock* parse(string);
private:
    string data;
    SyntaxParseBlock *block;
    Parser* parser;
};


#endif	/* PARSER_H */

