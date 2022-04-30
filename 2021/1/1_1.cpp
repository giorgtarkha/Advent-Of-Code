#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	
	int prev = -1;
	int x, ans = 0;
	while (fin >> x) {
		if (prev == -1) {
			prev = x;
		} else {
			ans += x > prev;
			prev = x;
		}
	}
	fout << ans << endl;
	
	return 0;
}