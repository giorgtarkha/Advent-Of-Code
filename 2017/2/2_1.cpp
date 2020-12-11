#include <bits/stdc++.h>

using namespace std;

int get_difference(string& s) {
	s += ' ';
	string curr = "";
	int min_val = 1 << 29;
	int max_val = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == '\t') {
			if (curr != "") {
				int val = stoi(curr);
				min_val = min(min_val, val);
				max_val = max(max_val, val);
				curr = "";
			}
		} else {
			curr += s[i];
		}
	}
	return max_val - min_val;
}

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_1.out");
	int ans = 0;
	for (string line; getline(fin, line);) {
		ans += get_difference(line);
	}
	fout << ans;
	
	return 0;
}