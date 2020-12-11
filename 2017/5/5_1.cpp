#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("5.in");
	ofstream fout("5_1.out");
	vector<int> instructions;
	int x;
	while (fin >> x) {
		instructions.push_back(x);
	}
	
	int index = 0;
	int ans = 1;
	while (true) {
		if (index + instructions[index] < 0 || index + instructions[index] >= instructions.size()) {
			break;
		}
		int val = instructions[index];
		instructions[index]++;
		index += val;
		ans++;
	}
	fout << ans;
	
	return 0;
}