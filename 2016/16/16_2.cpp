#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("16.in");
	ofstream fout("16_2.out");
	string s;
	fin >> s;
	int len = 35651584;
	while (s.length() < len) {
		string cp = s;
		s += '0';
		reverse(cp.begin(), cp.end());
		for (int i = 0; i < cp.length(); i++) {
			cp[i] = '0' + '1' - cp[i];
		}
		s += cp;
	}
	
	s = s.substr(0, len);
	while (s.length() % 2 == 0) {
		string next = "";
		for (int i = 0; i < s.length(); i += 2) {
			if (s[i] == s[i + 1]) {
				next += '1';
			} else {
				next += '0';
			}
		}
		s = next;
	}
	fout << s;
	
	return 0;
}