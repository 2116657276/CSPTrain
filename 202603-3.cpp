/*
题意：有一个足够大的整型内存空间（从 0 开始计数）。有 n 个进程，会发生 q 次操作：
1. new p L：进程 p 申请一个长度为 L 的连续内存块（队列）。
   分配原则：在当前所有空闲的内存中，找一个长度 >= L 且最接近 L 的空闲块（最优适应）。
   输出：这个内存块的起始地址。

2. send p：进程 p 向它名下的所有内存块发送一个数据。
   移动原则：每个内存块内部像一个“轮流坐庄”的循环队列。
   第一次发送，存在块的起点 a；后面每次发送，位置往后挪一格（t+1）；如果挪到边界了，就滚回起点 a。
   输出：这次发送中，所有被写入数据的内存地址之和。

3. delete p i：把进程 p 的第 i 个内存块删掉，释放这部分内存（e 和 x 置 0）。
*/
#include<iostream>
#include <vector>
#define int long long
using namespace std;

struct Memory {
	int begin_addr;
	int end_addr;
	int last_posi;
};

vector<vector<Memory> > memory(105);

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	if (!(cin >> n >> q)) return 0;

	int free_begin_addr = 0;
	for (int i = 0; i < q; i++) {
		string op;
		cin >> op;

		if (op == "new") {
			int p, length;
			cin >> p >> length;

			const int begin = free_begin_addr;
			const int end = begin + length - 1;

			memory[p].push_back({begin, end, -1});
			free_begin_addr = end + 1;
			cout << begin << "\n";
		} else if (op == "send") {
			int p;
			cin >> p;

			int sum_addr = 0;
			for (auto &m: memory[p]) {
				if (m.last_posi == -1) {
					sum_addr += m.begin_addr;
					m.last_posi = m.begin_addr;
				} else {
					if (m.last_posi < m.end_addr) {
						sum_addr += m.last_posi + 1;
						m.last_posi = m.last_posi + 1;
					} else {
						sum_addr += m.begin_addr;
						m.last_posi = m.begin_addr;
					}
				}
			}

			cout << sum_addr << "\n";
		} else if (op == "delete") {
			int p, a;
			cin >> p >> a;
		}
	}
	return 0;
}