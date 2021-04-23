#include <stdio.h>
#include <string.h>

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
int main(void) {
 
char inLine[]="      while {";

char result[]="";
int counter=0;
int i=0;
int len=strlen(inLine);
for(i=0;i<len;i++){
  if(inLine[i]==' '){
    continue;
    }
  else if(inLine[i]==')'){
    printf("lexeme is: %s\n",result);
    result[0]='\0';
    printf("lexeme is: )\n");
    }
  else if(inLine[i]=='('){
    printf("lexeme is: %s\n",result);
    result[0]='\0';
    printf("lexeme is: (\n");
    }
  else if(inLine[i]=='='){
    printf("lexeme is: %s\n",result);
    result[0]='\0';
    printf("lexeme is: =\n");
    }
  else if(inLine[i]=='{'){
    printf("lexeme is: %s\n",result);
    printf("lexeme is: {\n");
    }
  else{
    append(result,inLine[i]);
    if(i==len-1){
      printf("%s\n",result);
    }
    //if(len==i) printf("%s\n",result);
  }
  
}

return 0;
}