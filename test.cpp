#include <iostream>
using namespace std;

string coSo10Sang2(int coSo10) {
	bool binary[8];
	bool temp[8];
	int x = coSo10;

	for (int i = 0; i < 8; i++) {
		temp[i] = x % 2;
		x = x / 2;
	}

	for (int i = 0; i < 8; i++) {
		binary[i] = temp[8 - i - 1];
	}

	string binaryString;

	for (int i = 0; i < 8; i++) {
		binaryString += (binary[i] ? '1' : '0');
	}

	return binaryString;
}

string bu1(string binaryString) {
	string chuyenBu1 = "";
	for (int i=0; i<sizeof(string); i++) {
		if(binaryString[i]=='0') {
			chuyenBu1 += '1';
		} else chuyenBu1 += '0';
	}
	return chuyenBu1;
}

string bu2(string bu1String) {
	string chuyenBu2 = bu1String;
	int i = sizeof(string) - 1;
	while(bu1String[i]== '1' && i>=0) {
		chuyenBu2[i] = '0';
		i--;
	}
	chuyenBu2[i] = '1';
	return chuyenBu2;
}

string set(int pos, string inputBinary) {
	bool binary[8];
	for(int i=0; i<8; i++) {
		binary[i] = inputBinary[i] == '0' ? 0:1;
	}

	binary[8-pos-1] = binary[8-pos-1] || 1;

	string outputBinary;
	for (int i = 0; i < 8; i++) {
		outputBinary += (binary[i] ? '1' : '0');
	}
	return outputBinary;
}

string clear(int pos, string inputBinary) {
	bool binary[8];
	for(int i=0; i<8; i++) {
		binary[i] = inputBinary[i] == '0' ? false:true;
	}

	binary[8-pos-1] = binary[8-pos-1] && 0;

	string outputBinary;
	for (int i = 0; i < 8; i++) {
		outputBinary += (binary[i] ? '1' : '0');
	}
	return outputBinary;
}

int main() {
	int coSo10;
	cout << "Nhap so: ";
	cin >> coSo10;

	string binaryResult = coSo10Sang2(coSo10);

	cout << "Co so 2: " << binaryResult << endl;

	string chuyenBu1Result = bu1(binaryResult);
	cout << "Bu 1: "<< chuyenBu1Result << endl;

	string chuyenBu2Result = bu2(chuyenBu1Result);
	cout << "Bu 2: "<< chuyenBu2Result << endl;

	int position;
	cout << "Nhap vi tri ban can Set: ";
	cin >> position;
	string setResult = set(position,chuyenBu2Result);
	cout << "Setted Binary: "<< setResult << endl;

	cout << "Nhap vi tri ban can Clear: ";
	cin >> position;
	string clearResult = clear(position,chuyenBu2Result);
	cout << "Cleared Binary: "<< clearResult;
	return 0;
}
