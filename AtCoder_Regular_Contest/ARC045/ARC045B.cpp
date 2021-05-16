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
	int num, m, i;
	list<int> ans;
	cin >> num >> m;
	vector<int> d(num + 2, 0), l(m), r(m);
	rep(i, m) {
		cin >> l[i] >> r[i];
		d[l[i]]++;
		d[r[i] + 1]--;
	}
	rep(i, num + 1) {
		d[i + 1] += d[i];
		if (d[i] > 1)
			d[i] = 0;
	}
	rep(i, num + 1) {
		d[i + 1] += d[i];
	}
	rep(i, m) {
		if (d[r[i]] - d[l[i] - 1] == 0)
			ans.push_back(i + 1);
	}
	cout << ans.size() << "\n";
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << *it << "\n";
	return 0;
}