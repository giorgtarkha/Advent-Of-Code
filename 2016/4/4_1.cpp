#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("4.in");
	ofstream fout("4_1.out");
	string s;
	int ans = 0;
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
		
		map<char, int> counts;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '-') {
				counts[s[i]]++;
			}
		}
		
		map<int, set<char>> mp;
		for (auto it = counts.begin(); it != counts.end(); ++it) {
			mp[it->second].insert(it->first);			
		}
		
		bool good = true;
		int i = 0;
		for (auto it = mp.rbegin(); it != mp.rend() && i < 5; ++it) {
			for (auto itc = it->second.begin(); itc != it->second.end() && i < 5; ++itc) {
				if (checksum[i] != *itc) {
					good = false;
					break;
				}
				i++;
			}
			if (!good) {
				break;
			}
		}
		
		ans += good ? stoi(sector_id_string) : 0;
	}
	fout << ans;
	
	return 0;
}