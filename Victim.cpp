#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define PassWord "13968A@"
#define off "0000"
#define OFF (pass == off)

const string oneNum(void) {
	string number;

	ifstream in("C:\\Sasha\\3 Крс\\5 Семестр\\ТРИПО\\Лаба1\\Victim\\text.txt");

	if (in.is_open())
		getline(in, number);
	in.close();

	return number + '\n';
}

const string allNums(void) {
	string number, numbers;

	ifstream in("C:\\Sasha\\3 Крс\\5 Семестр\\ТРИПО\\Лаба1\\Victim\\text.txt");

	if (in.is_open()) {
		while (getline(in, number))
			numbers += number + '\n';
	}
	in.close();

	return numbers;
}

bool checkPass(string pass) {
	return pass == PassWord;
}

int main() {
	while (1) {
		cout << "Please, enter password to proceed" << endl << ">> ";
		string pass;
		cin >> pass;
		if (OFF) {
			cout << "Shutting down..." << endl << "Goodbye" << endl;
			system("pause");
			return 0;
		}
		if (checkPass(pass)) {
			int ch = 1;
			while (ch) {
				bool out = 0;
				cout << "[1] Show first phone number" << endl << "[2] Show all phone numbers" << endl << "[0] Exit" << endl << ">> ";
				cin >> ch;
				switch (ch)
				{
				case 0: { 
					cout << "Back to password check" << endl << endl;
					out = 1;
					ch = 1;
					break;
				}
				case 1: {
					cout << oneNum() << endl;
					break;
				}
				case 2: {
					cout << allNums() << endl;
					break;
				}
				default: {
					cout << "Try again" << endl << endl;
					break;
				}
				}
				if (out) break;
			}
		}
		else cout << "Wrong password!" << endl << endl << ">> ";
	}

	cout << "Here" << endl;
	system("pause");
	return 0;
	
}