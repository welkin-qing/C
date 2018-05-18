
#define m 100
typedef struct
{
	int stack[m];
  	int top;
}stackstru;

 init(stackstru *s)	/*װ��ջ*/
 {
 	s->top=0;
  	return 1;
 }

 int push(stackstru *s,int x)    /*��ջ����*/
 {
 	if (s->top==m)
     		printf("the stack is overflow!\n");
  	else
  	{
  		s->top=s->top+1;
  		s->stack[s->top]=x;
  	}
 }

 void display(stackstru *s)   /*��ʾջ��������*/
 {
 	if(s->top==0)
     		printf("the stack is empty!\n");
  	else
  	{
  		while(s->top!=0)
 		{
 			printf("%d->",s->stack[s->top]);
   			s->top=s->top-1;
   		}
   	}
 }

 int pop(stackstru *s)	/*��ջ���������ر�ɾ�����Ǹ���¼*/
 {
 	int y;
  	if(s->top==0)
  		printf("the stack is empty!\n");
  	else
  	{
  		y=s->stack[s->top];
  		s->top=s->top-1;
  		return y;
  	}
 }
 
 int gettop(stackstru *s)  /*�õ�ջ����*/
 { 
 	int e;
  	if(s->top==0)
  		return 0;
  	else 
  		e=s->stack[s->top];
  	return e;
 }

 main(stackstru *p)
 {
 	int n,i,k,h,x1,x2,select;
  	printf("create a empty stack!\n");
  	init(p);
  	printf("input a stack length:\n");
  	scanf("%d",&n);
  	for(i=0;i<n;i++)
  	{
  		printf("input a stack value:\n");
   		scanf("%d",&k);
   		push(p,k);
  	}
   	printf("select 1:display()\n");
   	printf("select 2:push()\n");
   	printf("select 3:pop()\n");
   	printf("select 4:gettop()\n");
   	printf("input a your select(1-4):\n");
   	scanf("%d",&select);
   	switch(select)
  	{
  		case 1:
  		{
  			display(p);
	 		break;
	 	}
   		case 2:
   		{
   			printf("input a push a value:\n");
	  		scanf("%d",&h);
	  		push(p,h);
	  		display(p);
	  		break;
	  	}
   		case 3:
   		{
   			x1=pop(p);
	    		printf("x1->%d\n",x1);
	    		display(p);
	    		break;
	    	}
   		case 4:
   		{
   			x2=gettop(p);
			printf("x2->%d",x2);
			break;
		}
	 }
}
