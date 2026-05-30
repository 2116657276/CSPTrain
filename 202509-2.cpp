#include<iostream>
#include<vector>
#include<set>
#define int long long
using namespace std;

const int mask[5][9] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1},
   {1, 0, 0, 1, 0, 0, 1, 0, 1},
   {1, 0, 0, 1, 1, 1, 1, 1, 0},
   {1, 0, 0, 0, 0, 1, 1, 0, 0},
   {1, 1, 1, 1, 1, 1, 1, 0, 0}
};

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n, L;
   if (!(cin >> n >> L)) return 0;

   vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));
   for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
         cin >> A[i][j];
      }
   }

   set<int> valid_k;
   for (int i = 1; i <= n - 4; i++) {
      for (int j = 1; j <= n - 8; j++) {
         int white_min = L;
         int black_max = -1;

         for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 9; col++) {
               int pixel = A[i + row][j + col];
               if (mask[row][col] == 1) {
                  white_min = min(white_min, pixel);
               } else {
                  black_max = max(black_max, pixel);
               }
            }
         }

         int k_low = black_max + 1;
         int k_high = white_min;
         if (k_low <= k_high) {
            int begin = max(0ll, k_low);
            int end = min(L - 1, k_high);
            for (int k = begin; k <= end; k++) {
               valid_k.insert(k);
            }
         }
      }
   }
   for (const auto& k : valid_k) {
      cout << k << "\n";
   }
   return 0;
}