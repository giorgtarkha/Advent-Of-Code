#include <bits/stdc++.h>

using namespace std;

bool good(string& s) {
	bool in_brackets = false;
	bool have_abba = false;
	set<string> brackets;
	set<string> outside;
	for (int i = 0; i < s.length() - 2; i++) {
		if (s[i] == '[') {
			in_brackets = true;
		} else if (s[i] == ']') {
			in_brackets = false;
		} else if (s[i] == s[i + 2] && s[i] != s[i + 1]) {
			string curr = "";
			curr += s[i];
			curr += s[i + 1];
			curr += s[i + 2];
			if (in_brackets) {
				brackets.insert(curr);
			} else {
				outside.insert(curr);
			}
		}
	}
	
	for (auto it = brackets.begin(); it != brackets.end(); ++it) {
		string curr = *it;
		swap(curr[0], curr[1]);
		curr[2] = curr[0];
		if (outside.count(curr)) {
			return true;
		}
	}
	
	return false;
}

int main() {
	
	ifstream fin("7.in");
	ofstream fout("7_2.out");
	int ans = 0;
	string s;
	while (fin >> s) {
		ans += good(s);
	}
	fout << ans;
	
	return 0;
}