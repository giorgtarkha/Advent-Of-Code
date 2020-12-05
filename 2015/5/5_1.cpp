#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("5.in");
	ofstream fout("5_1.out");
	
	string s;
	int ans = 0;
	while (fin >> s) {
		int vowel_count = 0;
		bool have_adjacents = false;
		bool possible = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				vowel_count++;
			} 
			if (i) {
				if (s[i] == s[i - 1]) {
					have_adjacents = true;
				}
				if (s[i - 1] == 'a' && s[i] == 'b' ||
				    s[i - 1] == 'c' && s[i] == 'd' ||
					s[i - 1] == 'p' && s[i] == 'q' ||
					s[i - 1] == 'x' && s[i] == 'y') {
					possible = false;
					break;
				}
			}
		}
		
		ans += have_adjacents && possible && vowel_count >= 3;
	}
	fout << ans;
	
	return 0;
}
