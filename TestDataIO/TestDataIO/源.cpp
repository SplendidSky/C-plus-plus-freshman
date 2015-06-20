#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
	ifstream data, file;
	char meta_data;
	string input = "";
	data.open("C:\\Users\\Administrator\\Desktop\\Format Data.txt", ios::in);
	if (!data.fail()) {
		streambuf *oldCin = cin.rdbuf();
		cin.rdbuf(data.rdbuf());
		while (cin.get(meta_data))
			input += meta_data;
		input += '\n';
		data.close();
		cin.rdbuf(oldCin);
		string path;
		cin >> path;
		streambuf *oldCout = cout.rdbuf();
		streambuf *filebuf = file.rdbuf();
		cout.rdbuf(filebuf);
		cout << input;
	}
	else
		cout << "数据文件打开失败\n";
	system("pause");
}