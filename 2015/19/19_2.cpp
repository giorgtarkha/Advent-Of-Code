#include <bits/stdc++.h>

using namespace std;

void parse_input(string& input, map<string, string>& replacements, vector<string>& replacement_keys) {
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
	replacements[value] = key;
	replacement_keys.push_back(value);
}

int main() {
	
	ifstream fin("19.in");
	ofstream fout("19_2.out");
	string s;
	map<string, string> replacements;
	vector<string> replacement_keys;
	while (getline(fin, s)) {
		if (s == "") {
			break;
		}
		parse_input(s, replacements, replacement_keys);
	}
	fin >> s;
	
	int ans = 2 << 29;
	while (s != "e") {
		int steps = 0;
		string before = s;
		bool can = true;
		random_shuffle(replacement_keys.begin(), replacement_keys.end());
		while (can) {
			can = false;
			for (int i = 0; i < replacement_keys.size(); i++) {
				if (replacement_keys[i].length() <= s.length()) {
					int index = s.find(replacement_keys[i]);
					if (index != string::npos) {
						can = true;
						steps++;
						s = s.substr(0, index) + replacements[replacement_keys[i]] + s.substr(index + replacement_keys[i].length(), s.length());
					}
				}
			}
		}
		if (s == "e") {
			ans = steps;
			break;
		}
		s = before;
	}
	fout << ans;
	
	return 0;
}