move(char getone,char putone)
{
printf("%c-->%c\n",getone,putone);
}
void hanoi(int n,char one,char two,char three)
{
if(n==1)move(one,three);
else{
hanio(n-1,one,three,two);    \*��A���n-1������ͨ��C���Ƶ�B��*\
move(one,three);             \*��A��ĵ�n�������Ƶ�C�룬��ӡ����*\
hanoi(n-1,two,one,three);    \*��B���n-1������ͨ��A���Ƶ�C��*\ 
}
}
main()
{
int m;
printf("input the number of diskes:");
scanf("%d",&m);
printf("the step to moving %3d diskes:\n",m);
hanoi(m,'A','B','C');
}
a