#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0, buf, val, ans = 1;
	cin >> num;
	val = num / 2 + num % 2;
	vector<int> d(val, 0);
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		d[buf / 2]++;
	}
	i = 1;
	while (i < val && d[i] == 2) { i++; }
	if (i != val) {
		printf("0\n");
		return 0;
	}
	for (i = 0; i < num / 2; i++) {
		ans <<= 1;
		ans %= 1000000007;
	}
	cout << ans << "\n";
	return 0;
}