/*��A,B,C,D,E,���ˣ�ÿ�˶�ͷ�϶�����һ�Ż�ڻ�׵�ֽ�����˶�����ÿ�˶��ܿ������˵ģ����������Լ��ġ����Һڵ����ѣ��׵ĳ�ʵ��
A˵�����ҿ����������˵��ǰ�ֽ��һ���Ǻ�ֽ����
B˵�����ҿ����ĸ��˵Ķ��Ǻ�ֽ����
C˵�����ҿ�����һ���˵��ǰ�ֽ���������Ǻ�ֽ����
D˵�����ҿ����ĸ��˵Ķ��ǰ�ֽ����
EʲôҲû��˵��*/
#include <stdio.h>
main()
{
	int a,b,c,d,e;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				for(d=0;d<=1;d++)
					for(e=0;e<=1;e++)
						if((a&&b+c+d+e==3||!a&&b+c+d+e!=3)
							&&(b&&a+c+d+e==0||!b&&a+c+d+e!=0)
							&&(c&&a+b+d+e==1||!c&&a+b+d+e!=1)
							&&(d&&a+b+c+e==4||!d&&a+b+c+e!=4))
						{
							printf("A is pasted a piece of %s paper on his forehead.\n",a?"white":"black");

							printf("B is pasted a piece of %s paper on his forehead.\n",b?"white":"black");

							printf("C is pasted a piece of %s paper on his forehead.\n",c?"white":"black");

							printf("D is pasted a piece of %s paper on his forehead.\n",d?"white":"black");
								
							printf("E is pasted a piece of %s paper on his forehead.\n",e?"white":"black");
						}
}