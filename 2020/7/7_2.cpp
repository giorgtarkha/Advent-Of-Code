#include <bits/stdc++.h>

using namespace std;

void parse_input(string& line, map<string, vector<pair<string, int>>>& children) {
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
		children[parent].push_back({curr, num});
		if (line[index] == '.') {
			break;
		}
		index += 2;
	}
}

void go(string& curr, map<string, vector<pair<string, int>>>& children, int& ans) {
	ans++;
	for (int i = 0; i < children[curr].size(); i++) {
		for (int j = 0; j < children[curr][i].second; j++) {
			go(children[curr][i].first, children, ans);
		}
	}
}

int main() {
	
	ifstream fin("7.in");
	ofstream fout("7_2.out");
	map<string, vector<pair<string, int>>> children;
	for (string line; getline(fin, line);) {
		parse_input(line, children);
	}
	set<string> visited;
	string start = "shiny gold";
	int ans = 0;
	go(start, children, ans);
	fout << ans - 1;
	
	return 0;
}