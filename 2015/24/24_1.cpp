#include <bits/stdc++.h>

using namespace std;

long long get_mult(vector<int>& v) {
	long long m = 1;
	for (int i = 0; i < v.size(); i++) {
		m *= v[i];
	}
	return m;
}

void set_ans(pair<int, long long>& ans, vector<int>& v) {
	if (v.size() < ans.first) {
		ans.first = v.size();
		ans.second = get_mult(v);
	} else if (v.size() == ans.first) {
		ans.second = min(ans.second, get_mult(v));
	}
}

int main() {
	
	ifstream fin("24.in");
	ofstream fout("24_1.out");
	int w;
	vector<int> weights;
	int sum = 0;
	while (fin >> w) {
		weights.push_back(w);
		sum += w;
	}
	int target = sum / 3;
	
	pair<int, long long> ans{100000, 1 << 29};
	for (int i = 1; i < weights.size(); i++) {
		string combination = string(weights.size() - i, '0') + string(i, '1');
		do {
			int current_sum = 0;
			vector<int> current_v;
			for (int j = 0; j < combination.length(); j++) {
				if (combination[j] == '1') {
					current_sum += weights[j];
					current_v.push_back(weights[j]);
				}
			}
			if (current_sum == target) {
				set_ans(ans, current_v);
			}
		} while (next_permutation(combination.begin(), combination.end()));
		if (ans.first < 100000) {
			break;
		}
	}
	fout << ans.second;
	
	return 0;
}