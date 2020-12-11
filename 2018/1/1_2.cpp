#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_2.out");
	string s;
	vector<int> changes;
	while (fin >> s) {
		if (s[0] == '+') {
			changes.push_back(stoi(s.substr(1, s.length() - 1)));
		} else {
			changes.push_back(-stoi(s.substr(1, s.length() - 1)));
		}
	}
	
	set<int> frequencies;
	int frequency = 0, index = 0;
	do {
		frequencies.insert(frequency);
		frequency += changes[index];
		index++;
		if (index == changes.size()) {
			index = 0;
		}
	} while (!frequencies.count(frequency));
	fout << frequency;
	
	return 0;
}