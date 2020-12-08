#include <bits/stdc++.h>

using namespace std;

pair<bool, int> go(vector<pair<int, int>>& instructions) {
	int acc = 0; 
	bool visited[instructions.size()] = {false};
	int i = 0;
	for (; i < instructions.size();) {
		if (visited[i]) {
			break;
		}
		visited[i] = true;
		if (instructions[i].first == 0) {
			acc += instructions[i].second;
			i++;
		} else if (instructions[i].first == 1) {
			i += instructions[i].second;
		} else {
			i++;
		}
	}
	if (i == instructions.size()) {
		return {true, acc};
	} else {
		return {false, 0};
	}
}

int main() {
	
	ifstream fin("8.in");
	ofstream fout("8_2.out");
	string s;
	vector<pair<int, int>> instructions;
	while (fin >> s) {
		string num;
		fin >> num;
		if (s == "acc") {
			instructions.push_back({0, stoi(num)});
		} else if (s == "jmp") {
			instructions.push_back({1, stoi(num)});
		} else {
			instructions.push_back({2, stoi(num)});
		}
	}
	
	for (int i = 0; i < instructions.size(); i++) {
		if (instructions[i].first == 1) {
			instructions[i].first = 2;
			pair<bool, int> res = go(instructions);
			if (res.first) {
				fout << res.second;
				return 0;
			}
			instructions[i].first = 1;
		} else if (instructions[i].second == 1) {
			instructions[i].first = 1;
			pair<bool, int> res = go(instructions);
			if (res.first) {
				fout << res.second;
				return 0;
			}
			instructions[i].first = 2;
		}
	}
	
	return 0;
}