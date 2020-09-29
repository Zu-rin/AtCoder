#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

queue<int> r[2];

void DFS(int n, vector<list<int>> & e, vector<int> & d) {
	r[d[n]].push(n);
	for (auto itr = e[n].begin(); itr != e[n].end(); itr++) {
		if (d[*itr] < 0) {
			d[*itr] = (d[n] + 1) & 1;
			DFS(*itr, e, d);
		}
	}
	return;
}

void Zfill(int n, vector<int>& ans) {
	int d[3] = { 3, 1, 2 }, k = 0;
	while (!r[n].empty()) {
		ans[r[n].front()] = d[0];
		d[0] += 3;
		r[n].pop();
	}
	for (int i = 1; i < ans.size(); i++) {
		if (ans[i] < 0) {
			ans[i] = d[k];
			d[k] += 3;
			if (d[k] > ans.size())
				k++;
		}
	}
	return;
}

void Fill(vector<int>& ans) {
	int i = 1, z = 3;
	while (!r[0].empty()) {
		if (i > ans.size()) {
			ans[r[0].front()] = z;
			z += 3;
		}
		else {
			ans[r[0].front()] = i;
			i += 3;
		}
		r[0].pop();
	}
	i = 2;
	while (!r[1].empty()) {
		if (i > ans.size()) {
			ans[r[1].front()] = z;
			z += 3;
		}
		else {
			ans[r[1].front()] = i;
			i += 3;
		}
		r[1].pop();
	}
	for (i = 1; i < ans.size(); i++) {
		if (ans[i] < 0) {
			ans[i] = z;
			z += 3;
		}
	}
	return;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<list<int>> e(num + 1);
	vector<int> d(num + 1, -1), ans(num + 1, -1);
	rep(i, num - 1) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	d[1] = 0;
	DFS(1, e, d);
	if (r[0].size() <= num / 3) {
		Zfill(0, ans);
	}
	else if (r[1].size() <= num / 3) {
		Zfill(1, ans);
	}
	else {
		Fill(ans);
	}
	for (i = 1; i <= num; i++)
		cout << ans[i] << " ";
	printf("\n");
	return 0;
}