#include <bits/stdc++.h>

using namespace std;

string go(string& s) {
	s += " ";
	vector<pair<int, char>> v;
	int count = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1]) {
			v.push_back({count, s[i - 1]});
			count = 1;
		} else {
			count++;
		}
	}
	
	string res = "";
	for (int i = 0; i < v.size(); i++) {
		res += to_string(v[i].first);
		res += v[i].second;
	}
	
	return res;
}

int main() {
	
	ifstream fin("10.in");
	ofstream fout("10_1.out");
	string s;
	fin >> s;
	for (int i = 0; i < 40; i++) {
		s = go(s);
	}
	fout << s.length();
	
	return 0;
}