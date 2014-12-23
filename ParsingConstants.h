/* 
 * File:   ParsingConstants.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 11:30 AM
 */

#ifndef PARSINGCONSTANTS_H
#define	PARSINGCONSTANTS_H

//Values representing types of node data
const int INT = 0, DOUBLE = 1, STRING = 2, SYMBOL = 3;

//List of delimiters, operators and symbols to help with parsing
const char DELIMITERS[] = {';'};
const int DELIMITERS_LENGTH = sizeof(DELIMITERS) / sizeof(*DELIMITERS);
const char OPERATORS[] = {'+', '-', '*', '/'};
const int OPERATORS_LENGTH = sizeof(OPERATORS) / sizeof(*OPERATORS);
const char SYMBOLS[] = {'{', '}', '(', ')', '[', ']'};
const int SYMBOLS_LENGTH = sizeof(SYMBOLS) / sizeof(*SYMBOLS);

#endif	/* PARSINGCONSTANTS_H */

