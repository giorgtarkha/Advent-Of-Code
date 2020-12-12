#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("12.in");
	ofstream fout("12_1.out");
	int direction = 1, n = 0, e = 0;
	string s;
	while (fin >> s) {
		int val = stoi(s.substr(1, s.length() - 1));
		if (s[0] == 'L') {
			direction -= val / 90;
			direction %= 4;
			direction = direction < 0 ? 4 - abs(direction) : direction;
		} else if (s[0] == 'R') {
			direction += val / 90;
			direction %= 4;
		} else if (s[0] == 'F') {
			if (direction == 0) {
				n += val;
			} else if (direction == 1) {
				e += val;
			} else if (direction == 2) {
				n -= val;
			} else if (direction == 3) {
				e -= val;
			}
		} else if (s[0] == 'N') {
			n += val;
		} else if (s[0] == 'S') {
			n -= val;
		} else if (s[0] == 'E') {
			e += val;
		} else if (s[0] == 'W') {
			e -= val;
		}
	}
	fout << abs(n) + abs(e);
	
	return 0;
}