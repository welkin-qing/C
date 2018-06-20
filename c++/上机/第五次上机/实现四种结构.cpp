#include<iostream>
using namespace std;
class Employee{
	private:
		char* name;
		int individualEmpNo;
		int grade;
		float accumPay;
		static int employeeNo;
	public:
		employee();
		~employee();
		void pay;
		void promote(int);
		void displayStatus();
};
