#include<math.h>
main()
{
	int d[6],m,i,j,m;
	long b[63],flag;
	float c[6],min,x;
        printf("�����뱳����װ������");
        scanf("%d",&m); 
	printf("������������������� ");
	for(i=0;i<6;i++)                   /*��������������*/
		scanf("%f",&c[i]);
	for(i=0,min=-1,d[0]=0;d[0]<2;d[0]++) /*������������ȫ����ϲ�����*/
		for(d[1]=0;d[1]<2;d[1]++)        /*i:��ֵ����min��ϵ�����*/
			for(d[2]=0;d[2]<2;d[2]++)    /*min:��10����С��ֵ*/
				for(d[3]=0;d[3]<2;d[3]++)/*d[]:���ʱ�Ƿ�ȡ�����ı�־*/
					for(d[4]=0;d[4]<2;d[4]++)
						for(d[5]=0;d[5]<2;d[5]++)
						{
							for(flag=0,x=0.,j=5;j>=0;j--)/*flag:��������������ö�Ӧ��һ��ʮ����λ��ʾ*/
							{x+=c[j]*d[j];flag=flag*10+d[j];}/*x:��Ӧ����������ϵĺ�*/
							x=((x-m>0)?x-m:m-x);          /*x:��ϵĺ���10�Ĳ�*/
							if(min<0)
							{
								min=x;          /*�Ե�һ�μ�����Ĳ�min���д���*/
								b[i++]=flag;    /*b[]:��¼����ͬmin��flag������ i:b[]������±�*/
							}
							else if(min-x>1.e-6)/*���µ�min�Ĵ���*/
							{
								min=x;
								b[0]=flag;
								i=1;
							}
							else if(fabs((double)x-min)<1.e-6)/*��ȵ�min�Ĵ���*/
								b[i++]=flag;
						}
						for(m=0;m<i;m++)      /*���ȫ��i����10�Ĳ�ֵ��Ϊmin�����*/
						{
							printf(" 10(+ -)%.2f=",min);
							for(flag=b[m],j=0;flag>0;j++,flag/=10)
								if(flag%10)  /*��b[]�д�ı��flag��ԭΪ�����������*/
									if(flag>1)
										printf("%.2f+",c[j]);
									else
										printf("%.2f\n",c[j]);
						}
}