#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	string s;
	fin >> s;
	s += s[0];
	int ans = 0;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1]) {
			ans += s[i] - '0';
		}
	}
	fout << ans;
	
	return 0;
}