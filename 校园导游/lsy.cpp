#define wbt 1
#define wq 1
#include "wbt.cpp"
#include"wq.cpp"
int panduan1(char s[])
{
	if(strlen(s)==1)
	{
		if(strcmp(s,"1")==0||strcmp(s,"2")==0||strcmp(s,"3")==0||strcmp(s,"4")==0||
		strcmp(s,"5")==0||strcmp(s,"6")==0||strcmp(s,"7")==0)
		return 1;
		else return 0;
	}
	else return 0;
}
char panduan2(char s[])
{
	char c;
	c = s[0];
	return c;
}

int main()
{
	int m,n,x;
	char choice[100];
	char c;
	int result[100];
	int len,rn;    //���·�� 
	int ifo;
	int easylen,allen;  //��·�� 
    v=load("1.txt",&nodeArr);
    while((v=load("1.txt",&nodeArr))==-1)
	{
		printf("�����ļ�ʧ�ܣ���ȷ���ļ��Ƿ�����Ҳ���ռ��,");
		if(confirm("�Ƿ����ԣ�"))
			continue;
    }
    while(1)
    {
    	system("color 3F");
		printf("\t\t***************************************************************\n");
        printf("\t\t\t******��ѡ����Ҫʵ�ֵĹ��ܣ���������1~5��******\n");
        printf("\t\t\t*******-----1.�鿴��ͼ-------------------******\n");
        printf("\t\t\t*******-----2.��ѯ�������---------------******\n");
        printf("\t\t\t*******-----3.��ѯ�������ļ�·��-----******\n");
        printf("\t\t\t*******-----4.��ѯ�����������·��-----******\n");
        printf("\t\t\t*******-----5.��ѯ������������·��-----******\n"); 
        printf("\t\t\t*******-----6.���¶����ļ�---------------******\n");
        printf("\t\t\t*******-----7.�˳�-----------------------******\n");
        scanf("%s",choice);
        while(panduan1(choice)==0)
        {
        	printf("ERROR\n");
        	printf("���������룡\n");
        	scanf("%s",choice);
		}
		c = panduan2(choice);
        switch(c)
        {
        	case '1':   //�鿴��ͼ 
        	        system("color 3");
        	 		CLS;
        			printf("\t\t***************************************************************\n");
                    putGraph();
                    printf("\t\t***************************************************************\n");
                    PAU;
                    CLS;
                    break;
        	case '2':   //��ѯ������� 
                    //CLS;
                    system("color F3");
					int n;
                    printf("\t\t\t*******-----�鿴������ܣ������뾰�����(1~16):-----******");
                    while(1)
					{
                        scanf("%d",&n);
                        CLS;
                        if (n>=v|| n<0)
                        {
							printf("\t\t*******-----�������������ֵΪ%d,��СֵΪ0,����������:-----******",v);
                        	//PAU;
                       		continue;
                        }
                        break;
                    }
                    
                    printf("��[%s] \n������:\n\t%s\n\n\n",nodeArr[n].name,nodeArr[n].ifo);
                    PAU;
                    CLS;
            		break;
            case '3':  //��·��bfs
			        printf("\t\t\t*******-----�������������㣺m n -----******\n");
					scanf("%d %d",&m,&n);
					if(m<1||n>16||m==n||m<'A'&&n>'z')
			        {
			        	CLS;
			        	printf("\n\n\n\t\t\t\t*******-----�������!-----******\n\n\n");
						continue;
					}
					BFS(m-1,n-1); 
					PAU;
                    CLS;
            		break;
        	case '4':  //���·�� 
			        //CLS;
					printf("\t\t\t*******-----�������������㣺m n -----******\n\n");
			        scanf("%d %d",&m,&n);
			        if(m<1||n>16||m==n||m<'A'&&n>'z')
			        {
			        	CLS;
			        	printf("\n\n\n\t\t\t\t*******-----�������!-----******\n\n\n");
						continue;
					}
			        len=minDis(nodeArr,v,m-1,n-1,result,&rn);
                    printf("\t\t\t*******-----���·���ǣ�%d-----******\n",len);
                    for(int i=0;i<rn;i++)
                    {
                    	printf("\t%d.%s\n",result[i]+1,nodeArr[result[i]].name);
                    	if(i!=rn-1)
                    		printf("\t   |\n\t   |\n\t   V\n");
					}
                    printf("\n");
                    PAU;
                    CLS;
                    break;
            case '5':  //����·�� dfs
            	    printf("�������������㣺m n\n");
            	    scanf("%d %d",&m,&n);
            	    if(m<1||n>16||m==n||m<'A'&&n>'z')
			        {
			        	CLS;
			        	printf("\n\n\n\t\t\t\t*******-----�������!-----******\n\n\n");
						continue;
					}
            	    DFS(m-1,n-1);
            	    PAU;
                    CLS;
            		break;
            	    
        	case '6':  //���¶��� 
		   			//CLS;
					free(nodeArr);
					v=load("1.txt",&nodeArr);
        			while((v=load("1.txt",&nodeArr))==-1)
					{
						printf("�����ļ�ʧ�ܣ���ȷ���ļ��Ƿ�����Ҳ���ռ��,");
						if(confirm("�Ƿ����ԣ�"))
						continue;
   					}
					printf("����ɹ���\n");
					printf("����%d����Ϣ��",v);
					PAU;
					CLS;
					break;
//			case 7:  //ɾ������ 
//			        printf("������Ҫɾ���ڵ����ţ�");
//					scanf("%d",&ifo);
//					if(ifo<1||ifo>15)
//					{
//						printf("\t�������\n");
//					}
					 
        	case '7':  //�˳� 
			  	//	CLS; 
					if(confirm("�Ƿ��˳���"))
						return 0;
					CLS;
				    break; 	
        }
    }
}





       
