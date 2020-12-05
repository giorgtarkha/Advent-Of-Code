#include <bits/stdc++.h>

using namespace std;

pair<int, int> get_rule(string& rule) {
	string first = "", second = "";
	int i = 0;
	for (; rule[i] != '-'; i++) {
		first += rule[i];
	}
	i++;
	for (; i < rule.length(); i++) {
		second += rule[i];
	}
	return { stoi(first), stoi(second) };
}

int main() {
	
	ifstream fin("2.in");
	ofstream fout("2_1.out");
	
	string rule, c, pass;
	int ans = 0;
	while (fin >> rule >> c >> pass) {
		pair<int, int> rule_p = get_rule(rule);
		char character = c[0];
		int count = 0;
		for (int i = 0; i < pass.length(); i++) {
			if (pass[i] == character) {
				count++;
			}
		}
		ans += count >= rule_p.first && count <= rule_p.second;
	}
	fout << ans;
	
	return 0;
}