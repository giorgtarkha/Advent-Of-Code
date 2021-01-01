#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("14.in");
	ofstream fout("14_1.out");
	string input[3];
	vector<pair<int, bool>> mask;
	map<string, long long> mp; 
	while (fin >> input[0] >> input[1] >> input[2]) {
		if (input[0] == "mask") {
			mask.clear();
			for (int i = 0; i < input[2].length(); i++) {
				if (input[2][i] != 'X') {
					mask.push_back({35 - i, input[2][i] - '0'});
				}
			}
		} else {
			string address = "";
			int index = 0;
			for (; input[0][index] != '['; index++);
			index++;
			for (; input[0][index] != ']'; index++) {
				address += input[0][index];
			}
			long long value = stol(input[2]);
			for (int i = 0; i < mask.size(); i++) {
				value ^= (-mask[i].second ^ value) & (1ll << mask[i].first);
			}
			mp[address] = value;
		}
	}
	
	long long ans = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		ans += it->second;
	}
	fout << ans;
	
	return 0;
}