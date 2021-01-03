#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("12.in");
	ofstream fout("12_1.out");
	string instruction;
	int registers[4] = {0, 0, 0, 0};
	vector<vector<string>> instructions;
	while (fin >> instruction) {
		if (instruction == "cpy" || instruction == "jnz") {
			string s[2];
			fin >> s[0] >> s[1];
			instructions.push_back({instruction, s[0], s[1]});
		} else {
			string s;
			fin >> s;
			instructions.push_back({instruction, s});
		}
		
	}
	
	for (int i = 0; i < instructions.size();) {
		if (instructions[i][0] == "cpy") {
			if (isdigit(instructions[i][1][0])) {
				registers[instructions[i][2][0] - 'a'] = stoi(instructions[i][1]);
			} else {
				registers[instructions[i][2][0] - 'a'] = registers[instructions[i][1][0] - 'a'];
			}
			i++;
		} else if (instructions[i][0] == "inc") {
			string s;
			fin >> s;
			registers[instructions[i][1][0] - 'a']++;
			i++;
		} else if (instructions[i][0] == "dec") {
			string s;
			fin >> s;
			registers[instructions[i][1][0] - 'a']--;
			i++;
		} else if (instructions[i][0] == "jnz") {
			int val;
			if (isdigit(instructions[i][1][0])) {
				val = stoi(instructions[i][1]);
			} else {
				val = registers[instructions[i][1][0] - 'a'];
			}
			
			if (val) {
				int offset = stoi(instructions[i][2]);
				i += offset;
			} else {
				i++;
			}
		}
	}
	fout << registers[0];
	
	return 0;
}