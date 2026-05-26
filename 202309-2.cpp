/*
题意：有n个坐标变换操作，分两种：操作1：将坐标(x,y) 按比例拉伸k倍（即x=x*k,y=y*k）；操作2：将坐标(x,y) 逆时针旋转t弧度。有m个查询，每个查询包含i, j, x, y。表示：将初始坐标(x,y) 依次执行第i个到第j个操作。
输出：每次查询执行完操作后的最终坐标(x,y)，保留3位小数。
输入：第一行 n, m。接下来n行，每行格式为 "1 k" 或 "2 t"。接下来m行，每行格式为 "i j x y"（k,t,x,y为浮点数）。
*/
#include<iostream>
#include<vector>
#include <cmath>
#include <iomanip>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    if (!(cin >> n >> m)) return 0;
    vector<double> k(n+1,1.0);
    vector<double> t(n+1,0.0);
    for (int i = 1; i < n+1; i++) {
        int option;
        double action;
        cin >> option >> action;
        if (option == 1) {
            k[i] = k[i-1]*action;
            t[i] = t[i-1];
        }else {
            k[i] = k[i-1];
            t[i] = t[i-1]+action;
        }
    }

    for (int a = 0; a < m ;a++) {
        int i, j;
        double x, y;
        cin >> i >> j >> x >> y;
        const double multi = k[j] / k[i-1];
        const double plus = t[j] - t[i-1];
        const double x1 = x*multi;
        const double y1 = y*multi;
        const double x2 = x1*cos(plus) - y1*sin(plus);
        const double y2 = x1*sin(plus) + y1*cos(plus);
        cout << fixed << setprecision(3)<<x2<<" "<<y2<<"\n";
    }
}
