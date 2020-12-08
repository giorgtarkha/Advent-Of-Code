#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("4.in");
	ofstream fout("4_2.out");
	string s;
	while (fin >> s) {
		s.pop_back();
		string checksum = "";
		while (s.back() != '[') {
			checksum = s.back() + checksum;
			s.pop_back();
		}
		s.pop_back();
		string sector_id_string = "";
		while (s.back() != '-') {
			sector_id_string = s.back() + sector_id_string;
			s.pop_back();
		}
		s.pop_back();
		int sector_id = stoi(sector_id_string);
		for (int j = 0; j < sector_id; j++) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '-') {
					s[i] = ' ';
				} else if (s[i] == ' ') {
					s[i] = '-';
				} else {
					s[i] = s[i] == 'z' ? 'a' : s[i] + 1;
				}
			}
		}
		if (s.find("northpole", 0) != string::npos || s.find("north pole", 0) != string::npos) {
			fout << sector_id;
			break;
		}
	}
	
	return 0;
}