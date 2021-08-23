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

void DFS(vector<vector<int>> &d, vector<int> &ok, int n = 1) {
	ok[n] = 0;
	for (int nx : d[n]) {
		if (ok[nx]) {
			cout << " " << nx;
			DFS(d, ok, nx);
			cout << " " << n;
		}
	}
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<int> ok(num + 1, 1);
	vector<vector<int>> d(num + 1);
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	rep(i, num + 1)
		sort(d[i].begin(), d[i].end());
	cout << 1;
	DFS(d, ok);
	cout << "\n";
	return 0;
}