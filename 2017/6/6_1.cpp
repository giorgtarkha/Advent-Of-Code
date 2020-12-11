#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("6.in");
	ofstream fout("6_1.out");
	int x;
	vector<int> v;
	while (fin >> x) {
		v.push_back(x);
	}
	
	set<vector<int>> occured;
	do {
		occured.insert(v);
		int max_v = 0;
		for (int i = 0; i < v.size(); i++) {
			max_v = max(max_v, v[i]);
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == max_v) {
				int j = i;
				v[j] = 0;
				while (max_v) {
					j++;
					if (j == v.size()) {
						j = 0;
					}
					v[j]++;
					max_v--;
				}
				break;
			}
		}
	} while (!occured.count(v));
	fout << occured.size();
	
	
	return 0;
}