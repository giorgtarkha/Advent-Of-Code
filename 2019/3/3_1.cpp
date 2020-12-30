#include <bits/stdc++.h>

using namespace std;

void parse_input(string& s, set<pair<int, int>>& st, int& ans, bool change_ans) {
	s += ',';
	int curri = 0, currj = 0;
	string curr = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			int distance = stoi(curr.substr(1, curr.length() - 1));
			int offseti = curr[0] == 'U' ? 1 : curr[0] == 'D' ? -1 : 0;
			int offsetj = curr[0] == 'R' ? 1 : curr[0] == 'L' ? -1 : 0;
			for (int j = 0; j < distance; j++) {
				curri += offseti;
				currj += offsetj;
				if (change_ans) {
					if (st.count({curri, currj})) {
						ans = min(ans, abs(curri) + abs(currj));
					}
				} else {
					st.insert({curri, currj});
				}
			}
			curr = "";
		} else {
			curr += s[i];
		}
	}
}

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_1.out");
	string s;
	fin >> s;
	int ans = 1 << 30;
	set<pair<int, int>> st;
	parse_input(s, st, ans, false);
	fin >> s;
	parse_input(s, st, ans, true);
	fout << ans;
	
	return 0;
}