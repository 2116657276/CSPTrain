#include<iostream>
#define int long long
using namespace std;

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int k; //查询个数
   if (!(cin >> k)) return 0;

   for (int i = 0; i < k; i++) {
      int mu, sigma, n;
      cin >> mu >> sigma >> n;
      int m = 100 * (n - mu) / sigma;
      int col = m % 10 + 1;
      int row = m / 10 + 1;
      cout << row << " " << col << "\n";
   }
   return 0;
}