# include "stdio.h" 
# define M  3 


void main (  ) 

 { 
  float MAT[M][2*M]; 
  float MAT1[M][M]; 
  float t; 
  int i,j,k,l; 

/***********************************************/ 

   /*�Ծ�����г�ʼ��*/ 
  for(i=0;i<M;i++) 
    for(j=0;j<2*M;j++) 
      MAT1[i][j]='\0'; 
  
  for(i=0;i<M;i++) 
     for(j=0;j<2*M;j++) 
     MAT[i][j]='\0'; 

    /*��MAT1���󸳳�ֵ  */ 
  for(i=0;i<M;i++) 
    for (j=0;j<M;j++) 
      scanf("%f",&MAT1[i][j]); 


  /*��ӡĿ�����?*/ 
  printf("ԭ����Ϊ��\n"); 
  for (i=0;i<M;i++) 
    { 
     for (j=0;j<M;j++)   
printf("%5.2f",MAT1[i][j]); 
     printf("\n"); 
     } 

/********************************************/ 

    /*��MAT1���������չ,MAT1������ӵ�λ����M*M���2M*2M����  */ 
  for(i=0;i<M;i++) 
    for(j=0;j<2*M;j++) 
      if (j<M)  MAT[i][j]=MAT1[i][j]; 
     else if (j==M+i)  MAT[i][j]=1; 
   else MAT[i][j]=0; 


    /*��M������б任��ʹ��ǰ�벿�־����Ϊ��λ����  */ 
    /*��벿�־���Ϊ�����������  */ 
  for(i=0;i<M;i++) 
   { 
    /*�Ե�i�н��й�һ��    */ 
     for (j=0;j<2*M;j++) 
     for(k=i+1;k<M;k++) 
MAT[i][j]=MAT[i][j]+MAT[k][j]; 
     t=MAT[i][i]; 
     for(j=i;j<2*M;j++) 
MAT[i][j]=MAT[i][j]/t; 

     /*�Ծ�������б任��ʹ�õ�i ��ֻ��һ��Ԫ�ز�Ϊ�㣬��Ϊ1*/ 
     for(k=0;k<M;k++) 
if(k!=i) 
  { 
   t=MAT[i][k]; 
   for (l=i;l<2*M;l++) 
   MAT[k][l]=MAT[k][l]-MAT[i][l]*t; 
  } 
     } 


 /*����벿�־�����������������MAT2����*/ 
  for(i=0;i<M;i++) 
   { 
  
    for(j=0;j<M;j++) 
      MAT1[i][j]=MAT[i][j+M]; 
    printf("\n"); 
      
   } 


/*********************************************/ 

   /*������������*/ 
   printf("����Ϊ��\n"); 
   for(i=0;i<M;i++) 
   { 
    
     for(j=0;j<M;j++) 
     printf("%5.2f",MAT1[i][j]); 
     printf("\n"); 
   } 

} 