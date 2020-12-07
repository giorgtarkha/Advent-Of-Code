#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("17.in");
	ofstream fout("17_2.out");
	int n;
	vector<int> v;
	while (fin >> n) {
		v.push_back(n);
	}
	
	int ans = 0;
	int ans_count[v.size()] = {0};
	for (int i = 0; i < (1 << v.size()); i++) {
		int sum = 0;
		int bit_count = 0;
		for (int j = 0; j < v.size(); j++) {
			if ((i >> j) & 1) {
				sum += v[j];
				bit_count++;
			}
		}
		if (sum == 150) {
			ans += 150;
			ans_count[bit_count]++;
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		if (ans_count[i]) {
			fout << ans_count[i];
			break;
		}
	}
	
	return 0;
}