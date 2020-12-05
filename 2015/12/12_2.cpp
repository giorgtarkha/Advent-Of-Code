#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("12.in");
	ofstream fout("12_2.out");
	string s;
	fin >> s;
	
	set<int> bad_indices;
	for (int i = 0; i < s.length() - 4; i++) {
		if (s[i] == '\"' && s[i + 1] == 'r' && s[i + 2] == 'e' && s[i + 3] == 'd' && s[i + 4] == '\"') {
			vector<int> indices;
			bool array = true;
			int count = 0;
			for (int j = i; j < s.length(); j++) {
				indices.push_back(j);
				if (s[j] == '}') {
					if (!count) {
						array = false;
						break;
					} else {
						count--;
					}
				} else if (s[j] == ']') {
					if (!count) {
						break;
					} else {
						count--;
					}
				} else if (s[j] == '[' || s[j] == '{') {
					count++;
				}
			}
			
			count = 0;
			for (int j = i; j >= 0; j--) {
				indices.insert(indices.begin(), j);
				if (s[j] == '{') {
					if (!count) {
						array = false;
						break;
					} else {
						count--;
					}
				} else if (s[j] == '[') {
					if (!count) {
						break;
					} else {
						count--;
					}
				} else if(s[j] == ']' || s[j] == '}') {
					count++;
				} 
			}
			
			if (!array) {
				for (int j = 0; j < indices.size(); j++) {
					bad_indices.insert(indices[j]);
				}
			}
		}
	}
	
	string curr = "";
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
			if (!bad_indices.count(i)) {
				curr += s[i];
			}
		} else {
			if (curr.length() >= 2) {
				ans += stoi(curr);
			} else if (curr.length() == 1) {
				if (curr[0] != '-') {
					ans += stoi(curr);
				} 
			}
			curr = "";
		}
	}
	fout << ans;
	
	return 0;
}