#include <iostream>
#include <cstring>
using namespace std;

class my_string {
  char *s;
public:
  my_string(char *str)
  {
	s = new char[strlen(str)+1];
	cout<<"Allocating room for s\n";
	strcpy(s, str);
  }
  ~my_string() { if(s) delete [] s; cout << "Freeing s\n"; }
  void show() { cout << s << "\n"; }
};

void display(my_string ob)
{
  ob.show( );
}

int main()
{
  my_string obj("Hello!");

  display(obj);
  
  obj.show();

  return 0;
}
