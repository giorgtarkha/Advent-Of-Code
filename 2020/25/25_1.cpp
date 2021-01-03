#include <bits/stdc++.h>

using namespace std;

#define MOD 20201227

int get_loop_size(long long key) {
	long long val = 1, subject = 7;
	int loop_size = 0;
	while (val != key) {
		val *= subject;
		val %= MOD;
		loop_size++;
	}
	return loop_size;
}

long long get_encryption_key(long long key, int loop_size) {
	long long val = 1;
	while (loop_size--) {
		val *= key;
		val %= MOD;
	}
	return val;
}

int main() {
	
	ifstream fin("25.in");
	ofstream fout("25_1.out");
	
	long long key1, key2;
	fin >> key1 >> key2;
	
	int loop_size_1 = get_loop_size(key1), loop_size_2 = get_loop_size(key2);
	long long encryption_key = get_encryption_key(key1, loop_size_2);
	fout << encryption_key;
	
	return 0;
}