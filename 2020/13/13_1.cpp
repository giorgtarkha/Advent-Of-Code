#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("13.in");
	ofstream fout("13_1.out");
	int min_dt;
	fin >> min_dt;
	string s;
	fin >> s;
	s += ',';
	string curr = "";
	int ans_time = 1 << 30, ans;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			if (curr != "x") {
				int time = stoi(curr);
				int d = min_dt / time;
				int dd = d * time;
				if (dd < min_dt) {
					dd += time;
				}
				if (ans_time - min_dt > dd - min_dt) {
					ans_time = dd;
					ans = (dd - min_dt) * time;
				}
			}
			curr = "";
		} else {
			curr += s[i];
		}
	}
	fout << ans;
	
	return 0;
}