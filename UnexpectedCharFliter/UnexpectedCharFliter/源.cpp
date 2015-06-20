#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("C:\\Users\\Administrator\\Desktop\\test data.txt", ios::in);
	streambuf *oldCin = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
	char sou;
	string des = "";
	while (cin.get(sou)) {
		if (sou == ' ' || sou == '\n' || isalnum(sou)) {
			if (sou == ' ' && (des[des.length() - 1] == ' ' || des[des.length() - 1] == '\n'))
				continue;
			des += sou;
		}
	}
	in.close();
	cin.rdbuf(oldCin);
	out.open("C:\\Users\\Administrator\\Desktop\\Format data.txt", ios::out);
	out << des;
}
