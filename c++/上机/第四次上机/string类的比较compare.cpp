// comparing apples with apples
#include <iostream>
#include <string>
 
int main ()
{
  std::string str1 ("green apple");
  std::string str2 ("red apple");
 
  if (str1.compare(str2) != 0)
    std::cout << str1 << " is not " << str2 <<'\n';
 
  if (str1.compare(6,5,"apple") == 0)
    std::cout << "still, " << str1 << " is an apple\n";
 
  if (str2.compare(str2.size()-5,5,"apple") == 0)
    std::cout << "and " << str2 << " is also an apple\n";
 
  if (str1.compare(6,5,str2,4,5) == 0)
    std::cout << "therefore, both are apples\n";
 
  return 0;
}
 
//string类的比较compare方法包括6个重载函数，函数原型如下：
/*
string (1)
int compare (const string& str) const;
 
substrings (2)
int compare (size_t pos, size_t len, const string& str) const;
int compare (size_t pos, size_t len, const string& str,
             size_t subpos, size_t sublen) const;
 
c-string (3)
int compare (const char* s) const;
int compare (size_t pos, size_t len, const char* s) const;
 
buffer (4)
int compare (size_t pos, size_t len, const char* s, size_t n) const;
*/
