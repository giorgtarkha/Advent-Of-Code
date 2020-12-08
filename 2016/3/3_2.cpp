#include <bits/stdc++.h>

using namespace std;

int get(vector<int>& v) {
	int ans = 0;
	for (int i = 0; i < v.size(); i += 3) {
		ans += v[i] + v[i + 1] > v[i + 2] && v[i] + v[i + 2] > v[i + 1] && v[i + 1] + v[i + 2] > v[i]; 
	}
	return ans;
}

int main() {
	
	ifstream fin("3.in");
	ofstream fout("3_2.out");
	int a, b, c;
	vector<int> first;
	vector<int> second;
	vector<int> third;
	while (fin >> a >> b >> c) {
		first.push_back(a);
		second.push_back(b);
		third.push_back(c);
	}
	fout << get(first) + get(second) + get(third);
	
	return 0;
}