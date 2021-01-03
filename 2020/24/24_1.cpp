#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("24.in");
	ofstream fout("24_1.out");
	
	string s;
	set<pair<double, double>> black_tiles;
	while (fin >> s) {
		double x = 0, y = 0;
		for (int i = 0; i < s.length();) {
			if (s[i] ==  'e') {
				x++;
				i++;
			} else if (s[i] == 'w') {
				x--;
				i++;
			} else {
				if (s[i] == 's') {
					y -= 0.5;
				} else {
					y += 0.5;
				}
				if (s[i + 1] == 'e') {
					x += 0.5;
				} else {
					x -= 0.5;
				}
				i += 2;
			}
		}
		if (black_tiles.count({x, y})) {
			black_tiles.erase({x, y});
		} else {
			black_tiles.insert({x, y});
		}
	}
	fout << black_tiles.size();
	
	return 0;
}