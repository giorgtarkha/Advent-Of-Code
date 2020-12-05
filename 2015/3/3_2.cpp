#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_2.out");
	
	string s;
	fin >> s;
	int santa_x = 0, santa_y = 0, robo_x = 0, robo_y = 0;
	set<pair<int, int>> visited;
	visited.insert({0, 0});
	for (int i = 0; i < s.length(); i++) {
		int offset_x = 0, offset_y = 0;
		if (s[i] == '<') {
			offset_x = -1;
		} else if (s[i] == '>') {
			offset_x = 1;
		} else if (s[i] == '^') {
			offset_y = 1;
		} else if (s[i] == 'v') {
			offset_y = -1;
		}
		if (i % 2) {
			robo_x += offset_x;
			robo_y += offset_y;
			visited.insert({robo_x, robo_y});	
		} else {
			santa_x += offset_x;
			santa_y += offset_y;
			visited.insert({santa_x, santa_y});	
		}
	}
	fout << visited.size();
	
	return 0;
}