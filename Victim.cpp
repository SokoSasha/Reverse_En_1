#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ObString {
public:

#define InitMes Messages.Init()
#define PathS Messages.Path()
#define ShutMes Messages.Shut()
#define MenuMes Messages.Menu()
#define BackMes Messages.Back()
#define TryMes Messages.Try()
#define WrongMes Messages.Wrong()
#define PW Messages.PassWord()
#define OFF (qwerty == Messages.OF())

	void Init() {
		cout << Decode(init_str);
	}

	const string Path() {
		return Decode(path);
	}

	void Shut() {
		cout << Decode(bye) << endl;
	}

	void Menu() {
		cout << Decode(menu);
	}

	void Back() {
		cout << Decode(back) << endl << endl;
	}

	void Try() {
		cout << Decode(trya) << endl << endl;
	}

	void Wrong() {
		cout << Decode(wrong) << endl << endl;
	}

	const string PassWord() {
		return Decode(password);
	}

	const string OF() {
		return Decode(off);
	}

	void Encode(const string str) {
		string enc;
		enc.resize(str.size());
		size_t size = str.size();
		for (size_t i = 0; i < size; i++) {
			enc[i] = str[i] + i;
		}
		cout << enc;
	}
private:
	const string Decode(string dec) {
		string back;
		back.resize(dec.size());
		for (size_t i = 0; i < dec.size(); i++) {
			back[i] = dec[i] - i;
		}
		return back;
	}
	const string init_str = "Pmgdwj2'mw~p~-~pƒ„‰‚†y6‹‡9Š‹€ƒ„„+`aD";
	const string menu = "[2_#Wmu~(os}.x€€x4ƒ‹„z~Œ%wO{?s‰‘šD†’“H™’šš’N¥ž”˜¦¨@’h–Z€´¦²I~b";
	const string path = "C;^Vexnhd<*ÕüþjD0â÷ÿù\x6\b\atëêãëëzkƒƒT€™‹ŸœWž£ ";
	const string bye = "Siwwxntn(my‚z;<=\x1aX‚xw|";
	const string back = "Bben$yu'xj}~ƒ|€s0tzxw€";
	const string trya = "Ts{#elgpv";
	const string wrong = "Wsqqk%vh{|z~q/";
	const string password = "14;9<FF";
	const string off = "0123";
};

ObString Messages;

const string oneNum(void) {
	string number;

	ifstream in(PathS);

	if (in.is_open())
		getline(in, number);
	in.close();

	return number + '\n';
}

const string allNums(void) {
	string number, numbers;

	ifstream in(PathS);

	if (in.is_open()) {
		while (getline(in, number))
			numbers += number + '\n';
	}
	in.close();

	return numbers;
}

bool checkPass(string qwer) {
	return qwer == PW;
}

int main() {
	while (1) {
		InitMes;
		string qwerty;
		cin >> qwerty;
		if (OFF) {
			ShutMes;
			system("pause");
			return 0;
		}
		if (checkPass(qwerty)) {
			int ch = 1;
			while (ch) {
				bool out = 0;
				MenuMes;
				cin >> ch;
				switch (ch)
				{
				case 0: {
					BackMes;
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
					TryMes;
					break;
				}
				}
				if (out) break;
			}
		}
		else WrongMes;
	}

	system("pause");
	return 0;
	
}