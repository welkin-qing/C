#include <iostream>
#include <string>
using namespace std;
const int K=2;
const int N=20;
class Student{
  string name;
  Student *welcome[K];
  Student *pair;
  public:
      void init(string &name, Student *a, Student *b) {
        this->name=name; 
        welcome[0]=a;
        welcome[1]=b;
        pair=NULL;
      }
     void printPair();
     void addPair();		
};
void printPair()
{
	
 } 
/* ����������д�� */

int main(){
    Student male[N], female[N];
    int m, f, i, j, a, b;
    string name;
    cin>>m;
    for(i=0;i<m;i++){
      cin>>name>>a>>b;
      male[i].init(name, &female[a], &female[b]);
    }
    cin>>f;
    for(i=0;i<f;i++){
      cin>>name>>a>>b;
      female[i].init(name, &male[a], &male[b]);
    }
    for(i=0;i<m;i++) male[i].addPair();
    for(i=0;i<f;i++) female[i].addPair();
    for(i=0;i<m;i++) male[i].printPair();
    return 0;
}
