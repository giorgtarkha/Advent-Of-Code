#include <bits/stdc++.h>

using namespace std;

vector<string> grid[1005][1005];
int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_2.out");
	string s;
	vector<vector<int>> v;
	while (fin >> s) {
		string id = s;
		fin >> s >> s;
		string curr = "";
		while (s.front() != ',') {
			curr += s.front();
			s.erase(s.begin());
		}
		s.erase(s.begin());
		int startj = stoi(curr);
		curr = "";
		while (s.front() != ':') {
			curr += s.front();
			s.erase(s.begin());
		}
		int starti = stoi(curr);
		
		fin >> s;
		curr = "";
		while (s.front() != 'x') {
			curr += s.front();
			s.erase(s.begin());
		}
		s.erase(s.begin());
		int w = stoi(curr), h = stoi(s);
		for (int i = starti; i < starti + h; i++) {
			for (int j = startj; j < startj + w; j++) {
				grid[i][j].push_back(id);
			}
		}
		v.push_back({starti, startj, w, h});
	}
	
	for (int i = 0; i < v.size(); i++) {
		int starti = v[i][0], startj = v[i][1], w = v[i][2], h = v[i][3];
		bool unique = true;
		for (int x = starti; x < starti + h; x++) {
			for (int y = startj; y < startj + w; y++) {
				if (grid[x][y].size() > 1) {
					unique = false;
				}
			}
		}
		if (unique) {
			fout << grid[starti][startj][0].substr(1, grid[starti][startj][0].length() - 1);
			break;
		}
	}
	
	return 0;
}