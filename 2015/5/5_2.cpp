#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("5.in");
	ofstream fout("5_2.out");
	
	string s;
	int ans = 0;
	while (fin >> s) {
		bool have_t = false;
		bool have_p = false;
		map<string, vector<int>> pairs;
		for (int i = 0; i < s.length() - 1; i++) {
			if (i < s.length() - 2) {
				if (s[i] == s[i + 2]) {
					have_t = true;
				}
			}
			string curr_pair = "";
			curr_pair += s[i];
			curr_pair += s[i + 1];
			if (pairs.count(curr_pair)) {
				for (int j = 0; j < pairs[curr_pair].size(); j++) {
					if (pairs[curr_pair][j] != i - 1) {
						have_p = true;
					}
				}
			}
			pairs[curr_pair].push_back(i);
		}
		ans += have_t && have_p;
	}
	fout << ans;
	
	return 0;
}
