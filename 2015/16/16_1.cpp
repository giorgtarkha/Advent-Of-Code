#include <bits/stdc++.h>

using namespace std;

void parse_data(string& input, vector<map<string, int>>& data) {
	map<string, int> parsed;
	int index = 0;
	while (input[index] != ':') {
		index++;
	}
	index += 2;
	string key = "";
	string value = "";
	bool have_key = false;
	for (int i = index; i < input.length(); i++) {
		if (input[i] == ':') {
			have_key = true;
			i++;
			continue;
		}
		if (input[i] == ',') {
			parsed[key] = stoi(value);
			key = "";
			value = "";
			have_key = false;
			i++;
			continue;
		}
		if (!have_key) {
			key += input[i];
		} else {
			value += input[i];
		}
	}
	data.push_back(parsed);
}

int main() {
	
	ifstream fin("16.in");
	ofstream fout("16_1.out");
	vector<map<string, int>> data;
	for (string line; getline(fin, line);) {
		parse_data(line, data);
	}
	
	map<string, int> tape;
	tape["children"] = 3;
	tape["cats"] = 7;
	tape["samoyeds"] = 2;
	tape["pomeranians"] = 3;
	tape["akitas"] = 0;
	tape["vizslas"] = 0;
	tape["goldfish"] = 5;
	tape["trees"] = 3;
	tape["cars"] = 2;
	tape["perfumes"] = 1;
	
	for (int i = 0; i < data.size(); i++) {
		bool good = true;
		for (auto it = data[i].begin(); it != data[i].end(); ++it) {
			if (tape[it->first] != it->second) {
				good = false;
				break;
			}
		}
		if (good) {
			fout << i + 1;
			break;
		}
	}
	
	return 0;
}