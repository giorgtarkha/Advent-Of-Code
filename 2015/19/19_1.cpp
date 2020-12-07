#include <bits/stdc++.h>

using namespace std;

void parse_input(string& input, map<string, vector<string>>& replacements) {
	string key = "";
	string value = "";
	bool have_key = false;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ' || input[i] == '=' || input[i] == '>') {
			have_key = true;
			continue;
		} else {
			if (have_key) {
				value += input[i];
			} else {
				key += input[i];
			}
		}
	}
	replacements[key].push_back(value);
}

int main() {
	
	ifstream fin("19.in");
	ofstream fout("19_1.out");
	string s;
	map<string, vector<string>> replacements;
	while (getline(fin, s)) {
		if (s == "") {
			break;
		}
		parse_input(s, replacements);
	}
	fin >> s;
	
	set<string> possibles;
	for (auto it = replacements.begin(); it != replacements.end(); ++it) {
		for (int i = 0; i < s.length() - it->first.length() + 1; i++) {
			bool good = true;
			for (int j = 0; j < it->first.length(); j++) {
				if (s[i + j] != it->first[j]) {
					good = false;
					break;
				}
			}
			if (good) {
				for (int j = 0; j < it->second.size(); j++) {
					possibles.insert(s.substr(0, i) + it->second[j] + s.substr(i + it->first.length(), s.length()));
				}
			}
		}
	}
	fout << possibles.size();
	
	return 0;
}