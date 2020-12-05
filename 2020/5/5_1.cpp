#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("5.in");
	ofstream fout("5_1.out");
	
	string s;
	int ans = 0;
	while (fin >> s) {
		int low = 0, high = 127;
		int counter = 0;
		while (counter < 7) {
			int mid = (low + high) / 2;
			if (s[counter] == 'F') {
				high = mid;
			} else {
				low = mid + 1;
			}
			counter++;
		}
		
		int counter_c = 0;
		int low_c = 0, high_c = 7;
		while (counter_c < 3) {
			int mid = (low_c + high_c) / 2;
			if (s[7 + counter_c] == 'L') {
				high_c = mid;
			} else {
				low_c = mid + 1;
			}
			counter_c++;
		}
		
		ans = max(ans, low * 8 + low_c);
	}
	
	fout << ans;
	
	return 0;
}