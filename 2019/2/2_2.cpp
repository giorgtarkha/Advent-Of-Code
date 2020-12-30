#include <bits/stdc++.h>

using namespace std;

void parse_input(string& s, vector<int>& ops) {
	s += ',';
	string curr = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			ops.push_back(stoi(curr));
			curr = "";
		} else {
			curr += s[i];
		}
	}
}

int solve(vector<int> ops, int noun, int verb) {
	int index = 0;
	ops[1] = noun;
	ops[2] = verb;
	while (index < ops.size() - 3 && ops[index] != 99) {
		if (ops[index] == 1) {
			ops[ops[index + 3]] = ops[ops[index + 1]] + ops[ops[index + 2]];  
		} else if (ops[index] == 2) {
			ops[ops[index + 3]] = ops[ops[index + 1]] * ops[ops[index + 2]];
		}
		index += 4;
	}
	return ops[0];
}

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_2.out");
	string s;
	fin >> s;
	vector<int> ops;
	parse_input(s, ops);
	for (int noun = 0; noun < 100; noun++) {
		for (int verb = 0; verb < 100; verb++) {
			if (solve(ops, noun, verb) == 19690720) {
				fout << 100 * noun + verb;
				return 0;
			}
		}
	}
	
	return 0;
}