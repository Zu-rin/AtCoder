#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int num, i = 0, p;
	long long ans = 0, a[5] = { 0 };
	cin >> num;
	string s, march = "MARCH";
	for (; i < num; i++) {
		cin >> s;
		p = march.find(s[0]);
		a[p]++;
	}
	ans += a[0] * a[1] * (a[2] + a[3] + a[4]);
	ans += a[2] * a[3] * (a[0] + a[1] + a[4]);
	ans += (a[0] + a[1]) * (a[2] + a[3]) * a[4];
	cout << ans << "\n";
	return 0;
}