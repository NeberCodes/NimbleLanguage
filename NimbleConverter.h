/* 
 * File:   NimbleConverter.h
 * Author: danielrigby
 *
 * Created on February 25, 2015, 3:02 PM
 */

#ifndef NIMBLECONVERTER_H
#define	NIMBLECONVERTER_H

#include "AssemblyFunction.h"
#include "NimbleFunction.h"

/*
 NimbleConverter class holds list of conversion from which nimble types to
 which assembly types (NimbleConversion Class: pointer to nimble function, pointer to assemblyfunction
 Has ability to loop through NimbleSyntaxTree converting them into a list of assembly instructions
 NOTE: add ability for assemblyinstructions to output as an assembly instruction may need to link variables in
 Need iterator to go through syntax tree, maybe NimbleSyntaxTreeIterator.
 Loop through syntaxtree converting nimble function to assembly*/
class NimbleConverter {
public:
    NimbleConverter();
    static void addLink(NimbleFunction*, AssemblyFunction*);
    static AssemblyFunction* getLink(NimbleFunction*);
private:
    static map<NimbleFunction*, AssemblyFunction*> conversionLinks;
};

#endif	/* NIMBLECONVERTER_H */

