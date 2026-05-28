#include<iostream>
#include<vector>
#define int long long
using namespace std;
static vector<int> A;

bool func(const vector<int> &s, const vector<int> &t) {
	int s_f = 0;
	int t_f = 0;
	for (const auto &i: s) {
		s_f = s_f ^ A[i];
	}
	for (const auto &i: t) {
		t_f = t_f ^ A[i];
	}
	return s_f == t_f;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	if (!(cin >> n >> m)) return 0;
	A.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	vector<vector<int> > S(m);
	vector<vector<int> > T(m);
	for (int i = 0; i < m; i++) {
		int s_size;
		cin >> s_size;
		vector<int> s;
		for (int j = 0; j < s_size; j++) {
			int s_i;
			cin >> s_i;
			s.push_back(s_i);
		}
		S[i] = s;
	}
	for (int i = 0; i < m; i++) {
		int t_size;
		cin >> t_size;
		vector<int> t;
		for (int j = 0; j < t_size; j++) {
			int t_i;
			cin >> t_i;
			t.push_back(t_i);
		}
		T[i] = t;
	}
	for (int i = 0; i < m; i++) {
		const bool ans = S[i] == T[i];
		const bool f = func(S[i], T[i]);
		if (ans == false && f == true) {
			cout << "wrong" << "\n";
		} else {
			cout << "correct" << "\n";
		}
	}

	return 0;
}