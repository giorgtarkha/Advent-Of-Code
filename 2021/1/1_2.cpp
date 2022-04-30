#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_2.out");
	
	vector<int> window(3, 0);
	int x, ans = 0;
	for (int i = 0; i < 3; i++) {
		fin >> window[i];
	}
	while (fin >> x) {
		if (window[0] < x) {
			ans++;
		}
		window[0] = window[1];
		window[1] = window[2];
		window[2] = x;
	}
	fout << ans << endl;
	
	return 0;
}