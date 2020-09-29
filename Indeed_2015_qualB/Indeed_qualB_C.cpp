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

void Search(vector<list<int>> & d, vector<int> & ans) {
	int n;
	vector<int> a(d.size(), 1);
	priority_queue<int, vector<int>, greater<int>> que;
	que.push(1);
	while (!que.empty()) {
		n = que.top();
		que.pop();
		a[n] = 0;
		ans.push_back(n);
		for (auto it = d[n].begin(); it != d[n].end(); it++) {
			if(a[*it])
				que.push(*it);
		}
	}
	return;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<list<int>> d(num + 1);
	vector<int> ans;
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	Search(d, ans);
	rep(i, ans.size() - 1)
		cout << ans[i] << " ";
	cout << ans[i] << "\n";
	return 0;
}