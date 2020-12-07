#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("23.in");
	ofstream fout("23_1.out");
	vector<vector<int>> instructions;
	string instruction;
	while (fin >> instruction) {
		if (instruction == "inc" || instruction == "tpl" || instruction == "hlf" || instruction == "jmp") {
			string s;
			fin >> s;
			if (instruction == "inc") {
				instructions.push_back({0, s[0] - 'a'});
			} else if (instruction == "tpl") {
				instructions.push_back({1, s[0] - 'a'});
			} else if (instruction == "hlf") {
				instructions.push_back({2, s[0] - 'a'});
			} else {
				instructions.push_back({3, s[0] == '+' ? stoi(s.substr(1, s.length())) : stoi(s)});
			}
		} else {
			string s1, s2;
			fin >> s1 >> s2;
			if (instruction == "jie") {
				instructions.push_back({4, s1[0] - 'a', s2[0] == '+' ? stoi(s2.substr(1, s2.length())) : stoi(s2)});
			} else {
				instructions.push_back({5, s1[0] - 'a', s2[0] == '+' ? stoi(s2.substr(1, s2.length())) : stoi(s2)});
			}
		}
	}
	
	int r[2] = {0};
	for (int i = 0; i < instructions.size();) {
		if (instructions[i][0] == 0) {
			r[instructions[i][1]]++;
		} else if (instructions[i][0] == 1) {
			r[instructions[i][1]] *= 3;
		} else if (instructions[i][0] == 2) {
			r[instructions[i][1]] /= 2;
		} else if (instructions[i][0] == 3) {
			if (i + instructions[i][1] >= 0 && i + instructions[i][1] < instructions.size()) {
				i += instructions[i][1];
				continue;
			} else {
				break;
			}
		} else if (instructions[i][0] == 4) {
			if (r[instructions[i][1]] % 2 == 0) {
				if (i + instructions[i][2] >= 0 && i + instructions[i][2] < instructions.size()) {
					i += instructions[i][2];
					continue;
				} else {
					break;
				}
			}
		} else if (instructions[i][0] == 5) {
			if (r[instructions[i][1]] == 1) {
				if (i + instructions[i][2] >= 0 && i + instructions[i][2] < instructions.size()) {
					i += instructions[i][2];
					continue;
				} else {
					break;
				}
			}
		}
		i++;
	}
	fout << r[1];
	
	return 0;
}