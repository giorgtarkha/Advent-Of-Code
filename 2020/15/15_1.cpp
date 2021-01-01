#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ofstream fout("15_1.out");
	map<int, int> numbers;
	numbers[8] = 1;
	numbers[13] = 2;
	numbers[1] = 3;
	numbers[0] = 4;
	numbers[18] = 5;
	int last_number = 9;
	for (int i = 6; i < 2020; i++) {
		int curr = last_number;
		if (numbers.count(last_number)) {
			last_number = i - numbers[last_number];
		} else {
			last_number = 0;
		}
		numbers[curr] = i;
	}
	fout << last_number;
	
	return 0;
}