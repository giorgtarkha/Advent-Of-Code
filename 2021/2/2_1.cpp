#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_1.out");
	
	string operation;
	int amount, x = 0, depth = 0;
	while (fin >> operation >> amount) {
		if (operation == "forward") {
			x += amount;
		} else if (operation == "down") {
			depth += amount;
		} else {
			depth -= amount;
		}
	}
	fout << x * depth << endl;
	
	return 0;
}