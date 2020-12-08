#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("25.in");
	ofstream fout("25_1.out");
	
	int col = 3083;
	int row = 2978;
	
	int num = 3;
	for (int i = 2; i < col; i++) {
		num += (i + 1);
	}
	
	for (int i = 1; i < row; i++) {
		num += col;
		col++;
	}
	
	num--;
	long long start = 20151125;
	while (num--) {
		start *= 252533;
		start %= 33554393;
	}
	fout << start;
	
	return 0;
}