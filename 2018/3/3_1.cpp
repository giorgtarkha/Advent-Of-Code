#include <bits/stdc++.h>

using namespace std;

int grid[1005][1005];
int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_1.out");
	string s;
	while (fin >> s) {
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
				grid[i][j]++;
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			ans += grid[i][j] >= 2;
		}
	}
	fout << ans;
	
	return 0;
}