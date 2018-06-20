#include<iostream>
using namespace std;

class Date
{
	int years,mouths,days;
	public:
		Date(int year,int mouth,int day)
		{
			years=year;
			mouths=mouth;
			days=day;
		}
		void date()
		{
			int sum=0;
 			for(int i=0;i<mouths;i++)
 			{
 				if(i==1) sum+=31;
 				else if(i==2)
 				{
 					if(judge()==1) sum+=29;
 					else sum+=28;
		 		}
		 		if(i==3) sum+=31;
				 if(i==4) sum+=30;
				 if(i==5) sum+=31;
				 if(i==6) sum+=30;
				 if(i==7) sum+=31;
				 if(i==8) sum+=31;
				 if(i==9) sum+=30;
				 if(i==10) sum+=31;
				 if(i==11) sum+=30;
				 if(i==12) sum+=31;
	 }
	 sum+=days;
	 cout<<sum;
		}
		int judge()
		{
			if((years%4==0&&years%100!=0)||(years%400==0))
			return 1;
			else
			return 0;
		}
 }; 
 
 int main()
 {
 	int year,mouth,day;
 	cin>>year>>mouth>>day;
 	Date date1(year,mouth,day);
 	date1.date(); 
  } 

