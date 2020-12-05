#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	
	string s;
	fin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		ans += s[i] == '(' ? 1 : -1;
	}
	fout << ans;
	
	return 0;
}