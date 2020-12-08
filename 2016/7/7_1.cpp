#include <bits/stdc++.h>

using namespace std;

bool good(string& s) {
	bool in_brackets = false;
	bool have_abba = false;
	for (int i = 0; i < s.length() - 3; i++) {
		if (s[i] == '[') {
			in_brackets = true;
		} else if (s[i] == ']') {
			in_brackets = false;
		} else if (s[i] == s[i + 3] && s[i + 1] == s[i + 2] && s[i] != s[i + 1]) {
			if (in_brackets) {
				return false;
			}
			have_abba = true;
		}
	}
	return have_abba;
}

int main() {
	
	ifstream fin("7.in");
	ofstream fout("7_1.out");
	int ans = 0;
	string s;
	while (fin >> s) {
		ans += good(s);
	}
	fout << ans;
	
	return 0;
}