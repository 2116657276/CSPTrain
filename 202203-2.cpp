/*
小明需要频繁出行，出行前必须有有效的核酸检测阴性证明。假设一次核酸检测做完后，需要等待k分钟才能出结果；出结果后，该证明在接下来的c分钟内有效（包含出结果的那一分钟）。现在小明有n项出行计划，第i项计划要求在时刻t_i出行。
小明想知道，如果他只在时刻q做一次核酸检测，那么这n项出行计划中，有多少项是可以顺利进行的？如果有m个不同的做核酸的时刻q_1,q_2,...,q_m，请分别回答对于每个q，能顺利出行的计划数。
【输入格式】第一行包含三个正整数n,m,k，分别表示出行计划数目、查询个数以及做完核酸等待出结果的时间。接下来n行，每行包含两个正整数t_i和c_i，表示一次出行计划所在的时刻和要求的核酸证明有效期。最后m行，每行包含一个正整数q_j，表示做核酸检测的时刻。
【输出格式】共输出m行，每行一个整数，表示在对应的时刻做核酸检测，能够顺利完成的出行计划数目。
*/
#include<iostream>
#define int long long
using namespace std;
constexpr int Max = 200005;
int diff[Max] = {};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m,k;
    //出行计划数、核酸查询个数、核酸查询时间
    if (!(cin >> n >> m >> k)) return 0;
    for (int i = 0; i < n; i++) {
        int t,c;
        //计划时刻，核酸有效时间
        cin >> t >> c;
        int Left = t-c-k+1;
        int Right = t-k;
        if (Left < 1) Left = 1;
        if (Right < 1) continue;
        diff[Left]++;
        diff[Right+1]--;
    }
    int index = 1;
    while (index < Max) {
        diff[index] = diff[index-1] + diff[index];
        index++;
    }
    for (int i =0;i < m;i++) {
        int query;
        cin >> query;
        cout << diff[query] << "\n";
    }
    return 0;
}