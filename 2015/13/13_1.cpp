#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("13.in");
	ofstream fout("13_1.out");
	string s[11];
	map<string, int> mapping;
	vector<vector<int>> adj;
	int curr = 0;
	while (fin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6] >> s[7] >> s[8] >> s[9] >> s[10]) {
		s[10].pop_back();
		if (!mapping.count(s[0])) {
			mapping[s[0]] = curr;
			curr++;
			adj.push_back({});
		}
		if (!mapping.count(s[10])) {
			mapping[s[10]] = curr;
			curr++;
			adj.push_back({});
		}
		int index = mapping[s[0]];
		int target = mapping[s[10]];
		if (adj[index].size() <= target) {
			adj[index].resize(target + 1);
		}
		adj[index][target] = s[2] == "gain" ? stoi(s[3]) : -stoi(s[3]);
	}
	
	string permutation = "";
	for (int i = 0; i < adj.size(); i++) {
		permutation += '0' + i;
	}
	int ans = 2 << 30;
	do {
		int gain = 0;
		for (int i = 1; i < permutation.length() - 1; i++) {
			gain += adj[permutation[i] - '0'][permutation[i + 1] - '0'];
			gain += adj[permutation[i] - '0'][permutation[i - 1] - '0'];
		}
		gain += adj[permutation[0] - '0'][permutation[1] - '0'];
		gain += adj[permutation[0] - '0'][permutation.back() - '0'];
		gain += adj[permutation.back() - '0'][permutation[permutation.length() - 2] - '0'];
		gain += adj[permutation.back() - '0'][permutation[0] - '0'];
		ans = max(gain, ans);
	} while (next_permutation(permutation.begin(), permutation.end()));
	fout << ans;
	
	return 0;
}