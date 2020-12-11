#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("6.in");
	ofstream fout("6_2.out");
	int x;
	vector<int> v;
	while (fin >> x) {
		v.push_back(x);
	}
	
	map<vector<int>, int> occured;
	int steps = 0;
	do {
		occured[v] = steps;
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
		steps++;
	} while (!occured.count(v));
	fout << steps - occured[v];
	
	
	return 0;
}