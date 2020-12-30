#include <bits/stdc++.h>

using namespace std;

bool good(string s) {
	string cp = s;
	sort(cp.begin(), cp.end());
	if (cp != s) {
		return false;
	}
	
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) {
			return true;
		}
	}
	return false;
}

int main() {
	
	ofstream fout("4_1.out");
	int ans = 0;
	for (int i = 109165; i < 576723; i++) {
		ans += good(to_string(i));
	}
	fout << ans;
	
	return 0;
}