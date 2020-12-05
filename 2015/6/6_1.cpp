#include <bits/stdc++.h>

using namespace std;

vector<int> parse_line(string& line) {
	int start_index;
	vector<int> res;
	if (line.rfind("turn on", 0) == 0) {
		start_index = 8;
		res.push_back(1);
	} else if (line.rfind("turn off", 0) == 0) {
		start_index = 9;
		res.push_back(0);
	} else {
		start_index = 7;
		res.push_back(-1);
	}
	
	string from = "", to = "";
	
	for (int i = start_index; line[i] != ' '; i++) {
		from += line[i];
	}
	for (int i = line.length() - 1; line[i] != ' '; i--) {
		to = string(1, line[i]) + to;
	}
	
	from += ",";
	to += ",";
	string curr = "";
	for (int i = 0; i < from.length(); i++) {
		if (from[i] == ',') {
			res.push_back(stoi(curr));
			curr = "";
		} else {
			curr += from[i];
		}
	}
	
	curr = "";
	for (int i = 0; i < to.length(); i++) {
		if (to[i] == ',') {
			res.push_back(stoi(curr));
			curr = "";
		} else {
			curr += to[i];
		}
	}
	
	
	return res;
}

int main() {
	
	ifstream fin("6.in");
	ofstream fout("6_1.out");
	bool grid[1000][1000];
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			grid[i][j] = 0;
		}
	}
	for (string line; getline(fin, line);) {
		vector<int> data = parse_line(line);
		if (data[0] == -1) {
			for (int i = data[1]; i <= data[3]; i++) {
				for (int j = data[2]; j <= data[4]; j++) {
					grid[i][j] ^= 1;
				}
			}
		} else if (data[0] == 1) {
			for (int i = data[1]; i <= data[3]; i++) {
				for (int j = data[2]; j <= data[4]; j++) {
					grid[i][j] |= 1;
				}
			}
		} else {
			for (int i = data[1]; i <= data[3]; i++) {
				for (int j = data[2]; j <= data[4]; j++) {
					grid[i][j] &= 0;
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			ans += grid[i][j];
		}
	}
	fout << ans;
	
	return 0;
}