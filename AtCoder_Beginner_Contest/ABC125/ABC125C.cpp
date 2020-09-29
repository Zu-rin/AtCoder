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
	int num, i, ans;
	cin >> num;
	vector<int> d(num), l(num), r(num);
	cin >> d[0];
	l[0] = d[0];
	for (i = 1; i < num; i++) {
		scanf_s("%d", &d[i]);
		l[i] = gcd(l[i - 1], d[i]);
	}
	r[num - 1] = d[num - 1];
	for (i = num - 2; i > 0; i--)
		r[i] = gcd(r[i + 1], d[i]);
	ans = max(r[1], l[num - 2]);
	for (i = 1; i < num - 1; i++)
		ans = max(ans, gcd(l[i - 1], r[i + 1]));
	cout << ans << "\n";
	return 0;
}