#include<iostream>
#define int long long
using namespace std;

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   return 0;
}

bool check (int ans);
int binary_function (int L,int R) {
   int ans = R;
   while (L <= R) {
      int limit = L + (R - L) / 2;

      if (check(limit)) {
         ans = limit;
         R = limit - 1;
      } else {
         L = limit + 1;
      }
   }
   return ans;
}
