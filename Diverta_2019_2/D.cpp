#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i;
	vector<int> a(3), b(3), k(3, 0);
	vector<pair<double, int>> d(3);
	cin >> num;
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	d[0] = make_pair((double)a[0] / (double)b[0], 0);
	d[1] = make_pair((double)a[1] / (double)b[1], 1);
	d[2] = make_pair((double)a[2] / (double)b[2], 2);
	sort(d.begin(), d.end());
	//A
	if (d[0].first < 1) {
		k[d[0].second] = num / a[d[0].second];
		num %= a[d[0].second];
		if (d[1].first < 1) {
			k[d[1].second] = num / a[d[1].second];
			num %= a[d[1].second];
		}
		if (d[2].first < 1) {
			k[d[2].second] = num / a[d[2].second];
			num %= a[d[2].second];
		}
	}
	//B
	for (i = 0; i < 3; i++) {
		num += k[i] * b[i];
		k[i] = 0;
	}
	sort(d.begin(), d.end(), greater<pair<double, int>>());
	if (d[0].first > 1) {
		k[d[0].second] = num / a[d[0].second];
		num %= a[d[0].second];
		if (d[1].first > 1) {
			k[d[1].second] = num / a[d[1].second];
			num %= a[d[1].second];
		}
		if (d[2].first > 1) {
			k[d[2].second] = num / a[d[2].second];
			num %= a[d[2].second];
		}
	}
	for (i = 0; i < 3; i++)
		num += k[i] * a[i];
	printf("%d\n", num);
	return 0;
}