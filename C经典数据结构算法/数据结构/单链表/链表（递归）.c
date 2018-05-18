#include 
#include 

struct listNode{ 
int data; 
struct listNode *nextPtr; 
}; 

typedef struct listNode LISTNODE; 
typedef LISTNODE * LISTNODEPTR; 

LISTNODEPTR list(LISTNODEPTR , int); // �˴���ͬ 
void printlist(LISTNODEPTR); 
void freelist(LISTNODEPTR); // ���� 

main() 
{ 
LISTNODEPTR newPtr=NULL; 

int i,a; 
for(i=0;i<3;i++){ 
printf("please enter a number\n"); 
scanf("%d,",&a); 
newPtr = list(newPtr,a); // �˴�ע�� 
} 

printlist(newPtr); 

freelist(newPtr); // �˴� 

return 0; 
} 

LISTNODEPTR list(LISTNODEPTR sPtr, int a) 
{ 
if ( sPtr != NULL ) 
sPtr->nextPtr = list( sPtr->nextPtr, a ); // �ݹ飬�����Ľڵ��ϼ� 
�� 
�ݡ� 
else 
{ 
sPtr =(LISTNODEPTR) malloc(sizeof(LISTNODE)); // ע�⣬�ǽڵ�� 
�ߴ�, 
����ת�� 
sPtr->nextPtr = NULL; 
sPtr->data = a; 
} 
return sPtr; 
} 

void freelist(LISTNODEPTR sPtr ) 
{ 
if ( sPtr != NULL ) 
{ 
freelist( sPtr->nextPtr ); // �ݹ飬 ���ͷź���Ľڵ� 
free( sPtr ); // ���ͷű��ڵ� 
} 
else // 
return ; // �����пɲ�Ҫ 
} 



void printlist(LISTNODEPTR currentPtr) 
{ 
if(currentPtr==NULL) 
printf("The list is empty\n"); 
else 
{ 
printf("This list is :\n"); 

while(currentPtr!=NULL) 
{ 
printf("%d-->",currentPtr->data); 
currentPtr=currentPtr->nextPtr; // ���ﲻһ�� 
} 
printf("NULL\n\n"); 
} 
} 


��ԭ����������£�------------------------- 

> list1.c 
> 
>#include 
>#include 
> 
>struct listNode{ 
> int data; 
> struct listNode *nextPtr; 
>}; 
> 
>typedef struct listNode LISTNODE; 
>typedef LISTNODE * LISTNODEPTR; 
> 
>void list(LISTNODEPTR *, int); 
>void printlist(LISTNODEPTR); 
> 
>main() 
>{ 
> LISTNODEPTR newPtr=NULL; 
> 
> 
> int i,a; 
> for(i=0;i<3;i++){ 
> printf("please enter a number\n"); 
> scanf("%d,",&a); 
> list(&newPtr,a); 
// �˴�������newPtr�ĵ�ַ�� ע�⣡ 

> } 
> 
> printlist(newPtr); 
> 
> free(newPtr); 
// ������ͷŲ�������д��������ֻ�ͷ���newPtrָ���һ���ڵ㡣 
// �������ҵ������β��Ȼ�����ͷţ����ߣ����� printlist��˳���ͷţ� 

// �ĺ���printlist�����ڴ˺������ͷš� 

> 
> return 0; 
>} 
> 
>void list(LISTNODEPTR *sPtr, int a) 
>{ 
> LISTNODEPTR newPtr,currentPtr; 
> 
> newPtr=malloc(sizeof(LISTNODEPTR)); 
// �˴��� LISTNODEPTR ��ָ�����ͣ����ǽṹ���ͣ� 
// malloc����voidָ�룬Ӧ��ǿ��ת�����ͣ��˴���澯��������Ӧ������ 
�� 
// ��̷����ϰ�ߡ� 
> if(newPtr!=NULL){ 
> newPtr->data=a; 
> newPtr->nextPtr=NULL; 
> 
> currentPtr=*sPtr; 
> } 
> if(currentPtr==NULL){ 
// �˴�������ȷ�У���ΪcurrentPtrû�г�ʼ���� 
// ��newPtrһ��ΪNULL���˾估���¾������⡣ 

> newPtr->nextPtr=*sPtr; 
> *sPtr=newPtr;} 
// �ڵ�һ��������ʱ��main���newPtrͨ��sPtr���޸�ָ��˽ڵ㡣 
// �ڵڶ���������ʱ��main���newPtrͨ��sPtr���޸�ָ��˽ڵ㡣 
// �ڵ�����������ʱ��main���newPtrͨ��sPtr���޸�ָ��˽ڵ㡣 
// ���main���newPtrָ����������� 
>} 
> 
> 
> 
>void printlist(LISTNODEPTR currentPtr) 
>{ 
> if(currentPtr==NULL) 
> printf("The list is empty\n"); 
> else{ 
> printf("This list is :\n"); 
> 
> while(currentPtr!=NULL){ 
> printf("%d-->",currentPtr->data); 

// main���newPtrָ��������������ȴ�ӡ�����һ������RE�ڶ������� 

> currentPtr=currentPtr->nextPtr->data; 
// �˾�Ƿ��� ���Ͳ�ͬ�� �п�������ֻѭ��һ�Σ���dataΪ0��RE��һ���� 
�� 

> } 
> printf("NULL\n\n"); 
> } 
>} 
// �����Ƴ��������У���������Ƕ��ǵ������Ӧ�ö����ø��ٵ��ԣ��������� 
�� 
���� 





