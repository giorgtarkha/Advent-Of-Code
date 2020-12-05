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
	ofstream fout("14_1.out");
	
	int seconds = 2503;
	int ans = 0;
	string s;
	int counter = 0;
	int fly_time, rest_time, speed;
	while (fin >> s) {
		if (counter == 3) {
			speed = stoi(s);
		} else if (counter == 6) {
			fly_time = stoi(s);
		} else if (counter == 13) {
			rest_time = stoi(s);
		} else if (counter == 14) {
			ans = max(ans, get_distance(seconds, fly_time, rest_time, speed));
			counter = -1;
		}
		counter++;
	}
	fout << ans;
	
	return 0;
}