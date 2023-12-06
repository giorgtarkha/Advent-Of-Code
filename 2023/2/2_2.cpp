#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_2.out");
	
	unsigned long long ans = 0;
	for (string s; getline(fin, s);) {
		string current_num = "";
		int r_min = 0, g_min = 0, b_min = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				current_num += s[i];
				continue;
			}
			if (current_num != "") {
				if (s[i] == 'r' || s[i] == 'g' || s[i] == 'b') {
					int num = stoi(current_num);
					current_num = "";
					r_min = max(r_min, s[i] == 'r' ? num : r_min);
					g_min = max(g_min, s[i] == 'g' ? num : g_min);
					b_min = max(b_min, s[i] == 'b' ? num : b_min);
				} else if (s[i] == ':') {
					current_num = "";
				}
			}
		}
		ans += (long long) r_min * g_min * b_min;
	}
	fout << ans << endl;
	
	return 0;
}
