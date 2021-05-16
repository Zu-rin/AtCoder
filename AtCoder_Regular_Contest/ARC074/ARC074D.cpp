#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, p;
	ll l = 0, r = 0, ans;
	cin >> num;
	vector<int> a(num << 1);
	vector<pair<int, int>> d(num << 1);
	priority_queue<int> que;
	for (i = 0; i < (num << 1); i++) {
		scanf_s("%d", &a[i]);
		d[i] = make_pair(a[i], i);
	}
	sort(d.begin(), d.end(), greater<pair<int, int>>());
	for (i = 0; i < num; i++) {
		l += d[i].first;
		scanf_s("%d", &p);
		que.push(p);
		r += p;
	}
	p = num - 1;
	ans = l - r;
	for (i = (num << 1) - 1; i >= num; i--) {
		que.push(a[i]);
		r -= que.top();
		r += a[i];
		que.pop();
		if (d[p].first <= a[i]) {
			l -= a[i];
			p++;
			while (d[p].second >= i)
				p++;
			l += d[p].first;
		}
		ans = max(ans, l - r);
	}
	cout << ans << "\n";
	return 0;
}