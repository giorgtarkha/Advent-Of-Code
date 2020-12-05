#include <bits/stdc++.h>

using namespace std;

vector<int> get_dimensions(string& s) {
	s += "x";
	vector<int> d;
	string curr = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'x') {
			d.push_back(stoi(curr));
			curr = "";
		} else {
			curr += s[i];
		}
	}
	
	sort(d.begin(), d.end());
	return d;
}

int main() {

	ifstream fin("2.in");
	ofstream fout("2_2.out");
	int ans = 0;
	string s;
	while (fin >> s) {
		vector<int> dimensions = get_dimensions(s);
		ans += 2 * (dimensions[0] + dimensions[1]);
		ans += dimensions[0] * dimensions[1] * dimensions[2];
	}
	fout << ans;

	return 0;
}