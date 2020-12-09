#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("9.in");
	ofstream fout("9_2.out");
	long long n;
	vector<long long> v;
	long long invalid_num = 0;
	while (fin >> n) {
		if (v.size() >= 25) {
			bool can_sum_up = false;
			for (int i = 0; i < 24; i++) {
				for (int j = i + 1; j < 25; j++) {
					if (v[v.size() + i - 25] + v[v.size() + j - 25] == n) {
						can_sum_up = true;
					}
				}
			}
			if (!can_sum_up && invalid_num == 0) {
				invalid_num = n;
			}
		}
		v.push_back(n);
	}
	
	for (int i = 0; i < v.size() - 1; i++) {
		long long sum = 0;
		long long min_v = 1ll << 60;
		long long max_v = 0;
		for (int j = i; j < v.size(); j++) {
			min_v = min(min_v, v[j]);
			max_v = max(max_v, v[j]);
			sum += v[j];
			if (sum > invalid_num) {
				break;
			} else if (sum == invalid_num) {
				if (j - i >= 1) {
					fout << min_v + max_v;
					return 0;
				}
			}
		}
	}
	
	
	return 0;
}