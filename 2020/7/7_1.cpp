#include <bits/stdc++.h>

using namespace std;

void go(string& curr, map<string, vector<string>>& parents, set<string>& visited) {
	visited.insert(curr);
	for (int i = 0; i < parents[curr].size(); i++) {
		go(parents[curr][i], parents, visited);
	}
}

void parse_input(string& line, map<string, vector<string>>& parents) {
	string parent = "";
	int count = 0;
	for (int i = 0; i < line.length(); i++) {
		parent += line[i];
		if (line[i] == ' ') {
			count++;
			if (count == 2) {
				break;
			}
		}
	}
	parent.pop_back();
	int index = line.find("contain", 0);
	while (line[index] != ' ') {
		index++;
	}
	index++;
	while (true) {
		string curr = "";
		int num = 0;
		while (line[index] != ',' && line[index] != '.') {
			if (line[index] == ' ') {
				if (num) {
					curr += line[index];
				} else {
					if (curr[0] < '0' || curr[0] > '9') {
						return;
					}
					num = stoi(curr);
					curr = "";
				}
			} else {
				curr += line[index];
			}
			index++;
		}
		curr = curr.substr(0, curr.length() - 4);
		if (curr.back() == ' ') {
			curr.pop_back();
		}
		parents[curr].push_back(parent);
		if (line[index] == '.') {
			break;
		}
		index += 2;
	}
}

int main() {
	
	ifstream fin("7.in");
	ofstream fout("7_1.out");
	map<string, vector<string>> parents;
	for (string line; getline(fin, line);) {
		parse_input(line, parents);
	}
	set<string> visited;
	string start = "shiny gold";
	go(start, parents, visited);
	fout << visited.size() - 1;
	
	return 0;
}