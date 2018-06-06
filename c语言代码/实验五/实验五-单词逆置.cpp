#include <stdio.h>
#include <string.h>

#define MAXLENGTH 128

void function(char * start ,char *end)
{
	while(start < end)
	{
		*start += *end;
		*end = *start -*end;
		*start = *start -*end;
		++start;
		--end; 
	} 
} 
int main(void)
{
	char str[]="how are you";
	char result[MAXLENGTH]={0};
	char *p,*start,*end;
	
	p = str + strlen(str) - 1;
	start = end = result; 
	while(p>=str)
	{
		*end++ = *p--;
	//	printf("%c\n",*(end-1)) ;
		if(*p== ' ')
		{
			function(start,end-1);
			start = end+1;
		}
	}
	function(start,end-1);
	printf("%s\n",result);
	
	return 0;
}
