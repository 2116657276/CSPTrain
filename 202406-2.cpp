/*
题意：在二维平面上，有 n 个基站。第 i 个基站控制一个矩形区域。该矩形的左下角坐标是 (x1_i, y1_i)，右上角坐标是 (x2_i, y2_i)。当一个点的 x 坐标在 [x1_i, x2_i] 且 y 坐标在 [y1_i, y2_i] 范围内时，该点就会获得 1 层的信号覆盖。由于基站可能重叠，某些区域会有多层信号覆盖。
目标：求出平面上，信号覆盖层数严格大于等于k的区域的总面积。
输入：第一行 n, k。接下来 n 行，每行四个整数：x1_i, y1_i, x2_i, y2_i。
输出：一个整数，表示满足条件的区域总面积。
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

typedef struct Event {
	int x, y1, y2, type;

	bool operator <(const Event &other) const {
		return x < other.x;
	}
} Event;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	if (!(cin >> n >> k)) return 0;

	vector<Event> events;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		events.push_back({x1, y1, y2, true});
		events.push_back({x2, y1, y2, false});
	}
	sort(events.begin(), events.end());

	map<int,int> y_diff;
	int area = 0;
	int last_x = events[0].x;

	for (int i = 0; i < events.size();) {
		int curr_x = events[i].x;

		if (curr_x > last_x) {
			int dx = curr_x - last_x;
			int y_hei = 0;
			int layer = 0;
			int last_y = 0;
			bool tag = true;

			for (pair<const int,int> &y: y_diff) {
				int curr_y = y.first;
				int diff_val = y.second;
				if (!tag && layer >= k) {
					y_hei += curr_y - last_y;
				}

				layer += diff_val;
				last_y = curr_y;
				tag = false;
			}
			area += dx * y_hei;
		}
		while (i < events.size() && events[i].x == curr_x) {
			y_diff[events[i].y1] += events[i].type;
			y_diff[events[i].y2] -= events[i].type;
			i++;
		}
		last_x = curr_x;
	}
	cout << area;
	return 0;
}