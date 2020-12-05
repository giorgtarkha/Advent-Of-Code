#include <bits/stdc++.h>

using namespace std;

void push_data_split(vector<string>& data, string& line) {
	line += " ";
	string key = "";
	bool separator = false;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			data.push_back(key);
			key = "";
			separator = false;
		} else {
			if (line[i] == ':') {
				separator = true;
			} else if (!separator) {
				key += line[i];
			}
		}
	}
}

bool is_valid(vector<string>& data) {
	set<string> needed {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
	for (int i = 0; i < data.size(); i++) {
		needed.erase(data[i]);
	}
	return !needed.size();
}

int main() {
	
	ifstream fin("4.in");
	ofstream fout("4_1.out");
	
	vector<string> data;
	int ans = 0;
	for (string line; getline(fin, line);) {
		if (line == "") {
			ans += is_valid(data);
			data.clear();
		} else {
			push_data_split(data, line);
			
		}
	}
	
	if (data.size()) {
		ans += is_valid(data);
	}
	
	fout << ans;
	
	return 0;
}