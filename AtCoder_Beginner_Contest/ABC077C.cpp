#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, j = 0;
	long long ans = 0, sum = 0;
	cin >> num;
	vector<int> a(num), b(num), c(num), d(num, 0);
	for (i = 0; i < num; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < num; i++)
		scanf_s("%d", &b[i]);
	for (i = 0; i < num; i++)
		scanf_s("%d", &c[i]);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (i = 0; i < num; i++) {
		while (j < num && a[j] < b[i])
			j++;
		d[i] = j;
	}
	j = 0;
	for (i = 0; i < num; i++) {
		while (j < num && b[j] < c[i]) {
			sum += d[j];
			j++;
		}
		ans += sum;
	}
	cout << ans << "\n";
	return 0;
}