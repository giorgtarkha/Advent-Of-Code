#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("8.in");
	ofstream fout("8_1.out");
	string s;
	int ans = 0;
	while (fin >> s) {
		int actual = 0;
		for (int i = 1; i < s.length() - 1;) {
			if (s[i] == '\\') {
				if (s[i + 1] == 'x') {
					i += 4;
				} else {
					i += 2;
				}
			} else {
				i++;
			}
			actual++;
		}
		ans += s.length() - actual;
	}
	fout << ans;
	
	return 0;
}