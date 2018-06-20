#include <iostream>
using namespace std;
/* 你提交的代码将被嵌入到这里 */
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
    // 输入前一日收盘价
    cin>>stock.previousClosingPrice;

    // 输入当前成交价
    cin>>stock.currentPrice;

    // 显示股票信息
    cout<<stock.name<<" price changed: " <<(stock.changePercent() * 100)<<"%";
    return 0;
  }
