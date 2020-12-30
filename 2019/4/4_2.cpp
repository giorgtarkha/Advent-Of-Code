#include <bits/stdc++.h>

using namespace std;

bool good(string s) {
	string cp = s;
	sort(cp.begin(), cp.end());
	if (cp != s) {
		return false;
	}
	
	map<char, int> cnt;
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i]]++;
	}
	
	for (auto it = cnt.begin(); it != cnt.end(); ++it) {
		if (it->second == 2) {
			return true;
		}
	}
	
	return false;
}

int main() {
	
	ofstream fout("4_2.out");
	int ans = 0;
	for (int i = 109165; i < 576723; i++) {
		ans += good(to_string(i));
	}
	fout << ans;
	
	return 0;
}