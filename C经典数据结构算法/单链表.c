/*������ĸ��ֲ���*/

# define null 0

typedef char ElemType; /* �ַ�������*/

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
};
		
setnull(struct LNode **p);
int length (struct LNode **p);
ElemType get(struct LNode **p,int i);
void insert(struct LNode **p,ElemType x,int i);
int delete(struct LNode **p,int i);
void display(struct LNode **p);

main()
{
	struct LNode *head,*q;  /*���徲̬����*/
	int select,x1,x2,x3,x4;
	int i,n; 
	int m,g;
	char e,y; 
	
 	head=setnull(&head);  /*������������Ϊ�ձ�*/
 	printf("���������ݳ���: ");
 	scanf("%d",&n);
 	for(i=1;i<n;i++);
 	{
 		printf("�����ݲ��뵽��������: ");
 		scanf("%d",&y);
 		insert(&head,y,i);}  /*�������ݵ�����*/
 		display(&head);	 /*��ʾ������������*/
 		
 		printf("select 1 �󳤶� length()\n");
 		printf("select 2 ȡ��� get()\n");
 		printf("select 3 ��ֵ���� locate()\n");
 		printf("select 4 ɾ����� delete()\n");
 		printf("input your select: ");
 		scanf("%d",&select);	
		switch(select)
		{
			case 1:
			{
				x1=length(&head);
				printf("���������ĳ���%d ",x1);
	 			display(&head);
	 		}break;
	 		
	 		case 2:
	 		{
	 			printf("������Ҫȡ�ý��: ");
         			scanf("%d",&m);
         			x2=get(&head,m);
         			printf(x2);
	 			display(&head);
	 		}break;
	 	
 			case 3:
 			{
 				printf("������Ҫ���ҵ�����: ");
         			scanf("%d",&e);
         			x3=locate(&head,e);
         			printf(x3);
	 			display(&head);
	 		}break;
 			
 			case 4:
 			{
 				printf("������Ҫɾ���Ľ��: ");
         			scanf("%d",&g);
         			x4=delete(&head,g);
         			printf(x4);
	 			display(&head);
	 		}break;
		}
	}
}


setnull(struct LNode **p)
{
	*p=null;
}

int length (struct LNode **p)
{
	int n=0;
 	struct LNode *q=*p;
 	while (q!=null)
 	{
 		n++;
  		q=q->next;
 	}
 	return(n);
}

ElemType get(struct LNode **p,int i)
{
	int j=1;
	struct LNode *q=*p;
	while (j<i&&q!=null)
 	{
 		q=q->next;
  		j++;
 	}
 	if(q!=null)
   		return(q->data);
 	else
 		printf("λ�ò�������ȷ!\n");
}

int locate(struct LNode **p,ElemType x)
{
	int n=0;
 	struct LNode *q=*p;
	while (q!=null&&q->data!=x)
 	{
 		q=q->next;
  		n++;
 	}
 	if(q==null)
 		return(-1);
 	else
 		return(n+1);
}

void insert(struct LNode **p,ElemType x,int i)
{
	int j=1;
 	struct LNode *s,*q;
  	s=(struct LNode *)malloc(sizeof(struct LNode));
  	s->data=x;
  	q=*p;
  	if(i==1)
  	{
  		s->next=q;
   		p=s;
  	}
  	else
  	{
  		while(j<i-1&&q->next!=null)
   		{
   			q=q->next;
    			j++;
   		}
   		if(j==i-1)
    		{
    			s->next=q->next;
     			q->next=s;
    		}
   		else 
   			printf("λ�ò�������ȷ!\n");
  	}	
}

int delete(struct LNode **p,int i)
{
	int j=1;
 	struct LNode *q=*p,*t;
 	if(i==1)
  	{
  		t=q;
  		*p=q->next;
  	}
 	else
  	{
  		while(j<i-1&&q->next!=null)
   		{
   			q=q->next;
    			j++;
   		}
    		if(q->next!=null&&j==i-1)
     		{
     			t=q->next;
      			q->next=t->next;
     		}
    		else 
    			printf("λ�ò�������ȷ!\n");
  	}
   	if(t=null)	
   		free(t);
}

void display(struct LNode **p)
{	
	struct LNode *q;
 	q=*p;
 	printf("��������ʾ: ");
 	if(q==null)
  		printf("����Ϊ��!");
 	else if (q->next==null)
       		printf("%c\n",q->data);
      	else
      	{
      		while(q->next!=null)
	    	{
	    		printf("%c->",q->data);
	     		q=q->next;
	    	}
	   	printf("%c",q->data);
	}
 	printf("\n");
}

