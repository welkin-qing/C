#include <fstream>
#include <iostream>
using namespace std;

int main() {
	char str[100];
	
	ofstream fout("test.txt");
	ifstream in("test.txt");		// 创建流对象并打开文件
	

	if(!fout) {
		cout << "Can't open file test.txt\n";
		return 1;
	}
	
	fout << "Learning C++ programming is fun!\n";
	fout.close();
	if(!in.is_open()) {
		// 判断文件是否打开
		cout << "Can't open file!\n";
		return 1;
	}
	in.getline(str, 100);
	// 输入带空白字符的字符串需要使用geiline()函数。

	cout << str << endl;

	in.close();
	return 0;
}

