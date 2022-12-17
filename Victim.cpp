#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <winternl.h>
#include <Intrin.h>
using namespace std;

typedef unsigned char* PUCHAR;
#define CRC 742455833
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
#define FileCh Secret.FCH()
#define DeBg Secret.DeBG()
#define VE Secret.VMd()

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

	void OK() {
		cout << Decode(OKe) << endl << endl;
	}

	void FCH() {
		cout << Decode(fileChange) << endl << endl;
	}

	void DeBG() {
		cout << Decode(Debg) << endl;
	}

	void VMd() {
		cout << Decode(VM) << endl;
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
		for (int i = 0; i < 5; i++)
			back[i] = dec[i] - i;
		back[5] = '\0';
		return back;
	}

	const string init_str = "Pmgdwj2'mw~p~-~pƒ„‰‚†y6‹‡9Š‹€ƒ„„+`aD";
	const string menu = "[2_#Wmu~(os}.x€€x4ƒ‹„z~Œ%wO{?s‰‘šD†’“H™’šš’N¥ž”˜¦¨@’h–Z€´¦²I~b";
	const string path = "tfzw2y~{"; //"C;^Vexnhd<*ÕüþjD0â÷ÿù\x6\b\atëêãëëzkƒƒT€™‹ŸœWž£ ";
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
	const string fileChange = "Fjnh$|gz(lrlztss11Uƒˆ…GHI";
	const string OKe = "Ewgu}ynpvp*t-}z1";
	const string Debg = "Suqs$ikij~qp~.";
	const string VM = "Vjtwyfr'mw€t~|||u†3xzŠ|{==a‹”‹‘‹STU";
};

//Hidden messages
ObString Secret;

//Usefull func ¹1
const string oneNum(void) {
	string number;
	ifstream in(PathS);
	__asm {
		__emit 0xeb
		__emit 0xff
		__emit 0xc0

		jmp rt
	}

	if (in.is_open())
		getline(in, number);
	in.close();

	return "\t" + number + '\n';

rt:
	return "123";
}

//Usefull func ¹2
const string allNums(void) {

	string number, numbers;

	ifstream in(PathS);
	__asm {
		__emit 0xeb
		__emit 0xff
		__emit 0xc0

		jmp rt1
	}

	if (in.is_open()) {
		while (getline(in, number))
			numbers += "\t" + number + '\n';
	}
	in.close();

	return numbers;
rt1:
	return "456";
}

//Func to check is password is correct
bool checkPass(string qwer) {
	return qwer == PW;
}
void CPEnd() {}

//Some garbage to distract "tHe HaCkErS"
void VeryUsefulFunc() {
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

//Func to check CRC
unsigned int CRC32_function(unsigned char* buf, unsigned long len)
{
	unsigned long crc_table[256];
	unsigned long crc;
	for (int i = 0; i < 256; i++)
	{
		crc = i;
		for (int j = 0; j < 8; j++)
			crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
		crc_table[i] = crc;
	};
	crc = 0xFFFFFFFFUL;
	while (len--)
		crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
	return crc ^ 0xFFFFFFFFUL;
}

//Resulf of CRC checking
bool CRC32_check() {
	auto len = (PUCHAR)checkPass - (PUCHAR)CPEnd;
	auto thisCRC = CRC32_function((PUCHAR)checkPass, len);

	if (thisCRC == CRC) return false;
	else {
		return true;
	}
}

void Hurt() {
	srand(time(NULL));
	auto x = rand() % 123456,
		y = rand() % 9273837,
		z = rand() % 1827383;
	if (x % 283998 == 3) {
		x /= 2893;
	}
	if (x % 18783 == 1 && y / 17873 == 77) {
		y -= x;
		y *= 3;
	}
	if ((z + y) % x == x - 72873) {
		z = x + y - 17283;
		auto c = rand() % 273123 + z;
	}
}


//Debbuger catcher #1
void DBG1() {
	if (IsDebuggerPresent()) {
		DeBg;
		system(POZ);
		exit(-1);
	}
}

//Debbuger catcher #2
void DBG2() {
	BOOL IsDbgPresent = FALSE;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &IsDbgPresent);
	if (IsDbgPresent)
	{
		DeBg;
		system(POZ);
		exit(-1);
	}
}

