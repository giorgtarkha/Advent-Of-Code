#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_1.out");
	int two_count = 0, three_count = 0;
	string s;
	while (fin >> s) {
		int counts[26] = {0};
		for (int i = 0; i < s.length(); i++) {
			counts[s[i] - 'a']++;
		}
		bool two_count_curr = false, three_count_curr = false;
		for (int i = 0; i < 26; i++) {
			two_count_curr |= counts[i] == 2;
			three_count_curr |= counts[i] == 3;
		}
		two_count += two_count_curr;
		three_count += three_count_curr;
	}
	fout << two_count * three_count;
	
	return 0;
}