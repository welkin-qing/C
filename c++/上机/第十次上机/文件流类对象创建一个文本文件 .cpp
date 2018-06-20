#include <fstream>
#include <iostream>
using namespace std;

int main() {
	char str[100];
	
	ofstream fout("test.txt");
	ifstream in("test.txt");		// ���������󲢴��ļ�
	

	if(!fout) {
		cout << "Can't open file test.txt\n";
		return 1;
	}
	
	fout << "Learning C++ programming is fun!\n";
	fout.close();
	if(!in.is_open()) {
		// �ж��ļ��Ƿ��
		cout << "Can't open file!\n";
		return 1;
	}
	in.getline(str, 100);
	// ������հ��ַ����ַ�����Ҫʹ��geiline()������

	cout << str << endl;

	in.close();
	return 0;
}

