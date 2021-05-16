#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main(void) {
	int i, j, a, b, c, d, e, f, aa, ab = 0, x = 0;
	cin >> a >> b >> c >> d >> e >> f;
	priority_queue<int, vector<int>, greater<int>> w, s;
	for (i = 0; i * 100 < f; i += a) {
		for (j = 0; (i + j) * 100 < f; j += b) {
			w.push(i + j);
		}
	}
	for (i = 0; i <= f; i += c) {
		for (j = 0; i + j <= f; j += d) {
			s.push(i + j);
		}
	}
	b = 0;
	aa = a * 100;
	w.pop();
	while (!w.empty()) {
		a = w.top();
		w.pop();
		while (b <= a * e && a * 100 + b <= f) {
			if (b * 100000 / (a + b) > x) {
				x = b * 100000 / (a + b);
				aa = a * 100 + b;
				ab = b;
			}
			b = s.top();
			s.pop();
		}
	}
	printf("%d %d\n", aa, ab);
	return 0;
}