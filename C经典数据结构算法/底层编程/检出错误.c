����ͷ���c����Դ�������ķ���

����֪���������������ҵ�Դ�����е��﷨�����������󣬲��������������������ܼ��������Ƶ��Ƿ�õ����㷨�Ƿ���ȷ����c����Դ������Թ����У��Ƚ��鷳��һ�ִ����ǳ������ִ�У����ò���ϣ���Ľ������ʹ���㷨��ȷ������£�����ԱҲҪ��ͷ��β�Ķ����������顣�ҳ�����ķ������Դ�һ�������ݿ�ʼ������֪������������򣬲��ѳ����𲽻�С��ֱ���ҳ��������ڲ�����������Ϊֹ�����ַ����󶼲�����Դ�����м�������printf()�����ʵ�֣�ͨ������м������Ϳ��ܰѳ����ԭ���ҳ����������ַ������ڷ������ӣ�ʹ�ò��㡣���Ľ���һ�ֽ���������ļ򵥷�����������ש��������á�

    �������һ���Ŵ���debug(),����ٶ���������֧�����ͣ��ַ��ͣ�����������ַ����������͡�����������ֵ���������������ͣ��Լ��޸�debug()�������ɡ�debug()�������£�

/* function to print ints,chars,and int&char arrays*/
#include<stdio.h>
#include<conio.h>
#define CLEARS 111

void debug(char let,char c_array[],int n_array[],int asize,int num,int opt)
{
    int i;
    switch(opt)
    {
        case 1:
            printf("The value is %d",num);
            break;
        case 2:
            printf("The letter is %c",let);
            break;
        case 3: {
            puts("The number array contains\n");
            for(i=0;i<=asize;++i)
            printf("%d",n_array[i]);
            break;
        }
        case 4:{
            puts("The character array contains\n");
            for(i=0;i<=asize;++i)
            printf("%c",c_array[i]);
            break;
        }
        default:
            puts("\nInvalid option selected!");
            break;
    }
    puts("\tPlease press any key to continue:");
    getch();
}


void main()
{
    int i,j,a[10];
    char ch,b[10];
    for(i=5,j=0;i<15;++i,++j){
        a[j]=j;
        b[j]=j;
    }
    putchar(CLEARS);
    ch='a';
    debug(0,0,0,0,i,1); /*display value of i*/
    debug(ch,0,0,0,0,2);/*display value of ch*/
    debug(0,0,a,10,0,3);/*display value of a*/
    debug(0,b,0,10,0,4);/*display value of b*/
    debug(0,0,0,0,0,7);/*error*/
}

���ڴ˺����ļ���˵����

    debug()�����ṩһ�����Ŵ�����а�������̴�ӡ�����ķ�����˼��ܼ򵥣�����Ҫ��ӡ���������ʹ��ݸ��������ɺ����printf()��佫���ӡ����������getch()�������������ͣ���У�ֱ���������������debug()����������λ���乤���������ݣ�������Ҫ������������йصĲ�������opt��Ҫʹ�õĿ�ѡ�

    ʵ��Ӧ��ʱ����debug()������������ĳ��򣬰Ѵ����ҳ����󣬿��Ժ����׵İ����е�debug()�����������ȥ����������Щ���ú�Ϊ��������debug()���õ�#include�ӳ����г����Ǻ����׵��¡���vi�༭�ڡ�exת����ʽ����ʹ�õ��������滻����g��s)����Щ��Դ������ʹ��printf()�����Ǻ��Ѱ쵽�ġ�

