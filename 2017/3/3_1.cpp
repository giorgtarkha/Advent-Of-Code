#include <bits/stdc++.h>

using namespace std;

pair<int, int> get_close(int increase, int square_num) {
	int start = 1;
	int steps = 0;
	while (start + increase <= square_num) {
		start += increase;
		increase += 8;
		steps++;
	}
	return {start, steps};
}

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_1.out");
	int square_num;
	fin >> square_num;
	
	vector<pair<pair<int, int>, char>> v {
		{get_close(1, square_num), 'r'},
		{get_close(3, square_num), 'u'},
		{get_close(5, square_num), 'l'},
		{get_close(7, square_num), 'd'},
	};
	
	pair<pair<int, int>, char> chosen = {{0, 0}, ' '};
	for (int i = 0; i < v.size(); i++) {
		if (abs(v[i].first.first - square_num) < abs(chosen.first.first - square_num)) {
			chosen = v[i];
		}
	}
	fout << chosen.first.second + abs(square_num - chosen.first.first);
	
	
	return 0;
}