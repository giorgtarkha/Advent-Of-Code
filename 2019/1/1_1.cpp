#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	int ans = 0;
	int x;
	while (fin >> x) {
		ans += x / 3 - 2;
	}
	fout << ans;
	
	return 0;
}