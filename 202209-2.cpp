/*
双十一买书，有 n 本书，第 i 本书价格为 a_i。电商平台的包邮门槛是 x 元。你想要凑单，从这 n 本书中挑出若干本，使得总价格 >= x，并且要求总价格【尽可能小】（也就是刚好过包邮线，不要浪费钱）。
求出满足条件的最小凑单总价格。
输入：第一行 n, x。接下来 n 行，每行一个整数 a_i。
输出：一个整数（最小的凑单总价）。
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define int long long

using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, X;
	if (!(cin >> n >> X)) return 0;
	vector<int> goods(n + 1, 0);
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		int good;
		cin >> good;
		sum += good;
		goods[i] = good;
	}
	sort(goods.begin(), goods.end());

	const int Y = sum - X;
	if (Y <= 0) {
		cout << sum;
		return 0;
	}
	vector<int> dp(Y + 1, 0);
	for (int i = 1; i <= n; i++) {
		int const price = goods[i];
		for (int j = Y; j >= price; j--) {
			dp[j] = max(dp[j], dp[j - price] + price);
		}
	}

	cout << sum - dp[Y];
	return 0;
}