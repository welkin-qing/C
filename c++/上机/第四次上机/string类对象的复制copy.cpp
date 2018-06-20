// string::copy
#include <iostream>
#include <string>
using namespace std;
//int string::copy(char* s, int len, int pos = 0) const º¯ÊýÔ­ÐÍ
int main ()
{
  char ChangAn[20];
  string str ("Xi¡¯an University of Post & Telecommunications");
  int length = str.copy(ChangAn,10,6);
  ChangAn[length]='\0';
  cout << "ChangAn contains: " << ChangAn << '\n';
  return 0;
}
