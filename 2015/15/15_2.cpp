#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("15.in");
	ofstream fout("15_2.out");
	
	string s;
	int counter = 0;
	vector<vector<int>> v;
	while (fin >> s) {
		if (counter == 2) {
			v.push_back({});
			s.pop_back();
			v.back().push_back(stoi(s));
		} else if (counter == 4) {
			s.pop_back();
			v.back().push_back(stoi(s));
		} else if (counter == 6) {
			s.pop_back();
			v.back().push_back(stoi(s));
		} else if (counter == 8) {
			s.pop_back();
			v.back().push_back(stoi(s));
		} else if (counter == 10) {
			v.back().push_back(stoi(s));
			counter = -1;
		}
		counter++;
	}
	
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				for (int l = 0; l <= 100; l++) {
					if (i + j + k + l == 100 &&
					    i * v[0][4] + j * v[1][4] + k * v[2][4] + l * v[3][4] == 500) {
						int capacity = max(0, i * v[0][0] + j * v[1][0] + k * v[2][0] + l * v[3][0]);
						int durability = max(0, i * v[0][1] + j * v[1][1] + k * v[2][1] + l * v[3][1]);
						int flavor = max(0, i * v[0][3] + j * v[1][2] + k * v[2][2] + l * v[3][2]);
						int texture = max(0, i * v[0][2] + j * v[1][3] + k * v[2][3] + l * v[3][3]);
						ans = max(ans, max(capacity, 1) * max(durability, 1) * max(flavor, 1) * max(texture, 1));
					}
				}
			}
		}
	}
	fout << ans;
	
	return 0;
}