/*
题意：有n个坐标变换操作，分两种：操作1：将坐标(x,y) 按比例拉伸k倍（即x=x*k,y=y*k）；操作2：将坐标(x,y) 逆时针旋转t弧度。有m个查询，每个查询包含i, j, x, y。表示：将初始坐标(x,y) 依次执行第i个到第j个操作。
输出：每次查询执行完操作后的最终坐标(x,y)，保留3位小数。
输入：第一行 n, m。接下来n行，每行格式为 "1 k" 或 "2 t"。接下来m行，每行格式为 "i j x y"（k,t,x,y为浮点数）。
*/
#include<iostream>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


}
