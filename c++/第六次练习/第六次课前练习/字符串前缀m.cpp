#include<iostream>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2){
        int flag=0;
        for(int i=0;i<s1.length();i++){
            if(s1.compare(0,i,s2,0,i)==0){
                flag=i;
            }
        }
        if(flag>0) cout<<"The common prefix is "<<s1.assign(s1,0,flag)<<endl;
        else cout<<"No common prefix\n";
    }
    return 0;
}

