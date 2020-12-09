#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("8.in");
	ofstream fout("8_2.out");
	string s;
	char grid[6][50];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 50; j++) {
			grid[i][j] = '.';
		}
	}
	while (fin >> s) {
		if (s == "rect") {
			string dimensions;
			fin >> dimensions;
			string width = "";
			while (dimensions.front() != 'x') {
				width += dimensions.front();
				dimensions.erase(dimensions.begin());
			}
			dimensions.erase(dimensions.begin());
			int widthi = stoi(width), heighti = stoi(dimensions);
			for (int i = 0; i < heighti; i++) {
				for (int j = 0; j < widthi; j++) {
					grid[i][j] = '#';
				}
			}
		} else {
			fin >> s;
			fin >> s;
			if (s[0] == 'y') {
				s.erase(s.begin());
				s.erase(s.begin());
				int row = stoi(s);
				fin >> s;
				fin >> s;
				int distance = stoi(s);
				string curr = "";
				for (int i = 0; i < 50; i++) {
					curr += grid[row][i];
				}
				distance %= 50;
				curr = curr.substr(50 - distance, 50) + curr.substr(0, 50 - distance);
				for (int i = 0; i < 50; i++) {
					grid[row][i] = curr[i];
				}
			} else {
				s.erase(s.begin());
				s.erase(s.begin());
				int col = stoi(s);
				fin >> s;
				fin >> s;
				int distance = stoi(s);
				string curr = "";
				for (int i = 0; i < 6; i++) {
					curr += grid[i][col];
				}
				distance %= 6;
				curr = curr.substr(6 - distance, 6) + curr.substr(0, 6 - distance);
				for (int i = 0; i < 6; i++) {
					grid[i][col] = curr[i];
				}
			}
		}
	}
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 50; j++) {
			fout << grid[i][j];
		}
		fout << endl;
	}
	
	return 0;
}