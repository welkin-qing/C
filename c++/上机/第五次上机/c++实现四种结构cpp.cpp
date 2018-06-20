#include <iostream>
#include <cstring>
using namespace std;

class Employee{
	private:
		string name;
		int individualEmpNo;
		int grade;
		static int employeeNo;
	protected:
		float accumPay;
	public:
		static int DAY_PER_MON ;
		static int MON_PER_YEAR;
		Employee(string n,int i,int g);
		~Employee();
		void pay(){
 			cout<<"The pay in the last year: "<<accumPay<<endl<<endl;	
		}
		void promote(int x){
			accumPay +=x;
		}
		void displayStatus(){
			cout<<"Employee"<<employeeNo<<" : "<<endl;
			cout<<"Name : "<<name;
			cout<<" , grade : "<<grade;
			cout<<" , employeeNumber : "<<individualEmpNo<<endl;
		}
}; 
Employee::Employee(string n,int i,int g){
			name = n;
			individualEmpNo = i;
			grade = g;
			//accumPay = a;
			employeeNo ++;
		}
Employee::~Employee(){
	employeeNo--;
}
int Employee::employeeNo = 0;
int Employee::DAY_PER_MON = 30;
int Employee::MON_PER_YEAR = 12;

class Technician : public Employee{
	float hourlyRate;
	int workHours;
	public:
		Technician(string n,int i,int g,float h,int w)
		:Employee(n,i,g){
			hourlyRate = h;
			workHours = w;
		}
		void pay(){
			accumPay = hourlyRate * workHours * DAY_PER_MON * MON_PER_YEAR;
 			cout<<"The pay in the last year: "<<accumPay<<endl<<endl;	
		}
}; 

class Manager : public Employee{
	private:
		float monthlyPay;
	public:
		Manager(string n,int i,int g,float m)
		:Employee(n,i,g){
			monthlyPay = m;
		}
		void pay(){	
			accumPay = monthlyPay*MON_PER_YEAR;
			cout<<"The pay in the last year: "<<accumPay<<endl<<endl;
		}
};

class Salesman :public Employee{
	private:
		float CommRate;
		float sales;
	public:
		Salesman(string n,int i,int g,float c,float s)
		:Employee(n,i,g){
			CommRate = c;
			sales = s;
		}
		void pay(){	
			accumPay = CommRate*sales*MON_PER_YEAR;
			cout<<"The pay in the last year: "<<accumPay<<endl<<endl; 
		}		
};

class Salesmanager :public Employee {
	private:
		float CommRate;
		float sales;
		float monthlyPay;
	public:
    	Salesmanager(string n,int i,int g,float m,float c,float s)
		:Employee(n,i,g){
			CommRate = c;
			sales = s;
			monthlyPay = m;
		}
		
		void pay(){
			cout<<"The pay in the last year: ";
			cout<<(monthlyPay+CommRate*sales)*MON_PER_YEAR<<endl<<endl; 
		}
};

int main(void){
	Technician tech("Vicky",29,2,100,6);
	tech.displayStatus();
	tech.pay();
	
	Manager mana("Emma",18,1,13000);
	mana.displayStatus();
	mana.promote(3000);
	mana.pay();

    Salesman salesman("Lucy",47,3,20,500);
	salesman.displayStatus();
	salesman.pay();
		
	Salesmanager salesmana("Tom",38,2,10000,0.2,9876);
	salesmana.displayStatus();
	salesmana.pay();
	
	return 0;
}

