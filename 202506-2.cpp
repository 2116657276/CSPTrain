#include<iostream>
#include<queue>
#include<vector>
#define int long long
using namespace std;

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n, k;
   if (!(cin >> n >> k)) return 0;

   int x, y;
   cin >> x >> y;

   vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
   visited[x][y] = true;
   queue<pair<int,int>> q;
   q.emplace(x, y);

   if (k > 0) {
      int jumped = 0;
      while (!q.empty()) {
         for (int i = 0; i < 8; i++) {
            const pair<int,int> jump[8] = {
               {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}
            };
            int new_x = q.front().first + jump[i].first;
            int new_y = q.front().second + jump[i].second;
            if (new_x > n || new_y > n || new_x < 1 || new_y < 1) continue;

            if (visited[new_x][new_y] == false) {
               visited[new_x][new_y] = true;
               q.emplace(new_x, new_y);
            }
         }
         q.pop();
         if (jumped >= k) break;
      }
   }

   int sum = 0;
   for (const auto& i : visited) {
      for (const auto& j : i) {
         if (j == true) sum++;
      }
   }
   cout << sum;

   return 0;
}
