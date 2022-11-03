#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//A class of hidden string to display
class ObString {
public:

#define InitMes Secret.Init()
#define PathS Secret.Path()
#define ShutMes Secret.Shut()
#define MenuMes Secret.Menu()
#define BackMes Secret.Back()
#define TryMes Secret.Try()
#define WrongMes Secret.Wrong()
#define PW Secret.PassWord()
#define OFF (qwerty == Secret.OF())
#define POZ Secret.Poz()
#define FP1 Secret.FP(1)
#define FP2 Secret.FP(2)
#define FP3 Secret.FP(3)
#define FP4 Secret.FP(4)

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

	const char* Poz() {
		return Decode(poz);
	}

	const string FP(int i) {
		switch (i)
		{
		case 1: {
			return Decode(fp1);
		}
		case 2: {
			return Decode(fp2);
		}
		case 3: {
			return Decode(fp3);
		}
		case 4: {
			return Decode(fp4);
		}
		default:
			break;
		}
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

	const char* Decode(const char* dec) {
		char* back = new char[6];
		for (int i = 0; i <5; i++)
			back[i] = dec[i] - i;
		back[5] = '\0';
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
	const char* poz = "pbwvi";
	const string fp1 = "1234";
	const string fp2 = "aaaa";
	const string fp3 = "qwertyuiop";
	const string fp4 = "password";
};

//Hidden messages
ObString Secret;

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

//Some garbage to distract "tHe HaCkErS"
void VeryUsefullFunc() {
	char haha = '!';
	while (0) {
		haha++;
	}
	if (haha != haha) {
		int gar = 12898123;
		gar--;
		gar *= 2;
		gar = gar << 4;
	}
	float trhn = 792.6163;
	while (trhn != 0) {
		trhn /= 3;
	}
}

int main() {
	while (1) {
		InitMes;
		string qwerty;
		cin >> qwerty;
		if (OFF) {
			ShutMes;
			system(POZ);
			return 0;
		}
		//////////False password check////////////
		if (qwerty == FP1 || qwerty == FP2)
			VeryUsefullFunc();
		/////////////////////////////////////////
		if (checkPass(qwerty)) {
			int ch = 1;
			while (ch) {
				bool out = 0;
				MenuMes;
				////False password check////
				if (qwerty == FP3)
					VeryUsefullFunc();
				////////////////////////////
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
					if (checkPass(qwerty))
						cout << oneNum() << endl;
					else {
						out = 1;
						ch = 1;
					}
					break;
				}
				case 2: {
					if (checkPass(qwerty))
						cout << allNums() << endl;
					else {
						//////False password check/////
						if (qwerty == FP4)
							VeryUsefullFunc();
						///////////////////////////////

						out = 1;
						ch = 1;
					}
					break;
				}
				default: {
					if (checkPass(qwerty))
						TryMes;
					else {
						out = 1;
						ch = 1;
					}
					break;
				}
				}
				if (out) break;
			}
		}
		else WrongMes;
	}

	system(POZ);
	return 0;
	
}