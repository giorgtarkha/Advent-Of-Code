#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ofstream fout("19_1.out");
	int n = 3004953;
	set<int> elves;
	for (int i = 1; i <= n; i++) {
		elves.insert(i);
	}
	
	bool remove = false;
	while (elves.size() > 1) {
		vector<int> to_remove;
		for (auto it = elves.begin(); it != elves.end(); ++it) {
			if (!remove) {
				remove = true;
			} else {
				remove = false;
				to_remove.push_back(*it);
			}
		}
		for (auto it = to_remove.begin(); it != to_remove.end(); ++it) {
			elves.erase(*it);
		}
	}
	fout << *elves.begin();
	
	return 0;
}