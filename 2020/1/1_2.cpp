#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_2.out");
	
	set<int> singles;
	map<int, pair<int, int>> twos;
	int n;
	while (fin >> n) {
		if (twos.count(2020 - n)) {
			fout << twos[2020 - n].first * twos[2020 - n].second * n;
			break;
		}
		for (auto it = singles.begin(); it != singles.end(); ++it) {
			twos[*it + n] = {*it, n};
		}
		singles.insert(n);
	}
	
	return 0;
}