#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("21.in");
	ofstream fout("21_2.out");
	string s, target = "fbgdceah";
	
	vector<string> initial_possibles;
	vector<string> possibles;
	string start = "abcdefgh";
	do {
		initial_possibles.push_back(start);
		possibles.push_back(start);
	} while (next_permutation(start.begin(), start.end()));
	
	while (fin >> s) {
		if (s == "swap") {
			string s2[5];
			fin >> s2[0] >> s2[1] >> s2[2] >> s2[3] >> s2[4];
			for (int j = 0; j < possibles.size(); j++) {
				if (s2[0] == "position") {
					swap(possibles[j][stoi(s2[1])], possibles[j][stoi(s2[4])]);
				} else {
					for (int i = 0; i < possibles[j].length(); i++) {
						if (possibles[j][i] == s2[1][0]) {
							possibles[j][i] = s2[4][0];
						} else if (possibles[j][i] == s2[4][0]) {
							possibles[j][i] = s2[1][0];
						}
					}
				}
			}
		} else if (s == "rotate") {
			string s1;
			fin >> s1;
			if (s1 == "based") {
				string s2[5];
				fin >> s2[0] >> s2[1] >> s2[2] >> s2[3] >> s2[4];
				for (int j = 0; j < possibles.size(); j++) {
					int index = possibles[j].find(s2[4], 0);
					possibles[j] = possibles[j].substr(possibles[j].length() - 1, 1) + possibles[j].substr(0, possibles[j].length() - 1);
					possibles[j] = possibles[j].substr(possibles[j].length() - index, index) + possibles[j].substr(0, possibles[j].length() - index);
					if (index >= 4) {
						possibles[j] = possibles[j].substr(possibles[j].length() - 1, 1) + possibles[j].substr(0, possibles[j].length() - 1);
					}
				}
			} else {
				int z;
				fin >> z;
				fin >> s;
				for (int j = 0; j < possibles.size(); j++) {
					int x = z;
					x %= possibles[j].length();
					if (s1 == "left") {
						possibles[j] = possibles[j].substr(x, possibles[j].length() - x) + possibles[j].substr(0, x);
					} else {
						possibles[j] = possibles[j].substr(possibles[j].length() - x, x) + possibles[j].substr(0, possibles[j].length() - x);
					}
				}
			}
		} else if (s == "reverse") {
			string s2[4];
			fin >> s2[0] >> s2[1] >> s2[2] >> s2[3];
			for (int j = 0; j < possibles.size(); j++) {
				reverse(possibles[j].begin() + stoi(s2[1]), possibles[j].begin() + stoi(s2[3]) + 1);
			}
		} else {
			string s2[5];
			fin >> s2[0] >> s2[1] >> s2[2] >> s2[3] >> s2[4];
			int from = stoi(s2[1]), to = stoi(s2[4]);
			for (int j = 0; j < possibles.size(); j++) {
				char c = possibles[j][from];
				possibles[j].erase(possibles[j].begin() + from);
				possibles[j].insert(possibles[j].begin() + to, c);
			}
		}
	}
	
	for (int i = 0; i < possibles.size(); i++) {
		if (possibles[i] == target) {
			fout << initial_possibles[i];
			break;
		}
	}
	
	return 0;
}