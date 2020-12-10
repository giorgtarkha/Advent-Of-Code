#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("10.in");
	ofstream fout("10_1.out");
	int n;
	vector<int> v;
	while (fin >> n) {
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	v.insert(v.begin(), 0);
	v.push_back(v.back() + 3);
	int three_differences = 0, one_differences = 0;
	for (int i = 1; i < v.size(); i++) {
		three_differences += v[i] - v[i - 1] == 3;
		one_differences += v[i] - v[i - 1] == 1;
	}
	fout << three_differences * one_differences;
	
	return 0;
}