#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_1.out");
	
	int ans = 0;
	for (string s; getline(fin, s);) {
		string current_num = "";
		int current_game;
		bool good = true;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				current_num += s[i];
				continue;
			}
			if (current_num != "") {
				if (s[i] == 'r' || s[i] == 'g' || s[i] == 'b') {
					int num = stoi(current_num);
					current_num = "";
					if ((s[i] == 'r' && num > 12) || (s[i] == 'g' && num > 13) || (s[i] == 'b' && num > 14)) {
						good = false;
						break;
					}
				} else if (s[i] == ':') {
					int num = stoi(current_num);
					current_num = "";
					current_game = num;
				}
			}
		}
		if (good) {
			ans += current_game;
		}
	}
	fout << ans << endl;
	
	return 0;
}
