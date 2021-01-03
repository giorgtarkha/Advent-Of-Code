#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("21.in");
	ofstream fout("21_1.out");
	string s, pass = "abcdefgh";
	while (fin >> s) {
		if (s == "swap") {
			string s2[5];
			fin >> s2[0] >> s2[1] >> s2[2] >> s2[3] >> s2[4];
			if (s2[0] == "position") {
				swap(pass[stoi(s2[1])], pass[stoi(s2[4])]);
			} else {
				for (int i = 0; i < pass.length(); i++) {
					if (pass[i] == s2[1][0]) {
						pass[i] = s2[4][0];
					} else if (pass[i] == s2[4][0]) {
						pass[i] = s2[1][0];
					}
				}
			}
		} else if (s == "rotate") {
			string s1;
			fin >> s1;
			if (s1 == "based") {
				string s2[5];
				fin >> s2[0] >> s2[1] >> s2[2] >> s2[3] >> s2[4];
				int index = pass.find(s2[4], 0);
				pass = pass.substr(pass.length() - 1, 1) + pass.substr(0, pass.length() - 1);
				pass = pass.substr(pass.length() - index, index) + pass.substr(0, pass.length() - index);
				if (index >= 4) {
					pass = pass.substr(pass.length() - 1, 1) + pass.substr(0, pass.length() - 1);
				}
			} else {
				int x;
				fin >> x;
				fin >> s;
				x %= pass.length();
				if (s1 == "left") {
					pass = pass.substr(x, pass.length() - x) + pass.substr(0, x);
				} else {
					pass = pass.substr(pass.length() - x, x) + pass.substr(0, pass.length() - x);
				}
			}
		} else if (s == "reverse") {
			string s2[4];
			fin >> s2[0] >> s2[1] >> s2[2] >> s2[3];
			reverse(pass.begin() + stoi(s2[1]), pass.begin() + stoi(s2[3]) + 1);
		} else {
			string s2[5];
			fin >> s2[0] >> s2[1] >> s2[2] >> s2[3] >> s2[4];
			int from = stoi(s2[1]), to = stoi(s2[4]);
			char c = pass[from];
			pass.erase(pass.begin() + from);
			pass.insert(pass.begin() + to, c);
		}
	}
	fout << pass;
	
	return 0;
}