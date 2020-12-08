#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_1.out");
	int a, b, c, ans = 0;
	while (fin >> a >> b >> c) {
		ans += a + b > c && b + c > a && a + c > b;
	}
	fout << ans;
	
	return 0;
}