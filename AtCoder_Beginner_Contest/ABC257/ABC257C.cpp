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
	int num, i;
	string s;
	cin >> num >> s;
	vector<pp> d(num);
	vector<int> a(num + 2, 0), b(num + 2, 0);
	rep(i, num) {
		cin >> d[i].first;
		d[i].second = s[i] - '0';
	}
	d.push_back(pp(1e9 + 1, 2));
	d.push_back(pp(0, 2));
	sort(d.begin(), d.end());
	rep(i, a.size() - 1) {
		a[i + 1] = a[i] + (d[i + 1].second == 0);
	}
	for (i = b.size() - 1; i > 0; i--) {
		b[i - 1] = b[i] + (d[i - 1].second == 1);
	}
	int ans = max(num - *a.rbegin(), *a.rbegin());
	rep(i, d.size() - 1) {
		if (d[i].first != d[i + 1].first) {
			chmax(ans, a[i] + b[i + 1]);
		}
	}
	cout << ans << "\n";
	return 0;
}