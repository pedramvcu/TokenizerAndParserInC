
/*Pedram Maleki CMSC 403 Assignment 4

This file is a  recursive-descent parser and will check a given 
array of lexemes and tokesn to see if they are valid
according to the given EBNF Grammar
*/

#include <stdio.h>
#include <string.h>
#include <regex.h>
#include "Parser.h"
/*These are in the Givens file which is included
but the compiler was giving errors*/


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


/*This is the start symbol in the grammar
/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int function(enum token *tk,int *current, int *counter){
  int h=header(tk,current,counter);
  int b=body(tk,current,counter);
  //printf("body:  %d\n",b);
  if(h==1 && b==1) return 1;
  else return 0;
  
}



/***********************************************************/
/************The Logic used in the header*******************/
/************function is the same for all*******************/
/************other functions in this class******************/
/***********************************************************/


/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int header(enum token *tk,int *current, int *counter){
	/*We check the first rule of the grammar
	for a header and we continiue*/
if(tk[*current]==VARTYPE){
	/*if the token is what is expected
	we increase the counter and check next*/
  *counter= *counter-1;
  *current= *current+1;
  if(tk[*current]==IDENTIFIER) {
    *counter= *counter-1;
    *current= *current+1;
    if(tk[*current]==LEFT_PARENTHESIS){
      *counter= *counter-1;
      *current= *current+1;
      int result=argDecl(tk, current,counter);
      if(result==0){
        return 0;
      }else{
        if(tk[*current]==RIGHT_PARENTHESIS){
          *counter= *counter-1;
          *current= *current+1;
          return 1;
        }else return 0;
      }

    }else return 0;
  }else return 0;
//if the token is not what is expected we return false
}else return 0;


}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int body(enum token *tk,int *current, int *counter){
if(tk[*current]==LEFT_BRACKET){

  *counter= *counter-1;
  *current= *current+1;
  if(tk[*current]==RIGHT_BRACKET){
    return 1;
  }else{
    int result=statementList(tk, current, counter);
    if(result==1){
    if(tk[*current]==RIGHT_BRACKET){
      *counter= *counter-1;
      *current= *current+1;
      return 1;
    }else return 0;

  }else return 0;

  }
   

}else return 0;
}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int argDecl(enum token *tk,int *current, int *counter){
if(tk[*current]==VARTYPE){
  *counter= *counter-1;
  *current= *current+1;
  if(tk[*current]==IDENTIFIER){
    *counter= *counter-1;
    *current= *current+1;
    while(tk[*current]==COMMA){
      *counter= *counter-1;
      *current= *current+1;
      if(tk[*current]==VARTYPE){
        *counter= *counter-1;
        *current= *current+1;
        if(tk[*current]==IDENTIFIER){
          *counter= *counter-1;
          *current= *current+1;
          continue;

        }else return 0;

      }else return 0;

    }
    return 1;

  }else return 0;

}else if(tk[*current]==RIGHT_PARENTHESIS){
  return 1;

}
else return 0;
}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int statementList(enum token *tk,int *current, int *counter){
if(counter==0){
  return 1;
} else if(statement(tk, current, counter)){
  return statementList(tk, current, counter);
} else return 0;
}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int statement(enum token *tk,int *current, int *counter){
if(whileLoop(tk, current, counter)){
  return 1;
}else if(returnn(tk, current, counter)){
  return 1;
}else if(assignment(tk, current, counter)){
  return 1;
}else if(body(tk, current, counter)){
  return 1;
}else return 0;
}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int whileLoop(enum token *tk,int *current, int *counter){
if(tk[*current]==WHILE_KEYWORD){
  *counter= *counter-1;
  *current= *current+1;
  if(tk[*current]==LEFT_PARENTHESIS){
    *counter= *counter-2;
    *current= *current+2;
    int result=expression(tk, current, counter);
    if(result==1){
      if(tk[*current]==RIGHT_PARENTHESIS){
        *counter= *counter-1;
        *current= *current+1;
        int rs=statement(tk,current,counter);
        if(rs){
          return 1;
        }else return 0;

      }else return 0;

    }else return 0;

  }else return 0;

}else return 0;
}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int returnn(enum token *tk,int *current, int *counter){
if(tk[*current]==RETURN_KEYWORD){
  *counter= *counter-1;
  *current= *current+1;
  int result=expression(tk, current, counter);
  if(result==1){
    if(tk[*current]==EOL){
      return 1;
    }else return 0;

  }else return 0;

}else return 0;
}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int assignment(enum token *tk,int *current, int *counter){
if(tk[*current]==IDENTIFIER){
  *counter= *counter-1;
  *current= *current+1;
  if(tk[*current]==EQUAL){
    *counter= *counter-1;
    *current= *current+1;
    int result=expression(tk, current, counter);
    if(result==1){
      if(tk[*current]==EOL){
        return 1;

      }else return 0;

    }else return 0;

  }else return 0;

}else return 0;
}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int expression(enum token *tk,int *current, int *counter){
if(term(tk, current, counter)){
  *counter= *counter-1;
  *current= *current+1;
  while(tk[*current]==BINOP){
    *counter= *counter-1;
    *current= *current+1;
    int rs=term(tk, current, counter);
    if(rs==1){
      *counter= *counter-1;
      *current= *current+1;
      continue;

    }else{
      return 1;

    }
  }


}else if(tk[*current]==LEFT_PARENTHESIS){
  *counter= *counter-1;
  *current= *current+1;
  int result=expression(tk, current, counter);
  if(result==1){
    if(tk[*current]==RIGHT_PARENTHESIS){
      return 1;
    }else return 0;

  }else return 0;

}
else return 0;

}

/*This function takes an enum array, and two
/*int numbers as input to keep track of the 
/*current and count*/
int term(enum token *tk,int *current, int *counter){
if(tk[*current]==IDENTIFIER){
  return 1;
}else if(tk[*current]==NUMBER){
  return 1;
}else return 0;
}

_Bool parser(struct lexics *someLexics, int numberOfLexics){
int i;
int counter=numberOfLexics;
int current=0;
enum token tokies[numberOfLexics];
/*This for loop will copy all the enum tokens
in the given lexics array and use the build array
to do the parsing for simplicity*/
for(i=0;i<numberOfLexics;i++){
  tokies[i]=someLexics[i].token;
  }
  //storing the result of the call to the start symbol and 
  //returning the appropriate value
int result=function(tokies, &current, &counter);
	if(result==1)return TRUE;
	else return !TRUE;
}

