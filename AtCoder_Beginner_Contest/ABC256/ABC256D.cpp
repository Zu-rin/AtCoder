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
	int num, i, l, r;
	cin >> num;
	vector<pp> d(num), ans;
	rep(i, num)
		cin >> d[i].first >> d[i].second;
	sort(d.begin(), d.end());
	ans.push_back(d[0]);
	for (i = 1; i < num; i++) {
		pp& a = *ans.rbegin();
		if (d[i].first <= a.second)
			chmax(a.second, d[i].second);
		else
			ans.push_back(d[i]);
	}
	rep(i, ans.size()) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}