#include <bits/stdc++.h>

using namespace std;

int get(deque<int>& d) {
	int res = 0, mult = 1;
	while (d.size()) {
		res += d.back() * mult;
		mult++;
		d.pop_back();
	}
	return res;
}

int main() {
	
	ifstream fin("22.in");
	ofstream fout("22_1.out");
	deque<int> p1;
	for (string s; getline(fin, s);) {
		if (s == "") {
			break;
		}
		if (s[0] != 'P') {
			p1.push_back(stoi(s));
		}
	}
	
	deque<int> p2;
	for (string s; getline(fin, s);) {
		if (s[0] != 'P') {
			p2.push_back(stoi(s));
		}
	}
	
	while (p1.size() && p2.size()) {
		int p1_top = p1.front(), p2_top = p2.front();
		p1.pop_front();
		p2.pop_front();
		if (p1_top > p2_top) {
			p1.push_back(p1_top);
			p1.push_back(p2_top);
		} else {
			p2.push_back(p2_top);
			p2.push_back(p1_top);
		}
	}
	
	int ans = 0;
	ans += get(p1);
	ans += get(p2);
	fout << ans;
	
	return 0;
}