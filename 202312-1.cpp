/*
 * 有n个仓库，每个仓库有m个维度的位置数据。
我们需要帮每一个仓库i找一个“上级仓库”j。
成为“上级仓库”的条件极其苛刻：仓库j的每一个维度的数据，都必须严格大于仓库i的对应维度数据。
如果有多个符合条件的上级仓库，输出编号最小的那个；如果没有，输出 0。
 */
#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n+1, vector<int>(m+1,0));
    for (int i = 1;i <=n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        int parent = 0;
        for (int j = 1;j <= m;j++) {
            int tag = 0;
            if (i == j) continue;
            for (int k = 1;k <=m;k++) {
                if (matrix[j][k]<= matrix[i][k]) {
                    tag = 1;
                    break;
                }
            }
            if (tag == 0) {
                parent = j;
                break;
            }
        }
        cout << parent << endl;
    }
}
