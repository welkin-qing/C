#include <stdio.h>

main()
{
  int data[40];
  int digit;
  int i,j,r,k;
  int n;

  for(i=1;i<=40;i++)  /* �������ʼֵ��Ϊ0 */
    data[i]=0;

  data[0]=1;
  data[1]=1;
  digit=1;

  printf("Enter a number what you want to calculus : ");
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
      for(j=1;j<=digit;j++) /* ÿλ�ϵȳ��Ͻ��� digit �����м�λ*/
	data[j]*=i;
      for(j=1;j<=digit;j++)
      {
	  if(data[j]>10)
	  {
	      for(r=1;r<=digit;r++)
	      {
		  if(data[digit]>10)
		    digit++;
		  data[r+1]+=data[r]/10;
		  data[r]=data[r]%10;
	      }
	  }
      }
      printf("%d!=",i);
      for(k=digit;k>0;k--)
	printf("%d",data[k]);
      printf("\n");
  }
  getch();
}




