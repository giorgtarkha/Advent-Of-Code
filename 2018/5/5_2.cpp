#include <bits/stdc++.h>

using namespace std;

int go(string s, char c) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (tolower(s[i]) == c) {
			continue;
		}
		if (!st.size()) {
			st.push(s[i]);
		} else if (tolower(st.top()) != tolower(s[i])) {
			st.push(s[i]);
		} else if (st.top() != s[i]) {
			st.pop();
		} else {
			st.push(s[i]);
		}
	}
	return st.size();
}

int main() {
	
	ifstream fin("5.in");
	ofstream fout("5_2.out");
	string s;
	fin >> s;
	int ans = 1 << 29;
	for (char c = 'a'; c <= 'z'; c++) {
		ans = min(ans, go(s, c));
	}
	fout << ans;
	
	return 0;
}