#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_2.out");
	
	vector<string> ids;
	string s;
	while (fin >> s) {
		ids.push_back(s);
	}
	
	for (int i = 0; i < ids.size() - 1; i++) {
		for (int j = i + 1; j < ids.size(); j++) {
			string ans = "";
			for (int k = 0; k < ids[i].length(); k++) {
				if (ids[i][k] == ids[j][k]) {
					ans += ids[i][k];
				}
			}
			if (ans.length() == ids[i].length() - 1) {
				fout << ans;
				return 0;
			}
		}
	}
	
	return 0;
}