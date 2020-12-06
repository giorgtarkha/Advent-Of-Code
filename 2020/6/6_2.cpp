#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("6.in");
	ofstream fout("6_2.out");
	map<char, int> answers;
	int ans = 0;
	int count = 0;
	for (string s; getline(fin, s);) {
		if (s == "") {
			for (auto it = answers.begin(); it != answers.end(); ++it) {
				if (it->second == count) {
					ans++;
				}
			}
			answers.clear();
			count = 0;
		} else {
			for (int i = 0; i < s.length(); i++) {
				answers[s[i]]++;
			}
			count++;
		}
	}
	for (auto it = answers.begin(); it != answers.end(); ++it) {
		if (it->second == count) {
			ans++;
		}
	}
	fout << ans;
	
	return 0;
}