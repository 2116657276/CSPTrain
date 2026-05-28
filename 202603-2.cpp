/*
题意：你有 m 杯咖啡（总预算/背包容量）。有 n 个任务（物品）。
每个任务初始耗时 t。你想分配咖啡来最大化“缩短的总耗时”。
任务分两种：
1. 普通型 (o=1)：典型的“死脑筋”。你要么不给它咖啡，要给就必须一次性给它 a 杯，它能帮你省 b 的时间。
2. 灵活型 (o=0)：非常好说话。它最多能喝 a 杯。你每给它 1 杯，它就能帮你省 (b / a) 的时间。
求：不喝咖啡的总耗时 - 你能省下的最多时间。
*/
#include<iostream>
#include<vector>
#include<iomanip>
#define int long long
using namespace std;

struct Item {
	int weight;
	double value;
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	if (!(cin >> n >> m)) return 0;

	vector<Item> items;
	double total_time = 0;
	for (int i = 0; i < n; i++) {
		int o, a;
		double t, b;
		cin >> o >> t >> a >> b;
		total_time += t;
		if (o == 1) {
			items.push_back({a, b});
		} else {
			int num = a;
			const double val = b / static_cast<double>(a);
			while (num > 0) {
				items.push_back({1, val});
				num--;
			}
		}
	}

	vector<double> dp(m + 1, 0);
	for (const auto &item: items) {
		const int w = item.weight;
		const double v = item.value;
		for (int j = m; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << fixed << setprecision(6) << total_time - dp[m] << "\n";
}