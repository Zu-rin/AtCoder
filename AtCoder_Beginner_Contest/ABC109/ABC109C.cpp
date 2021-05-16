#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	if (a < b) {
		int buf = a;
		a = b;
		b = buf;
	}
	return gcd(b, a % b);
}

int main(void) {
	int num, st, i = 0, ans;
	cin >> num >> st;
	vector<int> d(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		d[i] = abs(d[i] - st);
	}
	for (ans = d[0], i = 1; i < num; i++)
		ans = gcd(ans, d[i]);
	cout << ans << "\n";
	return 0;
}