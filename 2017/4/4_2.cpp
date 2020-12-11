#include <bits/stdc++.h>

using namespace std;

bool valid(string& s) {
	s += ' ';
	set<string> occured;
	string curr = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			if (curr != "") {
				sort(curr.begin(), curr.end());
				if (occured.count(curr)) {
					return false;
				}
				occured.insert(curr);
				curr = "";
			}
		} else {
			curr += s[i];
		}
	}
	return true;
}

int main() {
	
	ifstream fin("4.in");
	ofstream fout("4_2.out");
	int ans = 0;
	for (string line; getline(fin, line);) { 
		ans += valid(line);
	}
	fout << ans;
	
	return 0;
}