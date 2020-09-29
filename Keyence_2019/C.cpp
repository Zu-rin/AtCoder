#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int num, b, i, ans = 0;
	long long sum = 0;
	cin >> num;
	vector<int> c(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &c[i]);
	for (i = 0; i < num; i++){
		scanf_s("%d", &b);
		c[i] -= b;
	}
	sort(c.begin(), c.end());
	i = 0;
	while (i < num && c[i] < 0) {
		sum += c[i++];
		ans++;
	}
	for (i = num - 1; c[i] > 0; i--) {
		if (sum >= 0)
			break;
		sum += c[i];
		ans++;
	}
	if (sum < 0)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}