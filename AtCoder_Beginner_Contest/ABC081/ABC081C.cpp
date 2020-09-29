#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, k, buf, i = 0, sum = 0, ans = 0;
	cin >> num >> k;
	vector<int> d(num + 1, 0);
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		if (d[buf] == 0)
			sum++;
		d[buf]++;
	}
	if (sum <= k) {
		printf("0\n");
		return 0;
	}
	sort(d.begin(), d.end());
	for (i = num - sum + 1; k < sum; i++) {
		ans += d[i];
		k++;
	}
	cout << ans << "\n";
	return 0;
}