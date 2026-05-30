#include<iostream>
#include<iomanip>
#define int long long
using namespace std;

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n;
   double a;
   if (!(cin >> n >> a)) return 0;
   int m = 0;
   for (int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      if (x * x + y * y - a * a <= 1e-12) {
         m++;
      }
   }
   const double pi = 4.0 * static_cast<double>(m) / static_cast<double>(n);
   cout << fixed << setprecision(6) << pi;
   return 0;
}