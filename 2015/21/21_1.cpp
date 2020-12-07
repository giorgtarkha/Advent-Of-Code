#include <bits/stdc++.h>

using namespace std;

bool good(int my_hp, int my_armor, int my_damage, int boss_hp, int boss_armor, int boss_damage) {
	int counter = 0;
	while (my_hp > 0 && boss_hp > 0) {
		if (counter % 2) {
			my_hp -= max(1, boss_damage - my_armor);
		} else {
			boss_hp -= max(1, my_damage - boss_armor);
		}
		counter++;
	}
	return my_hp > boss_hp;
}

int set_values(int& damage, int& armor, pair<int, pair<int, int>>& choice) {
	if (choice.first == 0 || choice.first == 2) {
		damage += choice.second.second;
	} else {
		armor += choice.second.second;
	}
	return choice.second.first;
}

void pick(vector<vector<pair<int, pair<int, int>>>> picks, int boss_hp, int boss_armor, int boss_damage, int& ans) {
	int my_hp = 100, my_armor = 0, my_damage = 0;
	if (picks.size() == 0) {
		if (good(my_hp, my_armor, my_damage, boss_hp, boss_armor, boss_damage)) {
			ans = min(ans, 0);
		}
	} else if (picks.size() == 1) {
		for (int i = 0; i < picks[0].size(); i++) {
			int cost = 0;
			cost += set_values(my_damage, my_armor, picks[0][i]);
			if (good(my_hp, my_armor, my_damage, boss_hp, boss_armor, boss_damage)) {
				ans = min(ans, cost);
			}
			my_damage = 0;
			my_armor = 0;
		}
	} else if (picks.size() == 2) {
		for (int i = 0; i < picks[0].size(); i++) {
			for (int j = 0; j < picks[1].size(); j++) {
				if (picks[0][i].first == picks[1][j].first) {
					continue;
				}
				int cost = 0;
				cost += set_values(my_damage, my_armor, picks[0][i]);
				cost += set_values(my_damage, my_armor, picks[1][j]);
				if (good(my_hp, my_armor, my_damage, boss_hp, boss_armor, boss_damage)) {
					ans = min(ans, cost);
				}
				my_damage = 0;
				my_armor = 0;
			}
		}
	} else if (picks.size() == 3) {
		for (int i = 0; i < picks[0].size(); i++) {
			for (int j = 0; j < picks[1].size(); j++) {
				for (int k = 0; k < picks[2].size(); k++) {
					if (picks[1][j].first == picks[2][k].first) {
						continue;
					}
					int cost = 0;
					cost += set_values(my_damage, my_armor, picks[0][i]);
					cost += set_values(my_damage, my_armor, picks[1][j]);
					cost += set_values(my_damage, my_armor, picks[2][k]);
					if (good(my_hp, my_armor, my_damage, boss_hp, boss_armor, boss_damage)) {
						ans = min(ans, cost);
					}
					my_damage = 0;
					my_armor = 0;
				}
			}
		}
	} else if (picks.size() == 4) {
		for (int i = 0; i < picks[0].size(); i++) {
			for (int j = 0; j < picks[1].size(); j++) {
				for (int k = 0; k < picks[2].size(); k++) {
					for (int l = 0; l < picks[3].size(); l++) {	
						if (picks[2][k].first == picks[3][l].first) {
							continue;
						}
						int cost = 0;
						cost += set_values(my_damage, my_armor, picks[0][i]);
						cost += set_values(my_damage, my_armor, picks[1][j]);
						cost += set_values(my_damage, my_armor, picks[2][k]);
						cost += set_values(my_damage, my_armor, picks[3][l]);
						if (good(my_hp, my_armor, my_damage, boss_hp, boss_armor, boss_damage)) {
							ans = min(ans, cost);
						}
						my_damage = 0;
						my_armor = 0;
					}
				}
			}
		}
	}
}

int main() {
	
	ifstream fin("21.in");
	ofstream fout("21_1.out");
	int boss_hp = -1, boss_armor = -1, boss_damage = -1;
	for (string line; getline(fin, line);) {
		string stat = "";
		for (int i = line.length() - 1; line[i] != ' '; i--) {
			stat = line[i] + stat;
		}
		if (boss_hp == -1) {
			boss_hp = stoi(stat);
		} else if (boss_damage == -1) {
			boss_damage = stoi(stat);
		} else {
			boss_armor = stoi(stat);
		}
	}
	vector<pair<int, pair<int, int>>> weapons {{0, {8, 4}}, {0, {10, 5}}, {0, {25, 6}}, {0, {40, 7}}, {0, {74, 8}}};
	vector<pair<int, pair<int, int>>> armors {{1, {13, 1}}, {1, {31, 2}}, {1, {53, 3}}, {1, {75, 4}}, {1, {102, 5}}};
	vector<pair<int, pair<int, int>>> rings_w {{2, {25, 1}}, {2, {50, 2}}, {2, {100, 3}}};
	vector<pair<int, pair<int, int>>> rings_a {{3, {20, 1}}, {3, {40, 2}}, {3, {80, 3}}};
	int ans = 2 << 29;
	for (int i = 0; i < (1 << 3); i++) {
		vector<vector<pair<int, pair<int, int>>>> picks;
		picks.push_back(weapons);
		if (i & 1) {
			picks.push_back(armors);
		}
		if ((i >> 1) & 1) {
			picks.push_back(rings_w);
		}
		if ((i >> 2) & 1) {
			picks.push_back(rings_a);
		}
		pick(picks, boss_hp, boss_armor, boss_damage, ans);
	}
	
	for (int i = 0; i < (1 << 3); i++) {
		vector<vector<pair<int, pair<int, int>>>> picks;
		picks.push_back(weapons);
		if (i & 1) {
			picks.push_back(armors);
		}
		if ((i >> 1) & 1) {
			picks.push_back(rings_w);
		}
		if ((i >> 2) & 1) {
			picks.push_back(rings_w);
		}
		pick(picks, boss_hp, boss_armor, boss_damage, ans);
	}
	
	for (int i = 0; i < (1 << 3); i++) {
		vector<vector<pair<int, pair<int, int>>>> picks;
		picks.push_back(weapons);
		if (i & 1) {
			picks.push_back(armors);
		}
		if ((i >> 1) & 1) {
			picks.push_back(rings_a);
		}
		if ((i >> 2) & 1) {
			picks.push_back(rings_a);
		}
		pick(picks, boss_hp, boss_armor, boss_damage, ans);
	}
	fout << ans;
	
	return 0;
}