#include<iostream>
#include<cstring>
#include<string>
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
  		char   *m_data;    //  used for storing the string  
		int length; 
};
void String::display()
{
	for(int i=0;i<length;i++)
	cout<<m_data[i];
	cout<<endl;
}
String::~ String()
{
	delete m_data;
	length=0;
}
String::String(const char *str )
{
	m_data= new char[strlen(str)+1];
	strcpy(m_data,str);
	length=strlen(str);
}

String::String(const String &other)
{
	m_data= new char[strlen(other.m_data)+1];
	strcpy(m_data,other.m_data);
	length=other.length;
}

String & String::operator = (char *str)
{
	m_data= new char[strlen(str)+1];
	strcpy(m_data,str);
	length=strlen(str);
	return *this;
}

String & String::operator = (const String &other)
{
	m_data= new char[strlen(other.m_data)+1];
	strcpy(m_data,other.m_data);
	length=other.length;
	return *this;
}

int String::operator==(char *str)
{
	if(length==strlen(str))
	{
		for(int i=0;i<length;i++)
		if(m_data[i]!=str[i])
		return 0;
		return 1;
	 } 
	else
	return 0;
}

int String::operator==(String &other)
{
	if(length==other.length)
	{
		for(int i=0;i<length;i++)
		if(m_data[i]!=other.m_data[i])
		return 0;
		return 1;
	 } 
	else
	return 0;
}

int main()
{
	String a("Hello World !");
	String b("Happy !");
	a.display();
	b.display();
	
	if(a==b) cout<<"a，b相等！"<<endl;
	else cout<<"a,b 不等！"<<endl;
	
	a="Perfect !";
	a.display();
	
	a=b;
	a.display(); 
	if(a=="Happy !") cout<<"a和字符串相等！"<<endl;
	else cout<<"a和字符串 不等！"<<endl;
	
}
