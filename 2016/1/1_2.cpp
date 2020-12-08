#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_2.out");
	string s;
	int x = 0, y = 0, direction = 0;
	set<pair<int, int>> visited;
	visited.insert({x, y});
	while (fin >> s) {
		if (s.back() == ',') {
			s.pop_back();
		}
		int blocks = stoi(s.substr(1, s.length()));
		if (s[0] == 'R') {
			direction = (direction + 1) % 4;
		} else {
			direction = (direction == 0 ? 3 : direction - 1) % 4;
		}
		if (direction == 0) {
			for (int i = 1; i <= blocks; i++) {
				if (visited.count({x, y + i})) {
					fout << abs(x) + abs(y + i);
					return 0;
				}
				visited.insert({x, y + i});
			}
			y += blocks;
		} else if (direction == 1) {
			for (int i = 1; i <= blocks; i++) {
				if (visited.count({x + i, y})) {
					fout << abs(x + i) + abs(y);
					return 0;
				}
				visited.insert({x + i, y});
			}
			x += blocks;
		} else if (direction == 2) {
			for (int i = 1; i <= blocks; i++) {
				if (visited.count({x, y - i})) {
					fout << abs(x) + abs(y - i);
					return 0;
				}
				visited.insert({x, y - i});
			}
			y -= blocks;
		} else if (direction == 3) {
			for (int i = 1; i <= blocks; i++) {
				if (visited.count({x - i, y})) {
					fout << abs(x - i) + abs(y);
					return 0;
				}
				visited.insert({x - i, y});
			}
			x -= blocks;
		}
	}
	
	return 0;
}