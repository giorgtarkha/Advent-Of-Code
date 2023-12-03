#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	
	int ans = 0;
	string num = "00";
	string s;
	while (fin >> s) {
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				num[0] = s[i];
				break;
			}
		}
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] >= '0' && s[i] <= '9') {
				num[1] = s[i];
				break;
			}
		}
		ans += stoi(num);
	}
	fout << ans << endl;
	
	return 0;
}
