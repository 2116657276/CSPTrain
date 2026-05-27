/*
题意：有一个包含 n 个类别的检测系统，形成一棵“树”的结构。每个类别 i 有一个权重 w_i。你收到一个神秘物品，它属于这 n 个类别中的某一个。你需要通过不断提问来确定它的准确类别。每次提问：你可以选一个类别 u。系统会告诉你：“该物品是否属于 u 或 u 的子孙后代？”
目标：你希望设计一个“最聪明”的提问策略。每次提问时，选择一个类别 u，使得无论系统回答“是”还是“否”，剩下可能的目标类别的权重之和，都尽可能接近总权重的一半。
现在要求你模拟 m 次这样的完整检测流程，输出每次检测中，你依次提问的类别编号。
数据范围：1 <= n <= 2000, 1 <= m <= 100
测试点 1-4（20分）：这棵树实际上是一条直线（每个节点只有一个儿子）。
测试点 5-10（30分）：n <= 50, m <= 10。
*/
#include<iostream>
#include<vector>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int test = 0; test < m; test++) {
        vector<bool> alive(n + 1, true);

        int target;
        cin >> target;

        while (true) {
            int alive_count = 0;
            int last_alive_node = 0;
            for (int i = 1; i <= n; i++) {
                if (alive[i]) {
                    alive_count++;
                    last_alive_node = i;
                }
            }

            if (alive_count <= 1) {
                break;
            }

            int best_u = 1;
            int sum1 = 0;
            for (int i =1;i < n+1; i++) {
                sum1 += w[i];
            }
            int diff = 0xFFFF;
            int sum2 = 0;
            for (int i = 1;i < n+1; i++) {
                sum2 += w[i];
                diff = min(diff, sum2 - sum1 - (sum1 - w[i]));
                if (diff == sum2 - sum1 - (sum1 - w[i])) {
                    best_u = i;
                }
            }

            const bool is_child_or_self = (target >= best_u);

            if (is_child_or_self) {

                for (int i = 1; i < best_u; i++) alive[i] = false;
            } else {

                for (int i = best_u; i <= n; i++) alive[i] = false;
            }

            cout << best_u << " ";
        }
        cout << "\n";
    }
    return 0;
}