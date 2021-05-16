#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, c, k, i, ans = 1, n = 0, t = 0;
	cin >> num >> c >> k;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++) {
		if (n == 0) {
			t = d[i];
			n = 1;
		}
		else if (d[i] > t + k || n == c) {
			ans++;
			n = 0;
			i--;
		}
		else
			n++;
	}
	printf("%d\n", ans);
	return 0;
}