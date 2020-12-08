#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	string s;
	int x = 0, y = 0, direction = 0;
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
			y += blocks;
		} else if (direction == 1) {
			x += blocks;
		} else if (direction == 2) {
			y -= blocks;
		} else if (direction == 3) {
			x -= blocks;
		}
	}
	fout << abs(x) + abs(y);
	
	return 0;
}