#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_2.out");
	string s;
	int r = 2, c = 0;
	char grid[][5] = {
		{'0', '0', '1', '0', '0'},
		{'0', '2', '3', '4', '0'},
		{'5', '6', '7', '8', '9'},
		{'0', 'A', 'B', 'C', '0'},
		{'0', '0', 'D', '0', '0'}
	};
	string ans = "";
	while (fin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'U') {
				r = max(r - 1, 0); 
				if (grid[r][c] == '0') {
					r++;
				}
			} else if (s[i] == 'D') {
				r = min(r + 1, 4);
				if (grid[r][c] == '0') {
					r--;
				}
			} else if (s[i] == 'L') {
				c = max(c - 1, 0);
				if (grid[r][c] == '0') {
					c++;
				}
			} else {
				c = min(c + 1, 4);
				if (grid[r][c] == '0') {
					c--;
				}
			}
		}
		ans += grid[r][c];
	}
	fout << ans;
	
	return 0;
}