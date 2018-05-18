# define null 0
typedef char ElemType;

typedef struct Circular
{
	ElemType data;
	struct LNode *next;
};

setnull(struct Circular **p)
{	
	*p=null;
}
int length (struct Circular **p)
{
	int n=0;
 	struct Circular *q=*p;
 	while (q!=null)
 	{
 		n++;
  		q=q->next;
 	}
 	return(n);
}

ElemType get(struct Circular **p,int i)
{
	int j=1;
	struct Circular *q=*p;
	while (j<i&&q!=null)
 	{
 		q=q->next;
  		j++;
 	}
 	if(q!=null)
   		return(q->data);
 	else
 		printf("position parameter is incorrect!\n");
}

int locate(struct Circular **p,ElemType x)
{
	int n=0;
 	struct Circular *q=*p;
 	while (q!=null&&q->data!=x)
 	{
 		q=q->next;
  		n++;
 	}
 	if(q=null)
 		return(-1);
 	else
 		return(n+1);
}

void insert(struct Circular **p,ElemType x,int i)
{
	int j=1;
 	struct Circular *s,*q;
  	s=(struct Circular *)malloc(sizeof(struct Circular));
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
   		else printf("position parameter is incorrect!\n");
  	}
}

void delete(struct Circular **p,int i)
{
	int j=1;
 	struct Circular *q=*p,*t;
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
    		else printf("position parameter is incorrect!\n");
  	}
   	if(t=null)
     		free(t);
}

void display(struct Circular **p)
{
	struct Circular *q;
 	q=*p;
 	printf("LinkList display: ");
 	if(q==null)
  		printf("LinkList is Null!");
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

main()
{
	struct Circular *head,*q; char e; int i,n; char y; int select,x1,x2,x3,x4,m;
 	head=setnull();
 	printf("���������ݳ���:")��
 	scanf("%d",&n);
 	for(i=1;i<n;i++);
 	{
 		printf("�����ݲ��뵽��ѭ�������У�");
 		scanf("%d",&y);
 		insert(&head,y,i);}
 		display(&head);
 		printf("select 1 �󳤶� length()");
 		printf("select 2 ȡ��� get()" );
 		printf("select 3 ��ֵ���� locate()");
 		printf("select 4 ɾ����� delete()");
 		printf("input your selete: ");
 		scanf("%d",&select);
		switch(select)
		{
			case 1:
			{
				x1=length(&head);
         			printf("���뵥ѭ������ĳ���:",x1);
         			display(&head);
         			break;
         		}
 			case 2:
 			{
 				printf("������Ҫȡ�ý��:");		
         			scanf("%d",&m);
         			x2=get(&head,m);
         			printf(x2);
         			display(&head);
         			break;
         		}
 			case 3:
 			{
 				printf("������Ҫ���ҵ�����:");
         			scanf("%d",&e);
         			x3=locate(&head,e);
         			printf(x3);
         			display(&head);
         			break;
         		}
 			case 4:
 			{
 				printf("������Ҫɾ���Ľ��:");
         			scanf("%d",&m);
         			x4=delete(&head,m);
         			printf(x4);
         			display(&head);
         			break;
         		}		      			
		}
	}
}