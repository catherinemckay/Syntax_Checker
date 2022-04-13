/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 4 - Syntax Checker: File 1 of 5
*@version 1.0
*Main:
 initializes a syntax checker to process/check users file taken
 in by a command line argument
*/

#include "GenStack.h"
#include "DoublyLinkedList.h"
#include "SyntaxChecker.h"

int main(int argc, char const *argv[]) {
    SyntaxChecker *syntaxChecker = new SyntaxChecker();
    syntaxChecker->checkSyntax(argv[1]); // command line param w/ filename
    //syntaxChecker->checkSyntax("file.txt");
    return 0;
}
