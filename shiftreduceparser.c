#include<stdio.h>
#include<string.h>
int i=0,l=0,j=0,k=0,z=0,c=0;
char input[20],stk[20],action[20],ac[20];
void check();
void main(){
printf("Grammer is: \n E->E+E\nE->E*E\nE->(E)\nE->id");
printf("\n Enter input string: ");
scanf("%s",input);
c=strlen(input);
strcpy(action,"SHIFT->");
printf("\nStack\tInput\tAction\n");
	for(k=0,i=0;j<c;k++,i++,j++){
	if(input[j]=='i' && input[j+1]=='d'){
		stk[i]=input[j];
		stk[i+1]=input[j+1];
		stk[i+2]='\0';
		input[j]=' ';
		input[j+1]=' ';
		printf("$%s\t%s$\t%sid\n",stk,input,action);
		check();
			
		}
		else{
		stk[i]=input[j];
		stk[i+1]='\0';
		input[j]=' ';
		printf("$%s\t%s$\t%sSymbols\n",stk,input,action);
		check();
		}
	}
	if(stk[0]=='E' && stk[1]=='\0'){
	printf("\nACCEPT\n");
	}
	else{
	printf("\nREJECT\n");
	}
	return 0;
}

void check(){
strcpy(ac,"REDUCE TO E");
for(z=0;z<c;z++){
	if(stk[z]=='i' && stk[z+1]=='d'){
		stk[z]='E';
		stk[z+1]='\0';
		printf("$%s\t%s$\t%s\n",stk,input,ac);
		j++;
		}	
	}
for(z=0;z<c;z++){
	if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E'){
		stk[z]='E';
		stk[z+1]='\0';
		stk[z+2]='\0';
		printf("$%s\t%s$\t%s\n",stk,input,ac);
		i=i-2;
		}	
	}
for(z=0;z<c;z++){
	if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E'){
		stk[z]='E';
		stk[z+1]='\0';
		stk[z+2]='\0';
		printf("$%s\t%s$\t%s\n",stk,input,ac);
		i=i-2;
		}	
	}
	
for(z=0;z<c;z++){
	if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
		stk[z]='E';
		stk[z+1]='\0';
		stk[z+2]='\0';
		printf("$%s\t%s$\t%s\n",stk,input,ac);
		i=i-2;
		}	
	}	
}
