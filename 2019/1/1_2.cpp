#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_2.out");
	int ans = 0;
	int x;
	while (fin >> x) {
		while (x > 0) {
			x /= 3;
			x -= min(2, x);
			ans += x;
		}
	}
	fout << ans;
	
	return 0;
}