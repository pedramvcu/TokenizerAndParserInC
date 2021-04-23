#ifndef PARSER_H
#define PARSER_H

#include "Givens.h"
#include "Analyzer.h"
#include "Tokenizer.h"
/*Declaring the methods in the file*/
_Bool parser(struct lexics *someLexics, int numberOfLexics);
int function(enum token *tk,int *current, int *counter);
int header(enum token *tk,int *current, int *counter);
int body(enum token *tk,int *current, int *counter);
int argDecl(enum token *tk,int *current, int *counter);
int statementList(enum token *tk,int *current, int *counter);
int statement(enum token *tk,int *current, int *counter);
int whileLoop(enum token *tk,int *current, int *counter);
int returnn(enum token *tk,int *current, int *counter);
int assignment(enum token *tk,int *current, int *counter);
int expression(enum token *tk,int *current, int *counter);
int term(enum token *tk,int *current, int *counter);

#endif
