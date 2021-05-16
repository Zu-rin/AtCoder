#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, l = 0, r = 1, i;
	long long k, ans = 0, sum = 0;
	cin >> num >> k;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sum = d[0];
	if (num == 1) {
		if (sum >= k)
			ans++;
	}
	while (r < num) {
		while (r < num && sum < k)
			sum += d[r++];
		while (l <= r && sum >= k) {
			ans += num - r + 1;
			sum -= d[l++];
		}
	}
	cout << ans << "\n";
	return 0;
}