#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("4.in");
	ofstream fout("4_2.out");
	
	map<int, long long> factor;
	int ci = 0;
	for (string s; getline(fin, s);) {
		factor[ci]++;
		s += " ";
		int i = 0;
		while (s[i++] != ':');
		string curr_num = "";
		set<int> nums;
		while (s[i] != '|') {
			if (s[i] >= '0' && s[i] <= '9') {
				curr_num += s[i++];
				continue;
			}
			if (curr_num != "") {
				nums.insert(stoi(curr_num));
				curr_num = "";
			}
			i++;
		}
		curr_num = "";
		int count = 0;
		while (i < s.length()) {
			if (s[i] >= '0' && s[i] <= '9') {
				curr_num += s[i++];
				continue;
			}
			if (curr_num != "") {
				if (nums.count(stoi(curr_num))) {
					count++;
				}
				curr_num = "";
			}
			i++;
		}
		if (count) {
			for (int j = 1; j <= count; ++j) {
				factor[ci + j] += factor[ci];
			}
		}
		++ci;
	}
	
	long long ans = 0;
	for (auto it = factor.begin(); it != factor.end(); ++it) {
		ans += it->second;
	}
	fout << ans << endl;
	
	return 0;
}
