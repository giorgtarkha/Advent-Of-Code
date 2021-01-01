#include <bits/stdc++.h>

using namespace std;

typedef struct {
	long long num;
	char op;
} data;

long long eval(vector<data>& v, int from, int to) {
	long long val = 0;
	char last_op = ' ';
	for (int i = from; i <= to;) {
		long long curr_val;
		if (v[i].op == '(') {
			int j = i + 1;
			int count = 1;
			while (true) {
				if (v[j].op == '(') {
					count++;
				} else if (v[j].op == ')') {
					count--;
				}
				if (!count) {
					break;
				}
				j++;
			}
			curr_val = eval(v, i + 1, j - 1);
			if (last_op == '+') {
				val += curr_val;
			} else if (last_op == '*') {
				val *= curr_val;
			} else if (last_op == ' ') {
				val = curr_val;
			}
			i = j + 1;
		} else if (v[i].op == ' ') {
			curr_val = v[i].num;
			if (last_op == '+') {
				val += curr_val;
			} else if (last_op == '*') {
				val *= curr_val;
			} else if (last_op == ' ') {
				val = curr_val;
			}
			i++;
		} else {
			last_op = v[i].op;
			i++;
		}
	}
	return val;
}

void parse_input(vector<data>& v, string& s) {
	string curr = "";
	s += ' ';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '*') {
			if (curr != "") {
				data dt;
				dt.num = stol(curr);
				dt.op = ' ';
				v.push_back(dt);
				curr = "";
			}
			{
				data dt;
				dt.op = s[i];
				v.push_back(dt);
			}
		} else if (s[i] != ' ') {
			curr += s[i];
		} else {
			if (curr != "") {
				data dt;
				dt.num = stol(curr);
				dt.op = ' ';
				v.push_back(dt);
				curr = "";
			}
		}
	}
}

int main() {
	
	ifstream fin("18.in");
	ofstream
	fout("18_1.out");
	map<int, int> numbers;
	long long ans = 0;
	vector<data> v;
	for (string s; getline(fin, s);) {
		parse_input(v, s);
		ans += eval(v, 0, v.size() - 1);
		v.clear();
	}
	fout << ans;
	
	return 0;
}