#include <iostream>
using namespace std;
/* ���ύ�Ĵ��뽫��Ƕ�뵽���� */
class Stock
{
	public:
	string symbol;
	string name;
	double previousClosingPrice;
    double currentPrice;
   void set(string s1,string s2)
   {
   	//symbol=new char[strlen(s1)+1];
   	symbol=s1;
   	name=s2;
   }
  double  changePercent()
   {
   return((currentPrice-previousClosingPrice)/previousClosingPrice);
   }
};

int main( ) {
    char s1[10],n1[20];
    cin>>s1>>n1;
    Stock stock;
    stock.set(s1, n1);
    // ����ǰһ�����̼�
    cin>>stock.previousClosingPrice;

    // ���뵱ǰ�ɽ���
    cin>>stock.currentPrice;

    // ��ʾ��Ʊ��Ϣ
    cout<<stock.name<<" price changed: " <<(stock.changePercent() * 100)<<"%";
    return 0;
  }
