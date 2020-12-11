#include <bits/stdc++.h>

using namespace std;

int get_division(string& s) {
	s += ' ';
	string curr = "";
	vector<int> vals;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == '\t') {
			if (curr != "") {
				vals.push_back(stoi(curr));
				curr = "";
			}
		} else {
			curr += s[i];
		}
	}
	for (int i = 0; i < vals.size() - 1; i++) {
		for (int j = i + 1; j < vals.size(); j++) {
			if (vals[j] % vals[i] == 0) {
				return vals[j] / vals[i];
			}
			if (vals[i] % vals[j] == 0) {
				return vals[i] / vals[j];
			}
		}
	}
	return 0;
}

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_2.out");
	int ans = 0;
	for (string line; getline(fin, line);) {
		ans += get_division(line);
	}
	fout << ans;
	
	return 0;
}