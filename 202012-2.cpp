/*
题意：有 m 个同学，每个同学有安全指数 y 和真实结果 result(0或1)。你需要选定一个阈值 theta（必须是某个同学的 y 值）。若该同学 y >= theta，预测为 1（及格）；否则预测为 0（不及格）。
目标：找到使“预测正确的总人数”最多的 \theta。如有多个 \theta 准确率一样，输出最大的那个 \theta。
输入：第一行 m。接下来 m 行，每行 y_i, result_i。
输出：一个整数，即最佳阈值 \theta。
*/
#include<iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;
    vector<pair<int,int>> v;
    int ones = 0;
    for (int i = 0; i < m; i++) {
        int y,r;
        cin >> y >> r;
        v.emplace_back(y,r);
        if (r == 1) {
            ones++;
        }
    }
    sort(v.begin(),v.end());
    int t = v[0].first;
    int curr_correct = ones;
    int max_correct = curr_correct;
    for (int i = 1;i < m;i++) {
        if (v[i-1].second == 0) curr_correct++;
        else curr_correct--;

        if (v[i].first != v[i-1].first) {
            if (curr_correct >= max_correct) {
                max_correct = curr_correct;
                t =v[i].first;
            }
        }
    }
    cout << t;
}