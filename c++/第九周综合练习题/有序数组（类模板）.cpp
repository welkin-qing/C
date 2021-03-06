#include <iostream>
using namespace std;

/* ����������д�� */
template <class T>
class MyArray
{
	private:
		T *data;
		int size;
	public:
		MyArray(int size)
		{
			int i;
			this->size=size;
			data=new T[size];
			for(i=0;i<size;i++)
				cin>>data[i];
		}
		void sort()
		{
			int i,j;
			T t;
			for(i=0;i<size-1;i++)
				for(j=i+1;j<size;j++)
					if(data[i]>data[j])
					{
						t=data[i];
						data[i]=data[j];
						data[j]=t;		
					}
		}
		void display()
		{
			int i;
			for(i=0;i<size;i++)
			{
				cout<<data[i];
				if(i+1<size)
					cout<<" ";				
			}

			cout<<endl;
		}
		bool check();
		~MyArray();
};
	

template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}
