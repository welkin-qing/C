 ���̵�FAT��(�ļ������)����ʱ,������Ͳ��ܴ������϶�ȡ���ݡ� 
����,����������������ȫ��ͬ���ļ������,��DOS�ڶ��ļ�ʱ����ʹ�� 
�ڶ����ļ������,���,�����𻵵Ŀ����Խϵ͡��ڼ������ʾFAT���� 
��ʱ,���õڶ��ŷ������д��һ���ļ������,�����ܳɹ����������� 
���ϵ����ݡ��ļ�������ڴ����еľ���λ�ü������Ӵ��̵Ĺ��ͬ�� 
��ͬ�� 
    �����ṩ�ĳ���,��Turbo C 2.0��д,��Dos6.22,UCDOS 3.1��ͨ���� 
���ճ������ʾ,�ɷ���������һ������ 
    #include [dos.h] 
    main () 
      {int i,j,dh,ch; 
      a: printf ("Select drive/ѡ��������: (0->A/1->B) \n"); 
      scanf(" %d",&ch); 
      if (1       goto a; 
      printf ("Slect disk/ѡ����������:"); 
    printf(" (36->360KB/72->720KB/12->1.2MB/14->1.44MB) \n"); 
      scanf(" %d" ,&dh);/*��ѡ�����������ͽ��д���*/ 
      switch (dh) 
      {case 36:/*����360KB����*/ 
        for (i=1; i<3;i++) 
         {j=j+2 
           absread(ch,1,j,0); 
           abswrite (ch,1,i,0);} 
         break; 
       case 72: /*����720KB����*/ 
         for (i=1; i<4; i++) 
           {j=i+3; 
            absread (ch,1,j,0); 
            abswrite(ch,1,i,0);} 
         break; 
       case 12: /*����1.2MB����*/ 
         for (i=1; i<8; i++) 
            {j=i+7; 
             absread (ch,1,j,0); 
             abswrite (ch,1,i,0); 
            } 
         break; 

       case 14: /*����1.44MB����*/ 
         for (i=1; i<10; i++) 
            { 
             j=i+9; 
             absread (ch,1,j,0); 
             abswrite (ch,1,i,0); 
            } 
         break; 
        } 
        printf ("OK!"); 
      } 