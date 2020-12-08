#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("8.in");
	ofstream fout("8_1.out");
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
			instructions.push_back({2, 0});
		}
	}
	
	int acc = 0; 
	bool visited[instructions.size()] = {false};
	for (int i = 0; i < instructions.size();) {
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
	fout << acc;
	
	return 0;
}