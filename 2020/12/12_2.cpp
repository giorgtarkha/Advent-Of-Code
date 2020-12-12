#include <bits/stdc++.h>

using namespace std;

void rotate(int& n, int& e, bool clockwise) {
	swap(n, e);
	if (clockwise) {
		n = -n;
	} else {
		e = -e;
	}
}

int main() {
	
	ifstream fin("12.in");
	ofstream fout("12_2.out");
	int n = 0, e = 0, w_n = 1, w_e = 10; 
	bool dn = true, de = true;
	string s;
	while (fin >> s) {
		int val = stoi(s.substr(1, s.length() - 1));
		if (s[0] == 'L') {
			val /= 90;
			val %= 4;
			while (val--) {
				rotate(w_n, w_e, false);
			}
		} else if (s[0] == 'R') {
			val /= 90;
			val %= 4;
			while (val--) {
				rotate(w_n, w_e, true);
			}
		} else if (s[0] == 'F') {
			n += val * w_n;
			e += val * w_e;
		} else if (s[0] == 'N') {
			w_n += val;
		} else if (s[0] == 'S') {
			w_n -= val;
		} else if (s[0] == 'E') {
			w_e += val;
		} else if (s[0] == 'W') {
			w_e -= val;
		}
	}
	fout << abs(n) + abs(e);
	
	return 0;
}