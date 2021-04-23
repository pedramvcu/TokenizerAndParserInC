#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Givens.h"
#include "Analyzer.h"
#include "Parser.h"
/*Decalring the methods in the file*/
_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf);
void append(char* result, char inLineChar);
enum token resType(char *result);
void tokes(struct lexics *aLex, int *numLex, char *result, char *lex);


#endif