//Debbuger catcher #3
WORD GetVersionWord(void) {
	OSVERSIONINFO verInfo = { sizeof(OSVERSIONINFO) };
#pragma warning(suppress : 4996)
	GetVersionEx(&verInfo);
	return MAKEWORD(verInfo.dwMinorVersion, verInfo.dwMajorVersion);
}
BOOL IsWin8OrHigher(void) { return GetVersionWord() >= _WIN32_WINNT_WIN8; }
BOOL IsVistaOrHigher(void) { return GetVersionWord() >= _WIN32_WINNT_VISTA; }

PVOID GetPEB()
{
#ifdef _WIN64
	return (PVOID)__readgsqword(0x0C * sizeof(PVOID));
#else
	return (PVOID)__readfsdword(0x0C * sizeof(PVOID));
#endif
}

PVOID GetPEB64()
{
	PVOID pPeb = 0;
#ifndef _WIN64
	if (IsWin8OrHigher())
	{
		BOOL isWow64 = FALSE;
		typedef BOOL(WINAPI* pfnIsWow64Process)(HANDLE hProcess, PBOOL isWow64);
		pfnIsWow64Process fnIsWow64Process = (pfnIsWow64Process)
			GetProcAddress(GetModuleHandleA("Kernel32.dll"), "IsWow64Process");
		if (fnIsWow64Process(GetCurrentProcess(), &isWow64))
		{
			if (isWow64)
			{
				pPeb = (PVOID)__readfsdword(0x0C * sizeof(PVOID));
				pPeb = (PVOID)((PBYTE)pPeb + 0x1000);
			}
		}
	}
#endif
	return pPeb;
}

//Debbuger catcher #3
#define FLG_HEAP_ENABLE_TAIL_CHECK   0x10
#define FLG_HEAP_ENABLE_FREE_CHECK   0x20
#define FLG_HEAP_VALIDATE_PARAMETERS 0x40
#define NT_GLOBAL_FLAG_DEBUGGED (FLG_HEAP_ENABLE_TAIL_CHECK | FLG_HEAP_ENABLE_FREE_CHECK | FLG_HEAP_VALIDATE_PARAMETERS)

void DBG3()
{
	PVOID pPeb = GetPEB();
	PVOID pPeb64 = GetPEB64();
	DWORD offsetNtGlobalFlag = 0;
#ifdef _WIN64
	offsetNtGlobalFlag = 0xBC;
#else
	offsetNtGlobalFlag = 0x68;
#endif
	DWORD NtGlobalFlag = *(PDWORD)((PBYTE)pPeb + offsetNtGlobalFlag);
	if (NtGlobalFlag & NT_GLOBAL_FLAG_DEBUGGED)
	{
		DeBg;
		system(POZ);
		exit(-1);
	}
	if (pPeb64)
	{
		DWORD NtGlobalFlagWow64 = *(PDWORD)((PBYTE)pPeb64 + 0xBC);
		if (NtGlobalFlagWow64 & NT_GLOBAL_FLAG_DEBUGGED)
		{
			DeBg;
			system(POZ);
			exit(-1);
		}
	}
}

//Debbuger catcher #4
void DBG4() {
	DWORD LocalSerial = 0;
	DWORD Counter = GetTickCount64();
	for (unsigned int i = 0; i < 10; i++)
	{
		LocalSerial ^= 0x12345678;
	}
	Counter = GetTickCount64() - Counter;
	if (Counter >= 0x10) {
		DeBg;
		system(POZ);
		exit(-1);
	}
}

#define DBG DBG1();DBG2();DBG3();DBG4();

