#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("10.in");
	ofstream fout("10_2.out");
	int n;
	vector<int> v;
	int max_v = 0;
	while (fin >> n) {
		v.push_back(n);
		max_v = max(max_v, n);
	}
	bool have[max_v + 4] = {false};
	unsigned long long dp[max_v + 4] = {0};
	have[0] = true;
	have[max_v + 3] = true;
	for (int i = 0; i < v.size(); i++) {
		have[v[i]] = true;
	}
	dp[0] = 1;
	for (int i = 1; i < max_v + 4; i++) {
		if (have[i]) {
			dp[i] += dp[i - 1];
			dp[i] += i - 2 >= 0 ? dp[i - 2] : 0; 
			dp[i] += i - 3 >= 0 ? dp[i - 3] : 0;
		}
	}
	fout << dp[max_v + 3];
	
	return 0;
}