/*���ʵ������㷨 
This is a good day today -> sihT si a doog yad yadot */

#include "stdafx.h" 
#include "string.h" 
#include "malloc.h" 

char *fun(char *a);

int main(int argc, char* argv[]) 
{ 
   char *string = "This is a good day today"; 
   char *ll=fun(string); 
   printf("%s",ll); 
   return 0; 
} 
 
char *fun(char *a) 
{ 
   char *ptt = (char *)malloc(strlen(a)); 
   ptt = a; 
   char *ftt = (char *)malloc(strlen(a)); 
   *ftt = '\0'; 
   char step[] = " "; 
   char *token; 
   token = strtok( strdup(a),step); 
/*strtok()�����ַ���s1,���ַ���s1�����ַ���s2�ж���Ķ�������ָ�*/
/*strdup()���ַ���s���Ƶ���������ĵ�Ԫ*/
   while(token != NULL) 
   { 
      strcat(ftt,strrev(token)); /*strrev()���ַ���s���Ƶ���������ĵ�Ԫ*/
      strcat(ftt," "); 
      token = strtok( NULL,step); 
   } 
   *(ftt + strlen(a)-1) = '\0'; 
   return  ftt; 
} 