//VM detector #1
bool IsVM()
{
	int cpuInfo[4] = {};

	__cpuid(cpuInfo, 1);


	if (!(cpuInfo[2] & (1 << 31)))
		return false;

	const auto queryVendorIdMagic = 0x40000000;
	__cpuid(cpuInfo, queryVendorIdMagic);

	const int vendorIdLength = 13;
	using VendorIdStr = char[vendorIdLength];

	VendorIdStr hyperVendorId = {};

	memcpy(hyperVendorId + 0, &cpuInfo[1], 4);
	memcpy(hyperVendorId + 4, &cpuInfo[2], 4);
	memcpy(hyperVendorId + 8, &cpuInfo[3], 4);
	hyperVendorId[12] = '\0';

	static const VendorIdStr vendors[]{
	"KVMKVMKVM\0\0\0", // KVM 
	//"Microsoft Hv",    // Microsoft Hyper-V or Windows Virtual PC */
	"VMwareVMware",    // VMware 
	"XenVMMXenVMM",    // Xen 
	"prl hyperv  ",    // Parallels
	"VBoxVBoxVBox"     // VirtualBox 
	};

	for (const auto& vendor : vendors)
	{
		if (!memcmp(vendor, hyperVendorId, vendorIdLength))
			return true;
	}

	return false;
}

