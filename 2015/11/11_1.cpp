#include <bits/stdc++.h>

using namespace std;

bool good(string& s) {
	bool straight = false;
	for (int i = 0; i < s.length() - 2; i++) {
		if (s[i] == 'i' || s[i] == 'o' || s[i] == 'l') {
			return false;
		}
		if (s[i] == s[i + 1] - 1 && s[i] == s[i + 2] - 2) {
			straight = true;
			break;
		}
	}
	
	int d_index = -1;
	bool doubles = false;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'i' || s[i] == 'o' || s[i] == 'l') {
			return false;
		}
		if (s[i] == s[i - 1]) {
			if (d_index == -1) {
				d_index = i;
			} else {
				if (d_index != i - 1) {
					doubles = true;
					break;
				}
			}
		}
	}

	return straight & doubles;
}

int main() {
	
	ifstream fin("11.in");
	ofstream fout("11_1.out");
	string s;
	fin >> s;
	int count = 0;
	while (true) {
		int index = s.length() - 1;
		while (s[index] == 'z') {
			s[index] = 'a';
			index--;
		}
		s[index]++;
		if (good(s)) {
			break;
		}
	}
	fout << s;
	
	return 0;
}