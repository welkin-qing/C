#include "stdio.h" 
main() 
{ 
int n,s,j,k,p; 
int a[100],b[100];//�������100�� 
printf("������������"); 
scanf("%d",&n); 
printf("���������֣�"); 
scanf("%d",&s); 
for(k=0;k<n;k++) 
a[k]=k+1; 
for(j=0;j<n-1;j++) 
{ 
p=s%(n-j); 
for(k=0;k<n-p-j;k++)//���±任���� 
b[k]=a[p+k]; 
for(k=n-p-j;k<n-1-j;k++) 
b[k]=a[k-n+p+j]; 
for(k=0;k<n-1;k++) 
a[k]=b[k]; 
for(k=0;k<n-j-1;k++)//��ʾ����ÿ�α仯�������˳�� 
printf("%d,",a[k]); 
printf("\n"); 
} 
printf("�����ʣ�������ǣ�%d\n",a[0]); 
} 