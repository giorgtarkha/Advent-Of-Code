#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("8.in");
	ofstream fout("8_2.out");
	string s;
	int ans = 0;
	while (fin >> s) {
		int encoded = 4;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == '\"' || s[i] == '\\') {
				encoded += 2;
			} else {
				encoded++;
			}
		}
		ans += encoded - s.length();
	}
	fout << ans;
	
	return 0;
}