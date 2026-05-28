/*
题意：有一个存储设备状态的一维数组（从 1 开始计数）。有 N 个设备，M 条规则，Q 次状态更新。
规则结构：每条规则由“条件”和“动作（输出规则ID）”组成。
满分条件：条件是一个复杂的逻辑表达式字符串，如 "((dev[1]>50) AND (dev[2]==1)) OR (NOT(dev[3]<10))"。
1. 初始化：读入 N 个设备的初始状态值。
2. 注册规则：读入 M 条规则的表达式字符串。
3. 状态更新事件：发生 Q 次操作，每次输入格式为 "设备ID 新状态值"。触发原则：每次更新后，按规则注册顺序（1 到 M）依次评估条件。如果条件为真，输出该规则ID。
*/
#include<iostream>
#include<vector>
#define int long long
using namespace std;

struct SimpleRule {
	int target_device_id;
	string op; // ">", "<", or "=="
	int threshold;
};

vector<SimpleRule> rules;
int device_state[105];

bool check_rule(int rule_index) {
	int target_id = rules[rule_index].target_device_id;
	string op = rules[rule_index].op;
	int th = rules[rule_index].threshold;

	if (op == ">") return device_state[target_id] > th;
	if (op == "<") return device_state[target_id] < th;
	if (op == "==") return device_state[target_id] == th;

	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, q;
	if (!(cin >> n >> m >> q)) return 0;

	for (int i = 1; i <= n; ++i) {
		cin >> device_state[i];
	}

	rules.push_back({0, "", 0});
	for (int i = 1; i <= m; ++i) {
		int t_id;
		string op;
		int th;
		cin >> t_id >> op >> th;
		rules.push_back({t_id, op, th});
	}

	while (q--) {
		int update_id, new_val;
		cin >> update_id >> new_val;

		device_state[update_id] = new_val;

		bool triggered_any = false;
		for (int i = 1; i <= m; ++i) {
			if (check_rule(i)) {
				if (triggered_any) cout << " ";
				cout << i;
				triggered_any = true;
			}
		}
		if (!triggered_any) {
			cout << "NONE";
		}
		cout << "\n";
	}

	return 0;
}