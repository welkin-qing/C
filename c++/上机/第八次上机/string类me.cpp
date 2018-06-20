#include<iostream>
using namespace std;
class String 
{ 
	public:   
		String(const char *str = NULL);  //  constructor   
		String(const String &other);      //  copy constructor   
		~ String(void);    // destructor  
		String & operator =(char *str);                 
		String & operator =(const String &other);//  重载=运算符  
		int operator==(String &other);  //  重载==运算符  
		int operator==(char *str);  
		void display(); 
	private:  
   		char   *m_data;    //  used for storing the string  int 
   		length; 
};
String::String(const char *str)
{
	s=new char[strlen(str)+1];
	strcpy(s,str);
 } 
String::String(const char &other)
{
	s=new char[strlen(other.s)+1];
	strcpy(s,other.s);
}
String::~String()
{
	if(s) delete []s;
}
String & String::operator=(const String &other)
{
	if(this==&other)  return *this;
	delete s;
	s=new char(strlen(other.S)+1);
	strcpy(s,other.s);
	return *this;
}
int main()
{
	String p1("welkin");
	String p2("meanning");
	p1.print();
	p2.print();
	p2=p1;
	p2.print();
	p1.print();
	return 0;
}
