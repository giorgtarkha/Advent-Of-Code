#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_1.out");
	
	string binary;
	vector<int> count(12, 0);
	int num = 0;
	while (fin >> binary) {
		for (int i = 0; i < binary.length(); i++) {
			count[i] += binary[i] == '1';
		}
		num++;
	}
	
	int gamma = 0, epsilon = 0;
	for (int i = 0; i < 12; i++) {
		if (count[i] * 2 > num) {
			gamma |= 1 << (11 - i);
		} else {
			epsilon |= 1 << (11 - i);
		}
	}
	fout << gamma * epsilon << endl;
	
	return 0;
}