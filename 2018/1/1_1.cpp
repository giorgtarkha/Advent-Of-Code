#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	int ans = 0;
	string s;
	while (fin >> s) {
		if (s[0] == '+') {
			ans += stoi(s.substr(1, s.length() - 1));
		} else {
			ans -= stoi(s.substr(1, s.length() - 1));
		}
	}
	fout << ans;
	
	return 0;
}