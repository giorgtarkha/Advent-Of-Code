#include <bits/stdc++.h>

using namespace std;

long long go(string& s) {
	long long count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			string marker = "";
			int j = i + 1;
			for (; s[j] != ')'; j++) {
				marker += s[j];
			}
			string len = "";
			while (marker.front() != 'x') {
				len += marker.front();
				marker.erase(marker.begin());
			}
			marker.erase(marker.begin());
			int leni = stoi(len), timesi = stoi(marker);
			long long additional = 0;
			string next;
			if (j + leni >= s.length()) {
				additional = j + leni - s.length();
				next = s.substr(j + 1, s.length() - 1);
			} else {
				next = s.substr(j + 1, leni);
			}
			count += (go(next) + additional) * timesi;
			i = j + leni;
		} else {
			count++;
		}
	}
	return count;
}

int main() {
	
	ifstream fin("9.in");
	ofstream fout("9_2.out");
	string s;
	fin >> s;
	fout << go(s);
	
	return 0;
}