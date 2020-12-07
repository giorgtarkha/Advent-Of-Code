#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("18.in");
	ofstream fout("18_2.out");
	string s;
	vector<string> grid;
	while (fin >> s) {
		grid.push_back(s);
	}
	grid[0][0] = '#';
	grid[0][grid[0].size() - 1] = '#';
	grid[grid.size() - 1][0] = '#';
	grid[grid.size() - 1][grid[grid.size() - 1].size() - 1] = '#';
	
	for (int i = 0; i < 100; i++) {
		vector<string> new_grid = grid;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				
				if (i == 0 && j == 0 ||
				    i == 0 && j == grid[0].size() - 1 ||
					i == grid.size() - 1 && j == 0 ||
					i == grid.size() - 1&& j == grid[grid.size() - 1].size() - 1) {
						continue;
					}
				
				int on_count = 0;
				for (int ofi = -1; ofi <= 1; ofi++) {
					for (int ofj = -1; ofj <= 1; ofj++) {
						if (!ofi && !ofj) {
							continue;
						}
						if (i + ofi >= 0 && i + ofi < grid.size() && j + ofj >= 0 && j + ofj < grid[i].size()) {
							on_count += grid[i + ofi][j + ofj] == '#';
						}
						if (grid[i][j] == '#') {
							if (on_count == 2 || on_count == 3) {
								new_grid[i][j] = '#';
							} else {
								new_grid[i][j] = '.';
							}
						} else {
							if (on_count == 3) {
								new_grid[i][j] = '#';
							} else {
								new_grid[i][j] = '.';
							}
						}
					}
				}
			}
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