/*
题意：n块田同时开垦。第i块耗时 t_i，每投入 c_i 资源可缩短1天。最少不能少于 k 天。求总资源 m 内，开垦完所有田的最少天数。
输入：第一行 n, m, k。接下来 n 行每行 t_i, c_i。
输出：一个整数（最少天数）。
*/
#include<iostream>
#include <vector>
#define int long long
using namespace std;
int n,m,k;//田地数量，总资源数，极限时间
vector<int> times;
vector<int> cost;
bool check(int limit) {
    int curr_cost = 0;
    for (int i = 0;i < n;i++) {
        if (times[i] > limit) {
            curr_cost += (times[i] - limit) * cost[i];
        }
        if (curr_cost > m) return false;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (!(cin>>n>>m>>k)) return 0;
    int L = k;
    int R = k;
    for (int i=0;i<n;i++) {
        int t,c;
        //初始耗时，减少一天所需资源
        cin>>t>>c;
        times.emplace_back(t);
        cost.emplace_back(c);
        if (t > R) R = t;
    }
    int ans = R;
    while (L <= R) {
        int limit = (L + R)/2;
        if (check(limit)) {
            ans = limit;
            R = limit -1;
        }else{
            L = limit + 1;
        }
    }
    cout << ans;
    return 0;
}