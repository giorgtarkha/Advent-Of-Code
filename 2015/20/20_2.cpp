#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("20.in");
	ofstream fout("20_2.out");
	int n;
	fin >> n;
	
	vector<vector<int>> factors(1000001);
	map<int, int> count;
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; j * j <= 1000000; j++) {
			if (i % j == 0) {
				if (count[j] < 50) {
					factors[i].push_back(j);
					count[j]++;
				}
				if (i / j != j) {
					if (count[i / j] < 50) {
						factors[i].push_back(i / j);
						count[i / j]++;
					}
				}
			}
		}
	}
	
	for (int i = 1;; i++) {
		int sum = 0;
		for (int j = 0; j < factors[i].size(); j++) {
			sum += factors[i][j] * 11;
		}
		if (sum >= n) {
			fout << i;
			break;
		}
	}
	
	return 0;
}