#include <bits/stdc++.h>

using namespace std;

void turn_player(int mana, int used_mana, int my_hp, int boss_hp, int boss_damage, int shield_cooldown, int poison_cooldown, int recharge_cooldown, int& ans);
void turn_boss(int mana, int used_mana, int my_hp, int boss_hp, int boss_damage, int shield_cooldown, int poison_cooldown, int recharge_cooldown, int& ans);

void turn_player(int mana, int used_mana, int my_hp, int boss_hp, int boss_damage, int shield_cooldown, int poison_cooldown, int recharge_cooldown, int& ans) {
	my_hp--;
	if (my_hp <= 0) {
		return;
	}
	if (poison_cooldown) {
		boss_hp -= 3;
		if (boss_hp <= 0) {
			ans = min(ans, used_mana);
			return;
		}
	}
	if (recharge_cooldown) {
		mana += 101;
	}
	
	if (mana >= 53) {
		turn_boss(mana - 53, used_mana + 53, my_hp, boss_hp - 4, boss_damage, max(0, shield_cooldown - 1), max(0, poison_cooldown - 1), max(0, recharge_cooldown - 1), ans);
	}
	if (mana >= 73) {
		turn_boss(mana - 73, used_mana + 73, my_hp + 2, boss_hp - 2, boss_damage, max(0, shield_cooldown - 1), max(0, poison_cooldown - 1), max(0, recharge_cooldown - 1), ans);
	}
	if (mana >= 113 &&  shield_cooldown <= 1) {
		turn_boss(mana - 113, used_mana + 113, my_hp, boss_hp, boss_damage, 5, max(0, poison_cooldown - 1), max(0, recharge_cooldown - 1), ans);
	}
	if (mana >= 173 && poison_cooldown <= 1) {
		turn_boss(mana - 173, used_mana + 173, my_hp, boss_hp, boss_damage, max(0, shield_cooldown - 1), 6, max(0, recharge_cooldown - 1), ans);
	}
	if (mana >= 229 && recharge_cooldown <= 1) {
		turn_boss(mana - 229, used_mana + 229, my_hp, boss_hp, boss_damage, max(0, shield_cooldown - 1), max(0, poison_cooldown - 1), 5, ans);
	}
}

void turn_boss(int mana, int used_mana, int my_hp, int boss_hp, int boss_damage, int shield_cooldown, int poison_cooldown, int recharge_cooldown, int& ans) {
	if (boss_hp <= 0) {
		ans = min(ans, used_mana);
		return;
	}
	if (poison_cooldown) {
		boss_hp -= 3;
		if (boss_hp <= 0) {
			ans = min(ans, used_mana);
			return;
		}
	}
	if (recharge_cooldown) {
		mana += 101;
	}
	turn_player(mana, used_mana, shield_cooldown ? my_hp - max(1, boss_damage - 7) : my_hp - boss_damage, boss_hp, boss_damage, max(0, shield_cooldown - 1), max(0, poison_cooldown - 1), max(0, recharge_cooldown - 1), ans);
}

int main() {
	
	ifstream fin("22.in");
	ofstream fout("22_2.out");
	string s;
	fin >> s >> s >> s;
	int boss_hp = stoi(s);
	fin >> s >> s;
	int boss_damage = stoi(s);
	int ans = 2 << 29;
	turn_player(500, 0, 50, boss_hp, boss_damage, 0, 0, 0, ans);
	fout << ans;
	
	return 0;
}