#include <bits/stdc++.h>

using namespace std;

string nums[9] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
};

int is_num(string& s, int index) {
	vector<bool> v(9, true);
	for (int i = index; i < s.length(); ++i) {
		for (int j = 0; j < 9; ++j) {
			if (i - index < nums[j].length() && nums[j][i - index] != s[i]) {
				v[j] = false;
			}
			if (v[j] && i - index == nums[j].length() - 1) {
				return j + 1;
			}
		}
	}
	return -1;
}

int is_num_r(string& s, int index) {
	vector<bool> v(9, true);
	for (int i = index; i >= 0; --i) {
		for (int j = 0; j < 9; ++j) {
			if (index - i < nums[j].length() && nums[j][nums[j].length() + i - index - 1] != s[i]) {
				v[j] = false;
			}
			if (v[j] && index - i == nums[j].length() - 1) {
				return j + 1;
			}
		}
	}
	return -1;
}

int main() {
	
	ifstream fin("1.in");
	ofstream fout("1_2.out");
	
	int ans = 0;
	string num = "00";
	string s;
	while (fin >> s) {
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {
				num[0] = s[i];
				break;
			}
			int n = is_num(s, i);
			if (n != -1) {
				num[0] = '0' + n;
				break;
			}
		}
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] >= '0' && s[i] <= '9') {
				num[1] = s[i];
				break;
			}
			int n = is_num_r(s, i);
			if (n != -1) {
				num[1] = '0' + n;
				break;
			}
		}
		ans += stoi(num);
	}
	fout << ans << endl;
	
	return 0;
}
