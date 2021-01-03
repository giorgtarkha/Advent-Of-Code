#include <bits/stdc++.h>

using namespace std;

int get_safe_num(string& s) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		res += s[i] == '.';
	}
	return res;
}

int main() {
	
	ifstream fin("18.in");
	ofstream fout("18_2.out");
	string s;
	fin >> s;
	int ans = get_safe_num(s);
	for (int i = 0; i < 399999; i++) {
		string next = "";
		int len = s.length();
		s = "." + s + ".";
		for (int j = 1; j <= len; j++) {
			if (s[j - 1] == '.' && s[j] == '^' && s[j + 1] == '^') {
				next += '^';
			} else if (s[j - 1] == '^' && s[j] == '^' && s[j + 1] == '.') {
				next += '^';
			} else if (s[j - 1] == '^' && s[j + 1] != '^') {
				next += '^';
			} else if (s[j + 1] == '^' && s[j - 1] != '^') {
				next += '^';
			} else {
				next += '.';
			}
		}
		s = next;
		ans += get_safe_num(s);
	}
	fout << ans;
	
	return 0;
}