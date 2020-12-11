#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("11.in");
	ofstream fout("11_1.out");
	string s;
	vector<string> grid;
	while (fin >> s) {
		grid.push_back(s);
	}
	
	while (true) {
		bool changed = false;
		vector<string> new_grid = grid;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				int count = 0;
				for (int oi = -1; oi <= 1; oi++) {
					for (int oj = -1; oj <= 1; oj++) {
						if (oi == 0 && oj == 0) {
							continue;
						}
						if (i + oi >= 0 && i + oi < grid.size() && j + oj >= 0 && j + oj < grid[i].size()) {
							count += grid[i + oi][j + oj] == '#';
						}
					}
				}
				if (grid[i][j] == 'L' && count == 0) {
					new_grid[i][j] = '#';
					changed = true;
				} else if (grid[i][j] == '#' && count >= 4) {
					new_grid[i][j] = 'L';
					changed = true;
				}
			}
		}
		if (!changed) {
			break;
		}
		grid = new_grid;
	}
	
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			ans += grid[i][j] == '#';
		}
	}
	fout << ans;
	
	return 0;
}