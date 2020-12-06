#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("6.in");
	ofstream fout("6_1.out");
	set<char> answers;
	int ans = 0;
	for (string s; getline(fin, s);) {
		if (s == "") {
			ans += answers.size();
			answers.clear();
		} else {
			for (int i = 0; i < s.length(); i++) {
				answers.insert(s[i]);
			}
		}
	}
	ans += answers.size();
	fout << ans;
	
	return 0;
}