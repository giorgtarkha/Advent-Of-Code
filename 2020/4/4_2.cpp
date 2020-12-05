#include <bits/stdc++.h>

using namespace std;

void push_data_split(vector<pair<string, string>>& data, string& line) {
	line += " ";
	string key = "";
	string value = "";
	bool separator = false;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			data.push_back({ key, value });
			key = "";
			value = "";
			separator = false;
		} else {
			if (line[i] == ':') {
				separator = true;
			} else {
				if (!separator) {
					key += line[i];
				} else {
					value += line[i];
				}
			}
		}
	}
}

bool is_valid(vector<pair<string, string>>& data) {
	set<string> needed {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
	for (int i = 0; i < data.size(); i++) {
		needed.erase(data[i].first);
		if (data[i].first == "byr") {
			int byr = stoi(data[i].second);
			if (byr < 1920 || byr > 2002) {
				return false;
			}
		} else if (data[i].first == "iyr") {
			int iyr = stoi(data[i].second);
			if (iyr < 2010 || iyr > 2020) {
				return false;
			}
		} else if (data[i].first == "eyr") {
			int eyr = stoi(data[i].second);
			if (eyr < 2020 || eyr > 2030) {
				return false;
			}
		} else if (data[i].first == "hgt") {
			if (data[i].second.length() < 3) {
				return false;
			}
			int height = stoi(data[i].second.substr(0, data[i].second.length() - 2));
			if (data[i].second.back() == 'm') {
				if (height < 150 || height > 193) {
					return false;
				}
			} else {
				if (height < 59 || height > 76) {
					return false;
				}
			}
		} else if (data[i].first == "hcl") {
			if (data[i].second[0] != '#'|| data[i].second.length() != 7) {
				return false;
			}
			for (int j = 1; j <= 6; j++) {
				if (!(data[i].second[j] >= '0' && data[i].second[j] <= '9') &&
				    !(data[i].second[j] >= 'a' && data[i].second[j] <= 'f')) {
						return false;
					}
			}
		} else if (data[i].first == "ecl") {
			if (data[i].second != "amb" && data[i].second != "blu" && data[i].second != "brn" &&
			    data[i].second != "gry" && data[i].second != "grn" && data[i].second != "hzl" && 
				data[i].second != "oth") {
					return false;
				}
		} else if (data[i].first == "pid") {
			if (data[i].second.length() != 9) {
				return false;
			}
			for (int j = 0; j < 9; j++) {
				if (data[i].second[j] < '0' && data[i].second[j] > '9') {
					return false;
				}
			}
		}
	}
	return !needed.size();
}

int main() {
	
	ifstream fin("4.in");
	ofstream fout("4_2.out");
	
	vector<pair<string, string>> data;
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