/*
题意：给出一个长度为 n 的序列 A。选定一个阈值 p（p 为任意正整数）。将序列中所有小于 p 的数字变成 0。“非零段”定义为：由连续的、严格大于 0 的数字组成的子序列。
目标：找到一个合适的 p，使得整个序列被划分出的“非零段”个数最多。输出这个最多的个数。
输入：第一行 n。第二行 n 个正整数 A_i。
输出：一个整数（最大非零段个数）。
*/
#include<iostream>
#include<vector>
#include<map>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	if (!(cin >> n)) return 0;
	vector<int> a(n + 1, 0);
	map<int,int> diff;
	for (int i = 1; i <= n; i++) {
		int j;
		cin >> j;
		a[i] = j;
		if (a[i] > a[i - 1]) {
			diff[a[i - 1] + 1]++;
			diff[a[i] + 1]--;
		}
	}
	int p = 0;
	int segment = 0;
	int max_segment = 0;
	for (const auto &pair: diff) {
		segment += pair.second;
		if (segment >= max_segment) {
			max_segment = segment;
		}
	}
	cout << max_segment;
	return 0;
}