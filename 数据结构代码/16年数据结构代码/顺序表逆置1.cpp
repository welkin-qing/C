#define MAXSIZE
typedef int ElemType;
typedef struct
{
	ElemType elem[MAXSIZE];  //顺序表的数组指针 
	int length;   //顺序表的长度即元素个数 
	int listsize;   //当前分配给顺序表的存储容量
 }seqList;
 void init_seqList(seqList *L)
 {
 	L->length=0;
 	for(i=0;i<=m;i++)
 	{
 		L->elem[i]=
	 }
 }
 void  Reverse(seqList * L)
{
		int i, n=L->length;
		ElemType t;
		for(i=1;i<=n/2;i++)
		{
			t=L->elem[i];
			L->elem[i]=L->elem[n-i+1];
			L->elem[n-i+1]=t;
		}
}
/*
main()
{
  seqList* L1=new seqList();
  init_seqList(L1);      //测试Init_seqList函数
  (*L1).length=10;
  for(int j=0;j<(*L1).length;j++)
  {
    (*L1).elem[j]=j;     
  }
}*/
main()
{
	int i,m;
 	printf("请输入线性表长度：\n");
 	scanf("%d",&m);
 	
	
}
 
