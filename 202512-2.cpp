#include<iostream>
#include<vector>
#define int long long
using namespace std;

int func (int x,int k) {
   return (x * x + k * k) % 8 ^ k;
}

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n, m;
   if (!(cin >> n >> m)) return 0;

   vector<int> K(m);
   for (int i = 0; i < m; i++) {
      cin >> K[i];
   }
   for (int i = 0; i < n; i++) {
      int func_a;
      cin >> func_a;
      for (int j = m - 1; j >= 0; j--) {
         int a, b, c;
         int low = func_a & 0b111;
         int medium = (func_a >> 3) & 0b111;
         int high = (func_a >> 6) & 0b111;

         b = high;
         c = medium ^ func(b, K[j]);
         a = low ^ func(c, K[j]);
         func_a = (a << 6) | (b << 3) | c;
      }
      cout << func_a << (i == n - 1 ? "" : " ");
   }
   return 0;
}