/* C��־������Դ����*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

char* IsLegal(char* CheckWord);

char* ErrorMessages[]={ /*������Ϣ�б�*/
			"�޴���",
			"1  ���ַ�ֻ������ĸ���»��ߣ�",
			"2  ��������ֻ������ĸ���»��ߺ����ֹ��ɣ�",
			"3  ����������ʶ�����ã����Թؼ��֣�",
			"4  ����������ʶ�����ã����Ժ�����",
			"�ڴ治����"
};


void main(void)
{
  char *Prompt="C���Ա�־��������Ҫ��������ԭ��:";
  char *TestWord;
  int   i;

  TestWord = (char *)malloc( sizeof(char)*32 ); /*TestWord����û�����*/
  if( !TestWord ) 
    return;

  /*��ʾ������ʾ��Ϣ*/
  puts(Prompt);
  for( i=1 ;i<=4;i++){
    puts( ErrorMessages[i] );
  }
  puts("");

  while(1){
    printf("\n\n������һ����־��(��д��Q�˳�) :");/*��ʾ*/
    scanf("%s",TestWord);                   /*�õ��û�����*/
    if( (toupper)(TestWord[0])=='Q' )
      break;/*ѭ������*/
    printf("\n%s   %s",TestWord,IsLegal(TestWord)); /*�ж���־���ĺϷ���*/
  }

  free( TestWord );
}


/*�˺��������־�������ĺϷ���*/
char* IsLegal(char* CheckWord)
{
  char* KeyWords[]={"auto","break","case","char","continue","const","default",
		   "do","double","else","enum","extern","float","for","goto",
		   "if","int","long","noalias","register","return","short",
		   "signed","sizeof","static","struct","switch","typedef",
		   "union","unsigned","void","volatile","while","defined",
		   "define","undef","include","ifdef","ifndef","endif","line",
		   "error","elif","pragma"};/*C�ؼ����б�*/
  char* Functions[]={"close","creat","eof","fclose","fcloseall","feof","fopen",
			"ferror","fgetchar","fgets","fprintf","fputc","fputchar",
			"fseek","get","putch","putc","printf","open","putchar",
			"puts","read","scanf","abs","acos","asin","math","atan",
			"atan2","atof","atoi","atol","ceil","dos","cosh","ecvt",
			"exp","fabs","floor","fmod","frexp","itoa","labs","ldexp",
			"log","log10","modf","pow","rand","sin","sqrt","srand",
			"strtod","strlol","tan","tanh","ultoa","memset","strcpy",
			"struct","strchr","strcmp","calloc","isalnum","isalpha",
			"toascii","tolower","tollpper","exit"};/*C��Ҫ�����б�*/

  char* Others="_";/*'_'Ҳ�������ڹؼ���,�����ǲ��Ƽ���ʹ��!*/
  int WordLength,i;
  char* WordTemp;

  WordTemp = (char*)malloc( 32 *sizeof(char ) );
  if( !WordTemp ) return ErrorMessages[5];

  WordLength=strlen(CheckWord);

  /*����־������ԭ��1*/
  if((isalpha(CheckWord[0])==0)&&(CheckWord[0]!=Others[0]))
	return ErrorMessages[1];
  /*����־������ԭ��2*/
  for(i=0;i<WordLength;i++) 
    if((isalnum(CheckWord[i])==0)&&(CheckWord[i]!=Others[0]))
      return ErrorMessages[2];
  /*����־������ԭ��3*/
  for(i=0;i<44;i++)
  {
    if(!strcmp(CheckWord,KeyWords[i]))
      return ErrorMessages[3];
  }
  i=0;
  for(i=0;i<69;i++) /*����־������ԭ��4*/
  {
    if(!strcmp(CheckWord,Functions[i]))
      return ErrorMessages[4];
  }

  free(WordTemp);
  return ErrorMessages[0];
}