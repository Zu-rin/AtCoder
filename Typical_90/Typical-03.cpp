#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int argmax(vector<int> &d) {
	int i, ans = 0;
	rep(i, d.size()) {
		if (d[ans] < d[i])
			ans = i;
	}
	return ans;
}

void BFS(int s, vector<vector<int>>& d, vector<int>& ans) {
	queue<int> que;
	ans[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int n = que.front();
		que.pop();
		for (int nx : d[n]) {
			if (ans[nx] < 0) {
				que.push(nx);
				ans[nx] = ans[n] + 1;
			}
		}
	}
	return;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<vector<int>> d(num + 1);
	vector<int> x(num + 1, -1), y(num + 1, -1);
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	BFS(1, d, x);
	BFS(argmax(x), d, y);
	cout << y[argmax(y)] + 1<< "\n";
	return 0;
}