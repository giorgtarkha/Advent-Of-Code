#include <bits/stdc++.h>

using namespace std;

typedef struct {
	vector<int> values;
	string lower_to;
	string higher_to;
} bot;

int main() {
	
	ifstream fin("10.in");
	ofstream fout("10_2.out");
	string s;
	
	map<int, bot> bots;
	while (fin >> s) {
		if (s == "value") {
			fin >> s;
			int value = stoi(s);
			fin >> s >> s >> s >> s;
			int bot = stoi(s);
			bots[bot].values.push_back(value);
		} else {
			fin >> s;
			int bot = stoi(s);
			fin >> s >> s >> s >> s;
			bool is_bot = s == "bot";
			fin >> s;
			if (is_bot) {
				bots[bot].lower_to = "bot_" + s;
			} else {
				bots[bot].lower_to = "output_" + s;
			}
			fin >> s >> s >> s >> s;
			is_bot = s == "bot";
			fin >> s;
			if (is_bot) {
				bots[bot].higher_to = "bot_" + s;
			} else {
				bots[bot].higher_to = "output_" + s;
			}
		}
	}
	
	map<int, int> outputs;
	while (true) {
		bool have_workings_bots = false;
		for (auto it = bots.begin(); it != bots.end(); ++it) {
			if (it->second.values.size() == 2) {
				have_workings_bots = true;
				int lower = min(it->second.values[0], it->second.values[1]);
				int higher = max(it->second.values[0], it->second.values[1]);
				string target_lower = "";
				for (int i = it->second.lower_to.length() - 1; it->second.lower_to[i] != '_'; i--) {
					target_lower += it->second.lower_to[i];
				}
				reverse(target_lower.begin(), target_lower.end());
				if (it->second.lower_to[0] == 'b') {
					bots[stoi(target_lower)].values.push_back(lower);
				} else {
					outputs[stoi(target_lower)] = lower;
				}
				
				string target_higher = "";
				for (int i = it->second.higher_to.length() - 1; it->second.higher_to[i] != '_'; i--) {
					target_higher += it->second.higher_to[i];
				}
				reverse(target_higher.begin(), target_higher.end());
				if (it->second.higher_to[0] == 'b') {
					bots[stoi(target_higher)].values.push_back(higher);
				} else {
					outputs[stoi(target_higher)] = higher;
				}
				
				it->second.values.clear();
			}
		}
		if (!have_workings_bots) {
			break;
		}
	}
	
	fout << outputs[0] * outputs[1] * outputs[2];
	
	return 0;
}