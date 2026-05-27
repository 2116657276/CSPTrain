/*
给你 n 个正整数。如果一个数的二进制表示中，'1' 的个数和 '0' 的个数完全相等，那它就是“平衡数”（最高位前面的 0 不算，比如 12 变成 1100，算 2个1 和 2个0）。
求这 n 个数里有多少个平衡数。
*/
#include<iostream>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	if (!(cin >> n)) return 0;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int zeros = 0;
		int ones = 0;
		while (a > 0) {
			if (a % 2 == 1) ones++;
			else zeros++;
			a = a >> 1;
		}
		if (zeros == ones) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}