#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("9.in");
	ofstream fout("9_1.out");
	long long n;
	vector<long long> v;
	while (fin >> n) {
		if (v.size() == 25) {
			bool can_sum_up = false;
			for (int i = 0; i < 24; i++) {
				for (int j = i + 1; j < 25; j++) {
					if (v[i] + v[j] == n) {
						can_sum_up = true;
					}
				}
			}
			if (!can_sum_up) {
				fout << n;
				return 0;
			}
			v.erase(v.begin());
		}
		v.push_back(n);
	}
	
	
	return 0;
}