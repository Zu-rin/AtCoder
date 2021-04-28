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

vector<int> ans;

void Search(int n, int p, vector<int> &c, vector<vector<int>> &d, vector<int> &e) {
	if (!e[c[n]])
		ans.push_back(n);
	e[c[n]]++;
	for (int& nx : d[n]) {
		if (nx == p)
			continue;
		Search(nx, n, c, d, e);
	}
	e[c[n]]--;
	return;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<int> c(num + 1), e(100001, 0);
	vector<vector<int>> d(num + 1);
	for (i = 1; i <= num; i++)
		cin >> c[i];
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	Search(1, 1, c, d, e);
	sort(ans.begin(), ans.end());
	for (int& a : ans)
		cout << a << "\n";
	return 0;
}