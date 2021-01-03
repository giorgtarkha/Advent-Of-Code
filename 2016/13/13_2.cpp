#include <bits/stdc++.h>

using namespace std;

bool good(int x, int y, int num) {
	if (x < 0 || y < 0) {
		return false;
	}
	int sum = (x * x + 3 * x + 2 * x * y + y + y * y + num);
	int bcount = 0;
	while (sum) {
		bcount += sum & 1;
		sum >>= 1;
	}
	return (bcount % 2) ^ 1;
}

int main() {
	
	ofstream fout("13_2.out");
	int fn = 1358;
	queue<vector<int>> q;
	q.push({1, 1, 0});
	int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	set<pair<int, int>> visited;
	visited.insert({1, 1});
	while (!q.empty()) {
		vector<int> curr = q.front();
		q.pop();
		int x = curr[0], y = curr[1];
		if (curr[2] == 50) {
			continue;
		}
		
		for (int i = 0; i < 4; i++) {
			if (good(x + offsets[i][0], y + offsets[i][1], fn) && !visited.count({x + offsets[i][0], y + offsets[i][1]})) {
				visited.insert({x + offsets[i][0], y + offsets[i][1]});
				q.push({x + offsets[i][0], y + offsets[i][1], curr[2] + 1});
			}
		}
	}
	fout << visited.size();
	
	return 0;
}