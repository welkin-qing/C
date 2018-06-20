// string::find
#include <iostream> 
#include <string> 
using namespace std;
 
int main ()
{
  string str ("There are two needles in this haystack with needles.");
  string str2 ("needle");
 
  // different member versions of find in the same order as above:
  int found = str.find(str2);
  if (found!=-1)
    cout << "'first'needle' found at: " << found << '\n';
 
  found=str.find("needles are small",found+1,6);
  if (found!=-1)
    cout << "second ¡¯needle¡¯ found at: " << found << '\n';
 
  found=str.find("haystack");
  if (found!=-1)
    cout << "¡¯haystack¡¯ also found at: " << found <<'\n';
 
  found=str.find('.');
  if (found!=-1)
    cout << "Period found at: " << found << '\n';
 
  // let¡¯s replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
  cout << str << '\n';
 
  return 0;
}
