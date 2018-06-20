//#include <iostream>
//using namespace std;
//
//int main()
//{
  	//cout.setf(ios::showpos);  //+ 
  	//cout.setf(ios::scientific);  //ะกะด 
  /*cout << 1999<< " " << 3.1415926 <<endl;

  cout.setf(ios::uppercase);  //ด๓ะด 
  cout << 1999 << " " << 3.1415926 <<endl;

  cout.setf(ios::fixed);   
  cout <<1999<< " " << 3.1415926 <<endl;*/

//	cout<<"+"<<1999<<" "<<3.1415926<<"e"<<"+000"<<endl;
//	cout<<"+"<<1999<<" "<<3.1415926<<"E"<<"+000"<<endl;
//	cout<<"+"<<1999<<" "<<3.1415926<<" "<<endl;
//  return 0;
//}
/* 
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(void)
{
	cout.setf(ios::showpos | ios::scientific);
	cout<<setw(10)<<47332<<"  "<<setw(20)<<left<<5.21225215565<<endl;
	
	cout.width(10);
	cout<<3.141592657747<<endl;
	cout.setf(ios::uppercase);
	cout<<3.141592657747<<endl;
	return 0;
}*/
#include<iostream>
#include<iomanip> 
using namespace std;

int main()
{
	cout<<setiosflags(ios::showpoint|ios::scientific)
	<< 1999<< " " <<3.1415926<<endl;
	
	cout<<setiosflags(ios::uppercase)
	<< 1999<< " " <<3.1415926<<endl;
	
	cout<<setiosflags(ios::fixed)
	<< 1999<< " " <<3.1415926<<endl; 
}

