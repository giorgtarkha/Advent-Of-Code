#include <bits/stdc++.h>

using namespace std;

typedef struct {
	string type;
	string second_value;
	string into;
} instruction;

typedef struct {
	bool has_value;
	int value;
	vector<instruction> instructions;
} data;

void parse_input(string& input, map<string, data>& m, queue<string>& q) {
	vector<string> v;
	input += " ";
	string curr = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ' || input[i] == '-' || input[i] == '>') {
			if (curr.length()) {
				v.push_back(curr);
				curr = "";
			}
		} else {
			curr += input[i];
		}
	}
	
	if (v.size() == 2) {
		if (v[0][0] >= 'a' && v[0][0] <= 'z') {
			instruction s;
			s.type = "WIRE";
			s.into = v[1];
			m[v[0]].instructions.push_back(s);
		} else {
			m[v[1]].value = stoi(v[0]);
			m[v[1]].has_value = true;
			q.push(v[1]);
		}
	} else if (v.size() == 3) {
		if (v[1][0] >= 'a' && v[1][0] <= 'z') {
			instruction s;
			s.type = "NOT";
			s.into = v[2];
			m[v[1]].instructions.push_back(s);
		} else {
			m[v[2]].value = ~stoi(v[1]);
			m[v[2]].has_value = true;
			q.push(v[2]);
		}
	} else {
		if (v[0][0] >= '0' && v[0][0] <= '9' && v[2][0] >= '0' && v[2][0] <= '9') {
			if (v[1] == "AND") {
				m[v[3]].value = stoi(v[0]) & stoi(v[2]);
				m[v[3]].has_value = true;
				q.push(v[3]);
			} else if (v[1] == "OR") {
				m[v[3]].value = stoi(v[0]) | stoi(v[2]);
				m[v[3]].has_value = true;
				q.push(v[3]);
			} else if (v[1] == "LSHIFT") {
				m[v[3]].value = stoi(v[0]) << stoi(v[2]);
				m[v[3]].has_value = true;
				q.push(v[3]);
			} else if (v[1] == "RSHIFT") {
				m[v[3]].value = stoi(v[0]) >> stoi(v[2]);
				m[v[3]].has_value = true;
				q.push(v[3]);
			}
		} else if (v[0][0] >= '0' && v[0][0] <= '9') {
			instruction s;
			s.type = v[1];
			s.second_value = v[0];
			s.into = v[3];
			m[v[2]].instructions.push_back(s);
		} else {
			instruction s;
			s.type = v[1];
			s.second_value = v[2];
			s.into = v[3];
			m[v[0]].instructions.push_back(s);
		}
	}
	
}

void go(map<string, data>& m, queue<string> q) {
	while (!q.empty()) {
		string curr = q.front();
		q.pop();
		vector<instruction> new_instructions;
		vector<instruction> instructions = m[curr].instructions;
		for (int i = 0; i < instructions.size(); i++) {
			if (instructions[i].type == "WIRE") {
				m[instructions[i].into].value = m[curr].value;
				m[instructions[i].into].has_value = true;
				q.push(instructions[i].into);
			} else if (instructions[i].type == "NOT") {
				m[instructions[i].into].value = ~m[curr].value;
				m[instructions[i].into].has_value = true;
				q.push(instructions[i].into);
			} else if (instructions[i].type == "AND") {
				if (instructions[i].second_value[0] >= '0' && instructions[i].second_value[0] <= '9') {
					m[instructions[i].into].value = m[curr].value & stoi(instructions[i].second_value);
					m[instructions[i].into].has_value = true;
					q.push(instructions[i].into);
				} else {
					if (m[instructions[i].second_value].has_value) {
						m[instructions[i].into].value = m[curr].value & m[instructions[i].second_value].value;
						m[instructions[i].into].has_value = true;
						q.push(instructions[i].into);
					} else {
						new_instructions.push_back(instructions[i]);
					}
				}
			} else if (instructions[i].type == "OR") {
				if (instructions[i].second_value[0] >= '0' && instructions[i].second_value[0] <= '9') {
					m[instructions[i].into].value = m[curr].value | stoi(instructions[i].second_value);
					m[instructions[i].into].has_value = true;
					q.push(instructions[i].into);
				} else {
					if (m[instructions[i].second_value].has_value) {
						m[instructions[i].into].value = m[curr].value | m[instructions[i].second_value].value;
						m[instructions[i].into].has_value = true;
						q.push(instructions[i].into);
					} else {
						new_instructions.push_back(instructions[i]);
					}
				}
			} else if (instructions[i].type == "LSHIFT") {
				m[instructions[i].into].value = m[curr].value << stoi(instructions[i].second_value);
				m[instructions[i].into].has_value = true;
				q.push(instructions[i].into);
			} else if (instructions[i].type == "RSHIFT") {
				m[instructions[i].into].value = m[curr].value >> stoi(instructions[i].second_value);
				m[instructions[i].into].has_value = true;
				q.push(instructions[i].into);
			}
		}
		if (new_instructions.size()) {
			m[curr].instructions = new_instructions;
			q.push(curr);
		}
	}
}

int main() {
	
	ifstream fin("7.in");
	ofstream fout("7_2.out");
	map<string, data> m;
	queue<string> q;
	for (string line; getline(fin, line);) {
		parse_input(line, m, q);
	}
	
	for (auto it = m.begin(); it != m.end(); ++it) {
		sort(it->second.instructions.begin(), it->second.instructions.end(), 
			[](const instruction &in1, const instruction &in2) {
				if (in1.type == "WIRE" || in1.type == "NOT" || in1.type == "LSHIFT" || in1.type == "RSHIFT") {
					return 0;
				}
				return 1;
			});
	}
	
	for (auto it = m.begin(); it != m.end(); ++it) {
		reverse(it->second.instructions.begin(), it->second.instructions.end());
	}
	
	map<string, data> m_copy = m;
	queue<string> q_copy = q;
	go(m, q);
	int signal = m["a"].value;
	m_copy["b"].value = signal;
	go(m_copy, q_copy);
	fout << m_copy["a"].value;
	
	return 0;
}