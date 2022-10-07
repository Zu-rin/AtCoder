#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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

void BFS(vector<vector<int>> &d, vector<int> &ans, int s, int g) {
	queue<int> que;
	que.push(s);
	ans[s] = 0;
	while (!que.empty()) {
		int n = que.front();
		que.pop();
		for (int nx : d[n]) {
			if (ans[nx] == INF) {
				ans[nx] = ans[n] + 1;
				que.push(nx);
			}
		}
	}
}

int main(void) {
	int num, x, y, i, a, b;
	cin >> num >> x >> y;
	vector<int> k(num + 1, INF);
	vector<vector<int>> d(num + 1);
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	BFS(d, k, y, x);
	while (x != y) {
		cout << x << " ";
		for (int n : d[x]) {
			if (k[n] + 1 == k[x]) {
				x = n;
				break;
			}
		}
	}
	cout << y << "\n";
	return 0;
}