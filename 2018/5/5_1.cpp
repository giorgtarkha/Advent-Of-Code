#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("5.in");
	ofstream fout("5_1.out");
	string s;
	fin >> s;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
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
	fout << st.size();
	
	return 0;
}