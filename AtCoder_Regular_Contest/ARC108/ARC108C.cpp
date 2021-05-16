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
typedef struct {
	int to, c;
} edge;

int num, m;

void Search(int n, vector<vector<edge>>& e, vector<int> &ans, vector<int> &ok) {
	for (edge x : e[n]) {
		if (!ok[x.to]) {
			ok[x.to] = 1;
			if (ans[n] != x.c) {
				ans[x.to] = x.c;
			}
			else {
				ans[x.to] = (x.c == 1 ? 2 : 1);
			}
			Search(x.to, e, ans, ok);
		}
	}
	return;
}


int main(void) {
	int i, a, b, c;
	cin >> num >> m;
	vector<vector<edge>> e(num + 1);
	vector<int> ans(num + 1, 1), ok(num + 1, 0);
	rep(i, m) {
		cin >> a >> b >> c;
		e[a].push_back({ b, c });
		e[b].push_back({ a, c });
	}
	ok[1] = 1;
	Search(1, e, ans, ok);
	for (i = 1; i <= num; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}