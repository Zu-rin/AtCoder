#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, t, i, a, b;
	cin >> num >> t;
	vector<pair<int, int>> d(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		d[i] = make_pair(a, b);
	}
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++) {
		if (d[i].second <= t) {
			printf("%d\n", d[i].first);
			break;
		}
	}
	if (i == num)
		printf("TLE\n");
	return 0;
}