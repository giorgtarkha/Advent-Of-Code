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

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_1.out");
	string s;
	fin >> s;
	vector<int> ops;
	parse_input(s, ops);
	int index = 0;
	ops[1] = 12;
	ops[2] = 2;
	while (index < ops.size() - 3 && ops[index] != 99) {
		if (ops[index] == 1) {
			ops[ops[index + 3]] = ops[ops[index + 1]] + ops[ops[index + 2]];  
		} else if (ops[index] == 2) {
			ops[ops[index + 3]] = ops[ops[index + 1]] * ops[ops[index + 2]];
		}
		index += 4;
	}
	fout << ops[0];
	
	return 0;
}