#include<iostream>
using namespace std;

/* 请在这里填写答案 */
class Student
{
    int n,s;
public:
    Student(int no,int so):n(no),s(so){count++;}
    Student(Student &t)
    {
        n=t.n+1;
        s=t.s;
        count++;
    }
    static int count;
    void display()
    {
        cout<<n<<" ";
        s==0?cout<<"Fail":cout<<"Pass";
        cout<<endl;
    }
};
int Student::count=0;






int main(){
    const int size=100;
    int i, N, no, score;
    Student *st[size];
    cin>>N;
    for(i=0; i<N; i++){
        cin>>no;
        if(no>0){
            cin>>score;
            st[i]=new Student(no, score);
        }
        else
            st[i]=new Student(*st[i-1]);
    }
    cout<<Student::count<<" Students"<<endl;
    for(i=0;i<N;i++) st[i]->display();
    for(i=0;i<N;i++) delete st[i];
    return 0;
}

