#include <bits/stdc++.h>

using namespace std;

void go(long long n, int index, string& mask, map<long long, long long>& mp, long long val) {
	if (index == mask.length()) {
		mp[n] = val;
		return;
	}
	int mask_index = 35 - index;
	if (mask[mask_index] == '0') {
		go(n, index + 1, mask, mp, val);
	} else if (mask[mask_index] == '1') {
		go(n | (1ll << index), index + 1, mask, mp, val);
	} else {
		go(n & ~(1ll << index), index + 1, mask, mp, val);
		go(n | (1ll << index), index + 1, mask, mp, val);
	}
}

int main() {
	
	ifstream fin("14.in");
	ofstream fout("14_2.out");
	string input[3];
	string mask;
	map<long long, long long> mp; 
	while (fin >> input[0] >> input[1] >> input[2]) {
		if (input[0] == "mask") {
			mask = input[2];
		} else {
			string address = "";
			int index = 0;
			for (; input[0][index] != '['; index++);
			index++;
			for (; input[0][index] != ']'; index++) {
				address += input[0][index];
			}
			go(stol(address), 0, mask, mp, stol(input[2]));
		}
	}
	
	long long ans = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		ans += it->second;
	}
	fout << ans;
	
	return 0;
}