//VM detector #2
bool IsVMWare()
{
	bool res = true;

	__try {
		__asm {
			push   edx
			push   ecx
			push   ebx

			mov    eax, 'VMXh'
			mov    ebx, 0
			mov    ecx, 10
			mov    edx, 'VX'

			in     eax, dx

			cmp    ebx, 'VMXh'
			setz[res]

			pop    ebx
			pop    ecx
			pop    edx
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		res = false;
	}

	return res;
}

//Virtual PC detector
DWORD __forceinline IsInsideVPC_exceptionFilter(LPEXCEPTION_POINTERS ep)
{
	PCONTEXT ctx = ep->ContextRecord;

	ctx->Ebx = -1;
	ctx->Eip += 4;
	return EXCEPTION_CONTINUE_EXECUTION;
}

bool IsInsideVPC()
{
	bool rc = false;

	__try
	{
		_asm push ebx
		_asm mov  ebx, 0
		_asm mov  eax, 1

		// call VPC 
		_asm __emit 0Fh
		_asm __emit 3Fh
		_asm __emit 07h
		_asm __emit 0Bh

		_asm test ebx, ebx
		_asm setz[rc]
			_asm pop ebx
	}
	__except (IsInsideVPC_exceptionFilter(GetExceptionInformation()))
	{
	}

	return rc;
}

//Virtual environment detector
void VMKiller() {
	if (IsVM() || IsVMWare() || IsInsideVPC()) {
		VE;
		system(POZ);
		exit(-1);
	}
}

//Self-modifing code
BOOL WriteProcessMemoryEx(PVOID pTo, PVOID pFrom, ULONG cb)
{
	DWORD n = 0;
	BOOL  f = WriteProcessMemory(HANDLE(-1), pTo, pFrom, cb, &n);
	if (f)
	{
		if (n != cb)
			return false;

		return true;
	}

	if (GetLastError() != ERROR_NOACCESS)
		return false;

	DWORD dwOldProtect;
	if (!VirtualProtect(pTo, cb, PAGE_WRITECOPY, &dwOldProtect))
		return false;

	f = WriteProcessMemory(HANDLE(-1), pTo, pFrom, cb, &n);
	VirtualProtect(pTo, cb, dwOldProtect, &dwOldProtect);

	if (f)
	{
		if (n != cb)
		{
			VirtualProtect(pTo, cb, dwOldProtect, &dwOldProtect);
			return false;
		}
	}

	return f;
}

bool __stdcall IsThunk(PVOID pThunk, bool* pfRel = NULL)
{
#define CPU_JMP_MEM32   0x25FF
#define CPU_JMP_NEAR    0xE9

	bool fResult = false;

	if (pfRel)
		*pfRel = false;

	if (!IsBadReadPtr(pThunk, sizeof(WORD)))
	{
		if (*(WORD*)pThunk == CPU_JMP_MEM32)
		{
			PVOID** ppFunction = (PVOID**)((BYTE*)pThunk + sizeof(WORD));

			if (!IsBadReadPtr(*ppFunction, sizeof(DWORD)) &&
				!IsBadReadPtr(**ppFunction, sizeof(DWORD)))
			{
				fResult = true;
			}
		}
		else
			if (*LPBYTE(pThunk) == CPU_JMP_NEAR)
			{
				if (pfRel)
					*pfRel = true;

				fResult = true;
			}
	}
	return fResult;
}

PVOID __stdcall GetImportedFunctionAddress(PVOID pThunk)
{
	PVOID pFunction = NULL;

	bool  fRel;
	bool  fThunk = IsThunk(pThunk, &fRel);

	for (; fThunk; fThunk = IsThunk(pThunk, &fRel))
	{
		if (fRel)
			pThunk = LPBYTE(DWORD_PTR(pThunk) + 5 + *(DWORD*)(LPBYTE(pThunk) + 1));
		else
		{
			PVOID** ppFunction = (PVOID**)((BYTE*)pThunk + sizeof(WORD));
			pThunk = **ppFunction;
		}
	}

	return pThunk;
}

PVOID __stdcall GetFunctionAddress(PVOID pThunkOrRealAddr)
{
	return IsThunk(pThunkOrRealAddr) ?
		GetImportedFunctionAddress(pThunkOrRealAddr) : pThunkOrRealAddr;
}

void Change(PVOID funk, BYTE hexes[], BYTE bNop[], int hSize) {
	LPBYTE pCode = (LPBYTE)GetFunctionAddress(funk);
	bool brfl = 0;
	for (int g = 0; g < 256; g++, pCode++) {
		for (int i = 0; i < hSize; i++) {
			if (*(PBYTE)pCode == hexes[i]) {
				if (i == hSize - 1) {
					brfl = 1;
					break;
				}
				else
					pCode++;
			}
			else
				break;
		}
		if (brfl)
			break;
	}
	pCode -= hSize - 1;
	WriteProcessMemoryEx(pCode, bNop, hSize);
}

bool CH1 = 1, CH2 = 1;

void F1() {
	BYTE hexes[] = { 0xe9, 0xb4, 0x00, 0x00, 0x00 };
	BYTE bNop[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
	if (CH1) {
		Change(&oneNum, hexes, bNop, 5);
		CH1 = 0;
	}
	cout << oneNum() << endl;
}

void F2() {
	BYTE hexes[] = { 0xe9, 0x3d, 0x01, 0x00, 0x00 };
	BYTE bNop[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
	if (CH2) {
		Change(&allNums, hexes, bNop, 5);
		CH2 = 0;
	}
	cout << allNums() << endl;
}

int main() {
	string qwerty;
	int chce = 1;
here:
	switch (chce) {
	case 0: {
		VMKiller();
		chce = 3;
		Hurt();
		goto here;
	}

	case 1: {
		//CRC32 check for modification
		if (CRC32_check()) {
			FileCh;
			system(POZ);
			return -1;
		}
		chce = 0;
		goto here;
	}
	case 2: {
		Hurt();
		while (1) {
			int n = 4;
			InitMes;
			getline(cin, qwerty);
			if (OFF) {
				ShutMes;
				system(POZ);
				return 0;
			}
			//////////False password check////////////
			if (qwerty == FP1 || qwerty == FP2)
				VeryUsefulFunc();
			/////////////////////////////////////////
			if (checkPass(qwerty)) {
				int ch = 1;
				while (ch) {
					bool out = 0;
					MenuMes;
					Hurt();
					////False password check////
					if (qwerty == FP3)
						VeryUsefulFunc();
					////////////////////////////
					string menu;
					getline(cin, menu);
					ch = menu[0] - '0';
					switch (ch)
					{
					case 0: {
						BackMes;
						out = 1;
						ch = 1;
						break;
					}
					case 1: {
						if (checkPass(qwerty)) {
							Hurt();
							__asm {
								jz aouso
								jnz aouso
								_emit 0xB8
								aouso:
								call F1
							}
							//F1();
						}
						else {
							Hurt();
							out = 1;
							ch = 1;
						}
						break;
					}
					case 2: {
						if (checkPass(qwerty)) {
							__asm {
								jz aouse
								jnz aouse
								_emit 0xB8
								aouse:
								call F2
							}
							Hurt();
							//F2();
						}
						else {
							//////False password check/////
							if (qwerty == FP4) {
								VeryUsefulFunc();
								Hurt();
							}
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
						Hurt();
					}
					}
					if (out) break;
				}
			}
			else WrongMes;
		}
		break;
	}
	case 3: {
		DBG;
		chce = 2;
		goto here;
	}
	}

	system(POZ);
	return 0;

}