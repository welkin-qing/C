// replacing in a string
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string base="this is a test string.";
    string str2="n example";
    string str3="sample phrase";
    string str4="useful.";
   
    // replace signatures used in the same order as described above:
   
    // Using positions:                 0123456789*123456789*12345
    string str=base;           // "this is a test string."
    str.replace(9,5,str2);          // "this is an example string." (1)
    str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
    str.replace(8,10,"just a");     // "this is just a phrase."     (3)
    str.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
    str.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)
    cout << str << '\n';
   
}
