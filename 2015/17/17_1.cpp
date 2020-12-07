#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("17.in");
	ofstream fout("17_1.out");
	int n;
	vector<int> v;
	while (fin >> n) {
		v.push_back(n);
	}
	
	int ans = 0;
	for (int i = 0; i < (1 << v.size()); i++) {
		int sum = 0;
		for (int j = 0; j < v.size(); j++) {
			if ((i >> j) & 1) {
				sum += v[j];
			}
		}
		ans += sum == 150;
	}
	fout << ans;
	
	return 0;
}