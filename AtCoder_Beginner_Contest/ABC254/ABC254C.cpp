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

int main(void) {
	int num, k, i, ok = 1, x;
	cin >> num >> k;
	vector<int> a;
	vector<vector<int>> d(k);

	rep(i, num) {
		cin >> x;
		d[i % k].push_back(x);
	}
	rep(i, k)
		sort(d[i].begin(), d[i].end());
	rep(i, num)
		a.push_back(d[i % k][i / k]);
	rep(i, num - 1) {
		if (a[i] > a[i + 1]) {
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