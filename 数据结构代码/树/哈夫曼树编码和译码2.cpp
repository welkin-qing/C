#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 2*N-1

typedef struct {
    int weight;
    int parent, Lchild, Rchild;
    char value;
    char data;
} HTNode, HuffmanTree[M+1];
typedef char * Huffmancode[N+1];  //存译码的数组 
typedef struct {  //赞存节点 
    int weight;
    char data;
} Node;

void selecte(HuffmanTree ht, int n, int * s1, int * s2)
{
    int i, flag = 0, min1=0, min2=0;
    for (i = 1; i <= n; i++) {
        if (ht[i].parent == 0) {
            if (flag == 0) {
                min1 = ht[i].weight;
                *s1 = i;
                flag++;
            } else if (flag == 1) {
                min2 = ht[i].weight;
                *s2 = i;
                flag++;
                if (min1 > min2) {
                    min2 = min1;
                    *s2 = *s1;
                    min1 = ht[i].weight;
                    *s1 = i;
                }
            } else {
                if (min2 > ht[i].weight) {
                    if (min1 > ht[i].weight) {
                        min2 = min1;
                        *s2 = *s1;
                        min1 = ht[i].weight;
                        *s1 = i;
                    } else {
                        min2 = ht[i].weight;
                        *s2 = i;
                    }
                }
            }
        }
    }
}

void Creat(HuffmanTree ht, Node w[], int n) {
    int m = 2*n - 1, i, s1, s2;
    for (i = 1;i <= n; i++) {    //初始化 
        ht[i].weight = w[i].weight;
        ht[i].parent = 0;
        ht[i].Lchild = 0;
        ht[i].Rchild = 0;
        ht[i].data = w[i].data;
    }
    for (i = n + 1; i <= m; i++) {    
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].Lchild = 0;
        ht[i].Rchild = 0;
    }
    for (i = n + 1; i <= m; i++) {
        selecte(ht, i-1, &s1, &s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].Lchild = s1;
        ht[i].Rchild = s2;
        ht[s1].parent = i;
        ht[s2].parent = i;
    }
}


void Code(HuffmanTree ht, Huffmancode hc, int n) {   //编码 
    char * ch;
    int start, i, c, p;
    ch = (char *)malloc(n * sizeof(char));
    ch[n - 1] = '\0';
    for (i = 1; i <= n; i++) {
        start = n - 1;  //从n开始编码 
        c = i;
        p = ht[i].parent;
        while (p != 0) {
            --start;
            if (ht[p].Lchild == c)
                ch[start] = '0';
            else
                ch[start] = '1';
            c = p;
            p = ht[p].parent;
        }
        hc[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(hc[i], &ch[start]);
    }
}
//编码输出 
void codingHuffman(char str[], Huffmancode coding, Node a[], int n) {
    int i, j;
    char result[10000];
    result[0] = '\0';
    for (i = 0; i < strlen(str); i++) {
        for (j = 1; j <= n; j++) {
            if (a[j].data == str[i]) {
                strcat(result, coding[j]);
                break;
            }
        }
    }
    printf("%s\n", result);
}
//译码 
void decoding(char str[], HuffmanTree tree, int n) {
    int i, p = 2*n-1, k = 0;
    char result[1000];
    for (i = 0; str[i] != '\0'; i++) {
        if(str[i] == '0') {
            p = tree[p].Lchild;
        } else {
            p = tree[p].Rchild;
        }
        if (tree[p].Lchild == 0)  //用左孩子来判断 
		 {
            result[k++] = tree[p].data;
            p = 2*n-1;  //根的位置 
        }
    }
    result[k] = '\0';
    printf("%s\n", result);
}
//统计字符串权值 
void count(char str[], Node b[], char ch[],int * sum) {
    int  count = 1;  //有效的子叶 
    Node a[56];
    for (int i = 1; i < 56; i++) {
        a[i].data = ch[i];
        a[i].weight = 0;
    }
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == ' ')
            a[1].weight++;
        else if (str[i] == '.')
            a[2].weight++;
        else if (str[i] >= 'a' && str[i] <= 'z')
            a[str[i] - 'a' + 29].weight++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            a[str[i] - 'A' + 3].weight++;
    }
    for (int i = 1; i < 56; i++) {
        if (a[i].weight != 0)
            b[count++] = a[i];
    }
    *sum = count - 1;
}



int main(void)
{
    HuffmanTree h;  //创建哈夫曼树 
    Huffmancode C;   //存编码 
    int i,sum, k = 0, len;
    double average = 0;
    //枚举序列 
    char ch[100] = "0 .ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    Node string[56];
    char str1[205],str2[10000], temp;
    while ((temp = getchar()) != '#')
        str1[k++] = temp;
    str1[k] = '\0';
    //存01编码 
    scanf("%s", str2);
    len =(int)strlen(str1);   //文章长度  
    count(str1,string,ch,&sum);
    Creat(h,string, sum);
    Code(h, C, sum);
    codingHuffman(str1, C,string,sum);
    decoding(str2, h,sum);
    for (i = 1; i <=sum; i++) {
        average += strlen(C[i]) * ((string[i].weight * 1.0) / len);
    }
    printf("%.2f\n", average); //统计平均码长 
    return 0;
}

