#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_1.out");
	string s;
	int r = 1, c = 1;
	string ans = "";
	while (fin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'U') {
				r = max(r - 1, 0); 
			} else if (s[i] == 'D') {
				r = min(r + 1, 2);
			} else if (s[i] == 'L') {
				c = max(c - 1, 0);
			} else {
				c = min(c + 1, 2);
			}
		}
		ans += '0' + r * 3 + c + 1;
	}
	fout << ans;
	
	return 0;
}