#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_1.out");
	
	vector<string> grid;
	string s;
	int n, m;
	while (fin >> s) {
		m = s.length();
		grid.push_back(s);
	}
	n = grid.size();
	pair<int, int> pos = {0, 0};
	int tree_count = 0;
	while (pos.first < n) {
		tree_count += grid[pos.first][pos.second] == '#';
		pos.first++;
		pos.second += 3;
		pos.second %= m;
	}
	fout << tree_count;
	
	return 0;
}