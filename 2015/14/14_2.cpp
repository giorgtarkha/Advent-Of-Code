#include <bits/stdc++.h>

using namespace std;

int get_distance(int seconds, int fly_time, int rest_time, int speed) {
	int sum_time = fly_time + rest_time;
	int cycle_count = seconds / sum_time;
	int time_left = seconds % sum_time;
	return cycle_count * fly_time * speed + min(time_left, fly_time) * speed ;
}

int main() {
	
	ifstream fin("14.in");
	ofstream fout("14_2.out");
	
	int seconds = 2503;
	
	string s;
	int counter = 0;
	int fly_time, rest_time, speed;
	vector<vector<int>> distances;
	while (fin >> s) {
		if (counter == 3) {
			speed = stoi(s);
		} else if (counter == 6) {
			fly_time = stoi(s);
		} else if (counter == 13) {
			rest_time = stoi(s);
		} else if (counter == 14) {
			distances.push_back(vector<int>(seconds, 0));
			for (int i = 1; i <= seconds; i++) {
				distances.back()[i - 1] = get_distance(i, fly_time, rest_time, speed);
			}
			counter = -1;
		}
		counter++;
	}
	int ans = 0;
	vector<int> points(distances.size(), 0);
	for (int i = 0; i < seconds; i++) {
		int max_d = 0;
		for (int j = 0; j < distances.size(); j++) {
			max_d = max(max_d, distances[j][i]);
		}
		for (int j = 0; j < distances.size(); j++) {
			if (distances[j][i] == max_d) {
				points[j]++;
				ans = max(ans, points[j]);
			}
		}
	}
	fout << ans;
	
	return 0;
}