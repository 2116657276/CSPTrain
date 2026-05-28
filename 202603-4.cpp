/*
题意：维护一个长度为 n 的整型数组 a（从 1 开始编号），给出一个奇数 k 作为进制基数。核心运算 +k：将两个数按 k 进制拆分，每一位相加后对 k 取模，不进位。前缀函数 f(n)：从 0 一直用 +k 运算累加到 n。
输入格式：第一行：n (数组长度), m (操作次数), k (全局奇数进制)。第二行：n 个非负整数，代表初始数组 a。
接下来 m 行，分为两类操作：
  - 类型 1：1 l r v  -> 将区间 [l, r] 内的每个 a_i 变成 (a_i +k_v)。
  - 类型 2：2 l r    -> 求区间 [l, r] 内所有 f(a_i) 的 +k 累加和。
输出格式：
对于每个类型 2 的查询，输出一行结果。
*/
#include<iostream>
#include<vector>
#include<map>
#define int long long

using namespace std;
int n, m, k;
vector<int> a;
map<int, int> f_cache;

int k_xor(int x, int y) {
}

int get_f(int num) {
	if (num == 0) return 0;
	if (f_cache.count(num)) return f_cache[num];

	int res = k_xor(num, get_f(num - 1));
	f_cache[num] = res;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	if (!(cin >> n >> m >> k)) return 0;

	a.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			for (int i = l; i <= r; ++i) {
				a[i] = k_xor(a[i], v);
			}
		} else if (type == 2) {
			int l, r;
			cin >> l >> r;
			int ans = 0;
			for (int i = l; i <= r; ++i) {
				ans = k_xor(ans, get_f(a[i]));
			}
			cout << ans << "\n";
		}
	}

	return 0;
}