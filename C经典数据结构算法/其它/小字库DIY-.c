С�ֿ�DIY

����ķ����ǰ��Ӵ��ʮ�������ֿ⣨Լ160kB�ɣ�������Ҫ�õ��ļ�ʮ�����ֵ���ģ��ȡ����������µ�һ��С�ֿ⡣�������ĺô��ǣ�

1,�ռ�Ҫ��С���������������õ���xzku.datֻ��1kB�ֽڣ�������С��160kB�� �ڹ�ҵ��������ʱ���ռ��������ġ� 

2,�����ܣ����˲�֪���ơ�

3,ʵ���ٶȿ졣��Ҫ��fseek����ʡʱ�䣬�����ֳ������ٶȿ���һ��ࡣ 



/*MAKE �����ֿ� MAKE*/

main()
{FILE *zkfp, *zk1fp;
 unsigned char *s[S_NUMBER];
 int len[S_NUMBER], i, j, m;
 int qu, wei, l;
 long offset;
 int a[ZISHU], number = 0, xn;
  s[0] = "����С�ֿ���ʾ���";
  s[1] = "�����õ��ĺ�����ģ��ȡ�����������С�ֿ⣬";
  s[2] = "ʹ��ʱ���ɰ�ԭ�ֿ��׿���";
  s[3] = "Ը���λ������ȶ��";
  s[4] = "��ӭ��������֮����";
  s[5] = "������ϡ�";
 zk1fp = fopen("c:\xzku.dat", "wb");
 zkfp = fopen("c:\hzk16", "rb");
 if (zkfp == NULL) {printf("Can't open the cclib");
		  exit(0);
		  }
 for(i = 0; i < s_number; i++)
	{while(*s[i])
		{
		qu = *(s[i]++)-0xa0; 
		wei = *(s[i]++)-0xa0; 
		l = qu*94+wei; 
		for(j = 0; j < number&&a[j] != l; j++); 
		if(j!=number) 
			continue; 
		a[number++] = l; 
		offset = (94l*(qu-1)+(wei-1))*32l;
		fseek(zkfp, offset, SEEK_SET); 
		for(m = 0;m <32;m++) 
			putc(getc(zkfp), zk1fp);  
		}
	}
 fclose(zkfp); 
 fclose(zk1fp); 
 printf("\nOK!\n");
 } 
 
���������С�ֿ�ĳ�����ʾ�ĳ���ֻҪ�������˼·����������������Ҫ�����á�for(j=0;j < number&&a[j]!=l;j++);�������Ʋ�Ҫ���ظ�����ģ�� �������ڿ������γ����ֳ��ֵ�˳��