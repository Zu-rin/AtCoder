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

int main(void) {
	int num, i, k, q, a, b;
	vector<priority_queue<pp>> d(200001);
	priority_queue<pp, vector<pp>, greater<pp>> ans;
	cin >> num >> q;
	vector<int> kg(num + 1, 0), late(num + 1, 0);
	rep(i, num) {
		cin >> a >> b;
		kg[i + 1] = b;
		late[i + 1] = a;
		d[b].push(pp(a, i + 1));
	}
	rep(i, d.size()) {
		if(!d[i].empty())
			ans.push(pp(d[i].top().first, i));
	}
	rep(k, q) {
		cin >> a >> b;
		int m = kg[a];
		kg[a] = b;
		d[b].push(pp(late[a], a));
		while (!d[m].empty() && kg[d[m].top().second] != m)
			d[m].pop();
		if(!d[m].empty())
			ans.push(pp(d[m].top().first, m));
		ans.push(pp(d[b].top().first, b));
		while (d[ans.top().second].empty() || ans.top().first != d[ans.top().second].top().first)
			ans.pop();
		cout << ans.top().first << "\n";
	}
	return 0;
}