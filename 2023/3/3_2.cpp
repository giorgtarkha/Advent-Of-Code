#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_2.out");
	
	string s;
	vector<string> g;
	while (fin >> s) {
		g.emplace_back(s);
	}
	
	map<string, vector<long long>> mp;
	for (int i = 0; i < g.size(); ++i) {
		for (int j = 0; j < g[i].length();) {
			if (g[i][j] < '0' || g[i][j] > '9') {
				++j;
				continue;				
			}
			string curr_num = "";
			int cn_start = j, cn_end = j;
			while(cn_end < g[i].length() && g[i][cn_end] >= '0' && g[i][cn_end] <= '9') {
				curr_num += g[i][cn_end++];
			}
			int num = stoi(curr_num);
			bool good = false;
			for (int jdx = cn_start; jdx < cn_end; ++jdx) {
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						if (i + di >= 0 && i + di < g.size() && jdx + dj >= 0 && jdx + dj < g[i].length()) {
							char c = g[i + di][jdx + dj];
							if ((c < '0' || c > '9') && c != '.') {
								if (c == '*') {
									mp["" + to_string(i + di) + ";" + to_string(jdx + dj)].emplace_back((long long) num);
								}
								good = true;
								break;
							}
						}
					}
					if (good) {
						break;
					}
				}
				if (good) {
					break;
				}
			}
			j = cn_end;
		}
	}
	
	long long ans = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->second.size() == 2) {
			ans += it->second[0] * it->second[1];
		}
	}
	fout << ans << endl;
	
	return 0;
}
