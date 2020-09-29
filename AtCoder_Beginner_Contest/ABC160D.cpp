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

queue<int> que;
void Search(int n, vector<list<int>> & p, vector<int> &d) {
	for (auto it = p[n].begin(); it != p[n].end(); it++) {
		if (d[*it] < 0) {
			d[*it] = d[n] + 1;
			que.push(*it);
		}
	}
	if (que.empty())
		return;
	n = que.front();
	que.pop();
	Search(n, p, d);
	return;
}

int main(void) {
	int num, i, j, a, b, c, buf;
	cin >> num >> a >> b;
	vector<list<int>> p(num + 1);
	vector<vector<int>> d(2, vector<int>(num + 1, -1));
	vector<int> ans(num, 0);
	rep(i, num + 1) {
		if (i > 1)
			p[i].push_back(i - 1);
		if (i < num)
			p[i].push_back(i + 1);
	}
	p[a].push_back(b);
	p[b].push_back(a);
	d[0][a] = d[1][b] = 0;
	Search(a, p, d[0]);
	Search(b, p, d[1]);
	c = num - b;
	a--;
	b -= a;
	for (i = 1; i <= a; i++) {
		ans[i] += a - i;
		for (j = a + 1; j <= num; j++)
			ans[d[0][i] + d[0][j]]++;
	}
	for (j = 1; j <= (b - 1) / 2; j++)
		ans[j] += b;
	if (b % 2 == 0)
		ans[b / 2] += b / 2;
	for (; i <= a + b; i++) {
		for (j = a + b + 1; j <= num; j++)
			ans[d[1][i] + d[1][j]]++;
	}
	for (i = 1; i < c; i++)
		ans[i] += c - i;
	for (i = 1; i < num; i++)
		cout << ans[i] << "\n";
	return 0;
}