// 食堂推出了n种菜品。现在有m个同学依次报出自己想吃的菜品名称（字符串）。
// 请你按菜品第一次出现的顺序，输出每种被点到的菜品名称，以及它最终被点了多少次。
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    map<string,int> counter;
    vector<string> order;

    for (int i = 0;i < m;i++) {
        string dish;
        cin>>dish;
        if (counter.find(dish) == counter.end()) {
            counter[dish] = 1;
            order.push_back(dish);
        }else {
            counter[dish]++;
        }
    }
    for (const string& o:order) {
        cout << o << " " << counter[o] << "\n";
    }
}