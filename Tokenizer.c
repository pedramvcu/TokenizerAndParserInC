/*
Pedram Maleki CMSC 403 Assignment 4

This file is a tokenizer that will tokenize the 
input of a file into lexemes and tokens according to 
the enums
*/

#include "Tokenizer.h"
#include <string.h>
//This method will build strings that
//are not charachters
void append(char* result, char inLineChar) {
        int len = strlen(result);
        result[len] = inLineChar;
        result[len+1] = '\0';
}
/*This is a helper method to find what typede
of non charachter token is being read*/
enum token resType(char *result){
      if(!strcmp(result,"while")){
				return WHILE_KEYWORD;								
			}
			else if(!strcmp(result,"return")){
				return RETURN_KEYWORD;
				
			}
			else if(!strcmp(result,"int")){
				return VARTYPE;
			}
			else if(!strcmp(result,"void")){
				return VARTYPE;
			}
			else if(validNumber(result)){
				return NUMBER;
				
			}
			else if(validIdentifier(result)){
				return IDENTIFIER;
				
			}
      else {
		  
		  return EOL;
	  }
}
/*This method is a helper method to check each
character in the file for tokenization*/
void tokes(struct lexics *aLex, int *numLex, char *result, char *lex){
	//checking the type of charachter that is being read and
	//mathing with results
	if(!strcmp(lex, "(")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={LEFT_PARENTHESIS,'('};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={LEFT_PARENTHESIS,'('};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, ")")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={RIGHT_PARENTHESIS,')'};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={RIGHT_PARENTHESIS,')'};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "{")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={LEFT_BRACKET,'{'};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={LEFT_BRACKET,'{'};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
		else if(!strcmp(lex, "}")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={RIGHT_BRACKET,'}'};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={RIGHT_BRACKET,'}'};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "==")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={BINOP,"=="};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={BINOP,"=="};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "=")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={EQUAL,'='};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={EQUAL,'='};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, ",")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={COMMA,','};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={COMMA,','};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, ";")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={EOL,';'};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={EOL,';'};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "+")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={BINOP,'+'};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={BINOP,'+'};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "*")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={BINOP,'*'};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={BINOP,'*'};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "%")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={BINOP,'%'};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={BINOP,'%'};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "!=")){
		if(strcmp(result, "")!=0){      
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;				
						
			struct lexics lp={BINOP,'!='};
			aLex[*numLex]=lp;
			(*numLex)++;
		}
		else{
			
			struct lexics lp={BINOP,'!='};
			aLex[*numLex]=lp;
			(*numLex)++;    
		}    
	}
	
		//checking the type of charachter that is being read and
	//mathing with results
	else if(!strcmp(lex, "") && strcmp(result, "")!=0){
			struct lexics rs={resType(result)};
			strcpy(&rs.lexeme, result);
			aLex[*numLex]=rs;
			(*numLex)++;
			
			}
	else if(!strcmp(result, "") && strcmp(lex, "")!=0){
			
			//printf("resaaault: %s\n",lex);
			}
	
}

_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf){
	//declaring the needed variables here
	char inLine[256];
	char result[] ="";
	char *lex;
	int i =0;
	//using a while loop to read the file one line at a time
	while(fgets(inLine,256,inf) != NULL){
		int len=strlen(inLine);
		//this for loop will check each character in the file for tokens
		for(i=0;i<len;i++){
			if(inLine[i]==' ' || inLine[i]=='\t' || inLine[i]=='\n'){
				lex="";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='('){
				lex="(";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
				
			}
			else if(inLine[i]==')'){
				lex=")";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='{'){
				lex="{";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='}'){
				lex="}";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='='){
				if(inLine[i+1]=='='){
					lex="==";
					tokes(aLex, numLex, result, lex);
					result[0]='\0';
					i++;
				}else{
					lex="=";
					tokes(aLex, numLex, result, lex);
					result[0]='\0';
				}
				
			}
			else if(inLine[i]==','){
				lex=",";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]==';'){
				lex=";";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='+'){
				lex="+";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='*'){
				lex="*";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='%'){
				lex="%";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
			}
			else if(inLine[i]=='!'){
				if(inLine[i+1]=='='){
					lex="!=";
					tokes(aLex, numLex, result, lex);
					result[0]='\0';
				}else{
					//lex="!";
					//tokes(aLex, numLex, result, lex);
					//result[0]='\0';
				}				
			}
			else if(inLine[i]=='\0'){
				
				lex="";
				tokes(aLex, numLex, result, lex);
				result[0]='\0';
				break;
			}
			//this else will build non charachter tokens
			else{
				append(result,inLine[i]);
				if(i==len-1){
					lex="";
					tokes(aLex, numLex, result, lex);
										
				}
			}
			
		}
	}
	
	return TRUE;
}
