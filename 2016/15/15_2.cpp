#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("15.in");
	ofstream fout("15_2.out");
	string input[12];
	vector<pair<int, int>> v;
	while (fin >> input[0]) {
		for (int i = 1; i < 12; i++) {
			fin >> input[i];
		}
		int positions = stoi(input[3]), position = stoi(input[11].substr(0, input[11].length() - 1));
		v.push_back({position, positions});
	}
	v.push_back({0, 11});
	
	int time = 0;
	while (true) {
		bool found = true;
		for (int i = 0; i < v.size(); i++) {
			if ((v[i].first + time + i + 1) % v[i].second) {
				found = false;
				break;
			}
		}
		if (found) {
			break;
		}
		time++;
	}
	fout << time;
	
	return 0;
}