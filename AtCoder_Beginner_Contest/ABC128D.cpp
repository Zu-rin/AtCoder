#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define T true
#define F false

using namespace std;

int main(void) {
	int i, l, r, num, k, lim, sum, ans = 0;
	cin >> num >> k;
	vector<int> d(num);
	lim = min(num, k);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	for (l = 0; l <= lim; l++) {
		for (r = 0; l + r <= lim; r++) {
			sum = 0;
			priority_queue<int, vector<int>, greater<int>> s;
			for (i = 0; i < l; i++) {
				s.push(d[i]);
				sum += d[i];
			}
			for (i = num - 1; i >= num - r; i--) {
				s.push(d[i]);
				sum += d[i];
			}
			for (i = 0; i < k - r - l; i++) {
				if (!s.empty() && s.top() < 0) {
					sum -= s.top();
					s.pop();
				}
				else
					break;
			}
			ans = max(ans, sum);
		}
	}
	printf("%d\n", ans);
	return 0;
}