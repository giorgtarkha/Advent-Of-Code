#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("6.in");
	ofstream fout("6_2.out");
	string s;
	fin >> s;
	int count[s.length()][26];
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			count[i][j] = 0;
		}
	}
	
	do {
		for (int i = 0; i < s.length(); i++) {
			count[i][s[i] - 'a']++;
		}
	} while (fin >> s);
	
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		int min_c = 1 << 30;
		char c = ' ';
		for (int j = 0; j < 26; j++) {
			if (count[i][j] < min_c && count[i][j]) {
				min_c = count[i][j];
				c = 'a' + j;
			}
		}
		ans += c;
		
	}
	fout << ans;
	
	return 0;
}