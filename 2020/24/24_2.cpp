#include <bits/stdc++.h>

using namespace std;

void go(set<pair<double, double>>& black_tiles) {
	set<pair<double, double>> white_tiles;
	for (auto it = black_tiles.begin(); it != black_tiles.end(); ++it) {
		for (double x = -0.5; x <= 0.5; x += 1) {
			for (double y = -0.5; y <= 0.5; y += 1) {
				if (!black_tiles.count({it->first + x, it->second + y})) {
					white_tiles.insert({it->first + x, it->second + y});
				}
			}
		}
		if (!black_tiles.count({it->first + 1, it->second})) {
			white_tiles.insert({it->first + 1, it->second});
		}
		if (!black_tiles.count({it->first - 1, it->second})) {
			white_tiles.insert({it->first - 1, it->second});
		}
	}		
	
	set<pair<double, double>> white_to_black, black_to_white;
	for (auto it = black_tiles.begin(); it != black_tiles.end(); ++it) {
		int adj = 0;
		for (double x = -0.5; x <= 0.5; x += 1) {
			for (double y = -0.5; y <= 0.5; y += 1) {
				if (black_tiles.count({it->first + x, it->second + y})) {
					adj++;
				}
			}
		}
		if (black_tiles.count({it->first + 1, it->second})) {
			adj++;
		}
		if (black_tiles.count({it->first - 1, it->second})) {
			adj++;
		}
		if (adj == 0 || adj > 2) {
			black_to_white.insert(*it);
		}
	}
	
	for (auto it = white_tiles.begin(); it != white_tiles.end(); ++it) {
		int adj = 0;
		for (double x = -0.5; x <= 0.5; x += 1) {
			for (double y = -0.5; y <= 0.5; y += 1) {
				if (black_tiles.count({it->first + x, it->second + y})) {
					adj++;
				}
			}
		}
		if (black_tiles.count({it->first + 1, it->second})) {
			adj++;
		}
		if (black_tiles.count({it->first - 1, it->second})) {
			adj++;
		}
		if (adj == 2) {
			white_to_black.insert(*it);
		}
	}
	
	for (auto it = black_to_white.begin(); it != black_to_white.end(); ++it) {
		black_tiles.erase(*it);
	}
	
	for (auto it = white_to_black.begin(); it != white_to_black.end(); ++it) {
		black_tiles.insert(*it);
	}
}

int main() {
	
	ifstream fin("24.in");
	ofstream fout("24_2.out");
	
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
	
	for (int i = 0; i < 100; i++) {
		go(black_tiles);
	}
	fout << black_tiles.size();
	
	return 0;
}