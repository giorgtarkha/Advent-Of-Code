#include <bits/stdc++.h>

using namespace std;

void go(int curr, vector<vector<pair<int, int>>> adj, set<int> visited, int sum, int& ans) {
	if (visited.size() == adj.size()) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < adj[curr].size(); i++) {
		if (!visited.count(adj[curr][i].first)) {
			visited.insert(adj[curr][i].first);
			sum += adj[curr][i].second;
			go(adj[curr][i].first, adj, visited, sum, ans);
			sum -= adj[curr][i].second;
			visited.erase(adj[curr][i].first);
		}
	}
}

int main() {
	
	ifstream fin("9.in");
	ofstream fout("9_2.out");
	vector<vector<pair<int, int>>> adj;
	map<string, int> mapping;
	string s[5];
	int curr = 0;
	while (fin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4]) {
		if (!mapping.count(s[0])) {
			mapping[s[0]] = curr;
			adj.push_back({});
			curr++;
		}
		
		if (!mapping.count(s[2])) {
			mapping[s[2]] = curr;
			adj.push_back({});
			curr++;
		}
		
		adj[mapping[s[0]]].push_back({mapping[s[2]], stoi(s[4])});
		adj[mapping[s[2]]].push_back({mapping[s[0]], stoi(s[4])});
	}
	
	int ans = 0;
	for (int i = 0; i < adj.size(); i++) {
		set<int> visited;
		visited.insert(i);
		go(i, adj, visited, 0, ans);
	}
	fout << ans;
	
	return 0;
}