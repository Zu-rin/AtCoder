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

void BFS(vector<vector<int>> &d, vector<int> &ans) {
	queue<int> que;
	ans[1] = 0;
	que.push(1);
	while (!que.empty()) {
		int n = que.front();
		que.pop();
		for (int nx : d[n]) {
			if (ans[nx] == -1) {
				ans[nx] = ans[n] + 1;
				que.push(nx);
			}
		}
	}
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<vector<int>> d(num + 1), dep(num);
	vector<int> ans(num + 1, -1), x;
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	BFS(d, ans);
	for (i = 1; i <= num; i++)
		dep[ans[i]].push_back(i);
	int odd = 0;
	for (i = 1; i < num; i += 2)
		odd += dep[i].size();
	i = (odd >= num / 2);
	for (; i < num and x.size() < num / 2; i += 2) {
		for (int n : dep[i]) {
			if (x.size() == num / 2)
				break;
			x.push_back(n);
		}
	}
	rep(i, x.size() - 1)
		cout << x[i] << " ";
	cout << x[i] << "\n";
	return 0;
}