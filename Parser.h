/* 
 * File:   Parser.h
 * Author: Daniel Rigby
 *
 * Created on December 23, 2014, 10:23 AM
 */

#ifndef PARSER_H
#define	PARSER_H

#include <string>
#include "ParseTree.h"
#include "ParsingConstants.h"
#include "ParseBlock.h"

using namespace std;

//Parser class handles parsing of a string of code and storing them into a Parse Tree
class Parser 
{
public:
    Parser();
    Parser(string);
    ~Parser();
    void loadData(string);
    ParseBlock* parse();
    ParseBlock* parse(string);
    bool isToken(char);
    bool isType(char, const char[], const int);
private:
    string data;
    ParseBlock* block;
};


#endif	/* PARSER_H */

