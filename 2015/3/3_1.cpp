#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_1.out");
	
	string s;
	fin >> s;
	int x = 0, y = 0;
	set<pair<int, int>> visited;
	visited.insert({0, 0});
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			x -= 1;
		} else if (s[i] == '>') {
			x += 1;
		} else if (s[i] == '^') {
			y += 1;
		} else if (s[i] == 'v') {
			y -= 1;
		}
		visited.insert({x, y});	
	}
	fout << visited.size();
	
	return 0;
}