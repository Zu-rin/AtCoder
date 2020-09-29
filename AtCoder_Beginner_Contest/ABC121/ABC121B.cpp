#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, len, i = 0,  j = 0, sum, a, c, ans = 0;
	cin >> num >> len >> c;
	vector<int> b(len);
	for (; i < len; i++)
		scanf_s("%d", &b[i]);
	for (; j < num; j++) {
		sum = c;
		for (i = 0; i < len; i++) {
			scanf_s("%d", &a);
			sum += a * b[i];
		}
		if (sum > 0)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}