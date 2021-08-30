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

struct QueList {
	vector<queue<int>> que;
	vector<int> d;

	QueList(int n, int m) {
		int i, j, k, x;
		d.resize(n + 1, -1);
		que.resize(m + 1);
		rep(i, m) {
			cin >> k;
			rep(j, k) {
				cin >> x;
				que[i].push(x);
			}
		}
	}

	void pop(int p) {
		if (que[p].empty())
			return;
		int x = que[p].front();
		if (d[x] >= 0) {
			que[p].pop();
			que[d[x]].pop();
			pop(d[x]);
			pop(p);
		}
		else
			d[x] = p;
	}

	void popAll() {
		int i;
		rep(i, que.size()) {
			pop(i);
		}
	}
};

int main(void) {
	int num, m, i, j, k, x, ok = 1;
	cin >> num >> m;
	QueList ql(num, m);
	ql.popAll();
	rep(i, m) {
		if (ql.que[i].size()) {
			ok = 0;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}