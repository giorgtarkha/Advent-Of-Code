#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("12.in");
	ofstream fout("12_1.out");
	string s;
	fin >> s;
	string curr = "";
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
			curr += s[i];
		} else {
			if (curr.length() >= 2) {
				ans += stoi(curr);
			} else if (curr.length() == 1) {
				if (curr[0] != '-') {
					ans += stoi(curr);
				} 
			}
			curr = "";
		}
	}
	fout << ans;
	
	return 0;
}