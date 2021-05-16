#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, a, b, i, t = 0;
	bool ok = true;
	cin >> num;
	vector<pair<int, int>> d(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		d[i] = make_pair(b, a);
	}
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++) {
		t += d[i].second;
		if (t > d[i].first) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}