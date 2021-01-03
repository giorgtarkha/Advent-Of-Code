#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> merge(vector<pair<long long, long long>>& v) {
	vector<pair<long long, long long>> res;
	
	pair<long long, long long> curr = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (curr.second >= v[i].first - 1) {
			curr.second = max(curr.second, v[i].second);
		} else {
			res.push_back(curr);
			curr = v[i];
		}
	}
	
	return res;
}

int main() {
	
	ifstream fin("20.in");
	ofstream fout("20_1.out");
	vector<pair<long long, long long>> v;
	string s;
	while (fin >> s) {
		int index = s.find("-", 0);
		v.push_back({stoll(s.substr(0, index)), stoll(s.substr(index + 1, s.length() - index))});
	}
	
	sort(v.begin(), v.end());
	v = merge(v);
	fout << v[0].second + 1;
	
	return 0;
}