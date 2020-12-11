#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_2.out");
	string s;
	fin >> s;
	s += s;
	int ans = 0;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] == s[i + s.length() / 4]) {
			ans += s[i] - '0';
		}
	}
	fout << ans;
	
	return 0;
}