#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_2.out");
	
	string operation;
	int amount, x = 0, depth = 0, aim = 0;
	while (fin >> operation >> amount) {
		if (operation == "forward") {
			x += amount;
			depth += amount * aim;
		} else if (operation == "down") {
			aim += amount;
		} else {
			aim -= amount;
		}
	}
	fout << x * depth << endl;
	
	return 0;
}