#define MAXSIZE
typedef int ElemType;
typedef struct
{
	ElemType elem[MAXSIZE];  //˳��������ָ�� 
	int length;   //˳���ĳ��ȼ�Ԫ�ظ��� 
	int listsize;   //��ǰ�����˳���Ĵ洢����
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
  init_seqList(L1);      //����Init_seqList����
  (*L1).length=10;
  for(int j=0;j<(*L1).length;j++)
  {
    (*L1).elem[j]=j;     
  }
}*/
main()
{
	int i,m;
 	printf("���������Ա��ȣ�\n");
 	scanf("%d",&m);
 	
	
}
 
