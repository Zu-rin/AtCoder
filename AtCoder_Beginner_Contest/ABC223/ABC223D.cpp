#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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

int main(void) {
	int num, m, i, a, b;
	cin >> num >> m;
	priority_queue<int, vector<int>, greater<int>> que;
	vector<set<int>> d(num + 1);
	vector<int> ans, ind(num + 1, 0);
	rep(i, m) {
		cin >> a >> b;
		if (!d[a].count(b)) {
			d[a].insert(b);
			ind[b]++;
		}
	}
	for(i = 1; i <= num; i++) {
		if (!ind[i])
			que.push(i);
	}
	while (que.size()) {
		ans.push_back(que.top());
		que.pop();
		for (int nx : d[*ans.rbegin()]) {
			if (--ind[nx] == 0)
				que.push(nx);
		}
	}
	if (ans.size() == num) {
		rep(i, ans.size() - 1)
			cout << ans[i] << " ";
		cout << ans[i] << "\n";
	}
	else
		printf("-1\n");
	return 0;
}