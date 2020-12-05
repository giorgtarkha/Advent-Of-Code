#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("5.in");
	ofstream fout("5_2.out");
	
	string s;
	vector<int> seats;
	while (fin >> s) {
		int low = 0, high = 127;
		int counter = 0;
		while (counter < 7) {
			int mid = (low + high) / 2;
			if (s[counter] == 'F') {
				high = mid;
			} else {
				low = mid + 1;
			}
			counter++;
		}
		
		int counter_c = 0;
		int low_c = 0, high_c = 7;
		while (counter_c < 3) {
			int mid = (low_c + high_c) / 2;
			if (s[7 + counter_c] == 'L') {
				high_c = mid;
			} else {
				low_c = mid + 1;
			}
			counter_c++;
		}
		
		seats.push_back(low * 8 + low_c);
	}
	
	sort(seats.begin(), seats.end());
	for (int i = 1; i < seats.size(); i++) {
		if (seats[i - 1] + 1 == seats[i] - 1) {
			fout << seats[i] - 1;
			break;
		}
	}
	
	return 0;
}