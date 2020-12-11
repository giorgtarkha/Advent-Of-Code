#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_2.out");
	int num;
	fin >> num;
	vector<vector<int>> grid(500, vector<int>(500, 0));
	int starti = 250, startj = 250;
	grid[starti][startj] = 1;
	bool going_right = true;
	bool going_up = false;
	bool going_down = false;
	bool going_left = false;
	while (grid[starti][startj] <= num) {
		if (starti == startj) {
			if (going_right) {
				startj++;
				going_up = true;
				going_right = false;
			} else if (going_left) {
				starti++;
				going_down = true;
				going_left = false;
			}
		} else if (abs(starti - 250) == abs(startj - 250)) {
			if (going_up) {
				startj--;
				going_left = true;
				going_up = false;
			} else if (going_down) {
				startj++;
				going_right = true;
				going_down = false;
			}
		} else {
			if (going_up) {
				starti--;
			} else if (going_down) {
				starti++;
			} else if (going_right) {
				startj++;
			} else {
				startj--;
			}
		}
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				grid[starti][startj] += grid[starti + i][startj + j];
			}
		}
	}
	fout << grid[starti][startj];
	
	return 0;
}