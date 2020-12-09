#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("9.in");
	ofstream fout("9_1.out");
	string s;
	fin >> s;
	string decompressed = "";
	bool in_marker = false;
	string marker = "";
	int additional_count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (in_marker) {
			if (s[i] == ')') {
				in_marker = false;
				string len = "";
				while (marker.front() != 'x') {
					len += marker.front();
					marker.erase(marker.begin());
				}
				marker.erase(marker.begin());
				int leni = stoi(len), timesi = stoi(marker);
				string to_copy = "";
				for (int j = i + 1; j < i + leni + 1; j++) {
					if (j >= s.length()) {
						additional_count++;
					} else {
						to_copy += s[j];
					}
				}
				i += leni;
				additional_count *= timesi;
				for (int j = 0; j < timesi; j++) {
					decompressed += to_copy;
				}
				marker = "";
			} else {
				marker += s[i];
			}
		} else {
			if (s[i] == '(') {
				in_marker = true;
			} else {
				decompressed += s[i];
			}
		}			
	}
	fout << decompressed.length() + additional_count;
	
	return 0;
}