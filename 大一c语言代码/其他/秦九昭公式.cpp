#include<stdio.h>
int main(void)
{
    int b,i;
    scanf("%d",&b);
    int a[10];
    for(i=0;i<10;i++)  
    scanf("%d",&a[i]);
    float s=a[0];
    for(int n=1;n<=9;n++)
    {
        s=s*b+a[n];
    }
    printf("%.f",s);
 } 
