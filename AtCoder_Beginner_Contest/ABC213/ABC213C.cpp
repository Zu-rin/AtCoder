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
	int h, w, num, i;
	cin >> h >> w >> num;
	vector<pp> x(num), y(num), ans(num);
	rep(i, num) {
		cin >> x[i].first >> y[i].first;
		x[i].second = y[i].second = i;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int a = 1, b = 1;
	rep(i, num - 1) {
		ans[x[i].second].first = a;
		ans[y[i].second].second = b;
		if (x[i].first != x[i + 1].first)
			a++;
		if (y[i].first != y[i + 1].first)
			b++;
	}
	ans[x[i].second].first = a;
	ans[y[i].second].second = b;
	rep(i, num) {
		cout << ans[i].first << " ";
		cout << ans[i].second << "\n";
	}
	return 0;
}