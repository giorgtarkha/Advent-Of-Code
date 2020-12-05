#include <bits/stdc++.h>

using namespace std;

int go(int n, int m, vector<string>& grid, int stepr, int stepd) {
	pair<int, int> pos = {0, 0};
	int tree_count = 0;
	while (pos.first < n) {
		tree_count += grid[pos.first][pos.second] == '#';
		pos.first += stepd;
		pos.second += stepr;
		pos.second %= m;
	}
	return tree_count;
}

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_2.out");
	
	vector<string> grid;
	string s;
	int n, m;
	while (fin >> s) {
		m = s.length();
		grid.push_back(s);
	}
	n = grid.size();
	long long ans = 1;
	ans *= go(n, m, grid, 1, 1);
	ans *= go(n, m, grid, 3, 1);
	ans *= go(n, m, grid, 5, 1);
	ans *= go(n, m, grid, 7, 1);
	ans *= go(n, m, grid, 1, 2);
	fout << ans;
	
	return 0;
}