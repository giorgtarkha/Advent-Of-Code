#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_1.out");
	
	set<int> numbers;
	int n;
	while (fin >> n) {
		if (numbers.count(2020 - n)) {
			fout << n * (2020 - n);
			break;
		}
		numbers.insert(n);
	}
	
	return 0;
}