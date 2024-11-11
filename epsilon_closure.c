#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char state[5][10],closure[5][5][5];
int n;

 void main(){
 FILE *fp=fopen("transitions.txt","r");
 int i,j;
 char trans[5][3];
 printf("enter the number of states ");
 scanf("%d",&n);
 printf("\nenter the states \n");
 for(i=0;i<n;i++){
 scanf("%s",state[i]);
 }

 for(i=0;i<n;i++){
 j=0;
 while(fscanf(fp,"%s%s%s",trans[0],trans[1],trans[2])!=EOF){
 	if(strcmp(trans[1],"e")==0 && strcmp(trans[0],state[i])==0){
 	strcpy(closure[i][j],trans[2]);
 	j++;
 	}
 }rewind(fp);
 }

for(i=0;i<n;i++){
printf("\n%s={ %s ",state[i],state[i]);
print_closure(state[i]);
printf("}");

}printf("\n");
}
 
 

void print_closure(char c_state[5]){
for(int i=0;i<n;i++){
if(strcmp(c_state,state[i])==0){
printf(" %s ",closure[i][0]);
print_closure(closure[i][0]);
}
}

}
